/*   
 *   Cave Canem Publisher is part of Cave Canem, an extensible DDS-based 
 *   monitoring and intrusion detection system.
 *
 *   Copyright (C) 2011 Fernando García Aranda
 *                                                                         
 *   This program is free software: you can redistribute it and/or modify  
 *   it under the terms of the GNU Lesser General Public License as published by  
 *   the Free Software Foundation, either version 3 of the License, or     
 *   (at your option) any later version.                                   
 *                                                                         
 *   This program is distributed in the hope that it will be useful,       
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         
 *   GNU Lesser General Public License for more details.                          
 *                                                                         
 *   You should have received a copy of the GNU Lesser General Public License     
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */                                                                         

#include <map>
#include <list>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <signal.h>

#include <boost/extension/factory.hpp>
#include <boost/extension/shared_library.hpp>
#include <boost/extension/type_map.hpp>
#include <boost/extension/convenience.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <plugins/plugin.hpp>

#include <ndds/ndds_cpp.h>

#ifndef LIBDIR
#  define LIBDIR ""
#endif

#ifndef SYSCONFDIR
#  define SYSCONFDIR ""
#endif

#define DAEMON_NAME "cavecanem-publisher"

using namespace boost::extensions;
using boost::property_tree::ptree;
using namespace std;

struct plugin_description {
  string plugin_type;
  string lib_name;
};


void exit_program(int sig);
map<string,boost::shared_ptr<plugin> > map_plugins;

int main()
{
  bool daemonize = true;
  
  setlogmask(LOG_UPTO(LOG_INFO));
  openlog(DAEMON_NAME, LOG_CONS, LOG_USER);
  
  if(daemonize) {    
    syslog(LOG_INFO, "Starting process");    
    /* Our process ID and Session ID */
    pid_t pid, sid;    
    
    /* Fork off the parent process */
    pid = fork();
    if (pid < 0) {
      exit(EXIT_FAILURE);
    }
    
    /* If we got a good PID, then
       we can exit the parent process. */
    if (pid > 0) {
      exit(EXIT_SUCCESS);
    }
    /* Change the file mode mask */
    umask(0);
    
    /* Create a new SID for the child process */
    sid = setsid();
    if (sid < 0) {
      /* Log the failure */
      exit(EXIT_FAILURE);
    }
    
    /* Change the current working directory */
    if ((chdir("/")) < 0) {
      /* Log the failure */
      exit(EXIT_FAILURE);
    }
    
    /* Close out the standard file descriptors */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);      
  }
  
  //Getting configuration and libraries base directory
  string sysconf_dir(SYSCONFDIR);
  string lib_dir(LIBDIR);

  string conf_file(sysconf_dir + "cavecanem_publisher.xml");
  string qos_library;
  string qos_file;
  //Default publishing period = 1 minute
  DDS_Duration_t publishing_period = {60,0};
  
  //Plugins to load map
  map<string,struct plugin_description> lib_map;
  map<string,struct plugin_description>::iterator lib_map_it;
  
  try {
    ptree pt;
    read_xml(conf_file,pt);
    
    //Reading general information
    publishing_period = {pt.get<int>("general.publishing_period")};
    qos_file = pt.get<string>("general.qos_file");
    //    qos_library = pt.get<string>("general.qos_default_library");
    
    //Dealing with plugin definitions
    ptree plugins = pt.get_child("plugins");
    for(ptree::const_iterator it = plugins.begin(); it != plugins.end(); ++it) {
      cout << it->first << endl;
      ptree const& plugin = it->second;
      
      //New plugin to load: lib_map[plugin_id] = plugin_lib_name
      plugin_description aux;
      aux.plugin_type = plugin.get_child("plugin_type").data();
      aux.lib_name = lib_dir + plugin.get_child("lib_name").data();
      lib_map[it->first]= aux;
    }
  }
  catch(std::exception &e) {
    syslog(LOG_ERR, "%s",e.what());
    exit(EXIT_FAILURE);
  }
  
  signal(SIGHUP, exit_program);
  signal(SIGTERM, exit_program);
  signal(SIGINT, exit_program);
  signal(SIGQUIT, exit_program);
  
  type_map types;
  lib_map_it = lib_map.begin();

  while(lib_map_it != lib_map.end()) {   
    if(!load_single_library(types,lib_map_it->second.lib_name)) {
      syslog(LOG_ERR,"Error loading plugin");
      lib_map.erase(lib_map_it++);
    }
    else 
      ++lib_map_it;
  }

  // Retrieve a map of all plugin factories taking an int and indexed
  // by a string from the type_map.
  map<string, factory<plugin, string> >& factories(types.get());
  if (factories.empty()) {
    syslog(LOG_ERR, "No plugins found!");
    exit_program(SIGQUIT);
  }

  DDS_DomainParticipantFactoryQos factory_qos;
  DDS_ReturnCode_t retcode;
  DDSTheParticipantFactory->get_qos(factory_qos);
  factory_qos.profile.url_profile.ensure_length(1,1);
  factory_qos.profile.url_profile[0] = DDS_String_dup((sysconf_dir + "qos/" + qos_file).c_str());

  DDSTheParticipantFactory->set_qos(factory_qos);
  // retcode = DDSTheParticipantFactory->set_default_library(qos_library.c_str());
  // if(retcode != DDS_RETCODE_OK) {
  //   syslog(LOG_ERR,"Set default QoS library error %d",retcode);
  //   exit_program(SIGQUIT);
  // }
  
  for(lib_map_it = lib_map.begin(); lib_map_it != lib_map.end(); ++lib_map_it) {
    
    try {
      map_plugins[lib_map_it->first].reset(factories[lib_map_it->second.plugin_type].create(lib_map_it->first));
    }
    catch(exception &e) {
      syslog(LOG_ERR, "Unloading %s plugin. Reason: %s",(lib_map_it->first).c_str(),e.what());
      map_plugins.erase(lib_map_it->first);
      lib_map.erase(lib_map_it);
    }
  }

  if(map_plugins.empty())
    exit(EXIT_FAILURE);

  while(true) {
    for(map<string,boost::shared_ptr<plugin> >::iterator it = map_plugins.begin(); it != map_plugins.end() ;++it) 
      map_plugins[it->first]->publish_information();
    
    NDDSUtility::sleep(publishing_period);
  }
  
  exit_program(SIGQUIT);
  
}


void exit_program(int sig)
{
  syslog(LOG_WARNING, "Received signal %s", strsignal(sig));
  syslog(LOG_INFO, "%s daemon exiting", DAEMON_NAME);
  
  for(map<string,boost::shared_ptr<plugin> >::iterator it = map_plugins.begin(); it != map_plugins.end() ;++it) 
    map_plugins[it->first]->clean_dds_stuff();
  
  
  exit(EXIT_SUCCESS);
}