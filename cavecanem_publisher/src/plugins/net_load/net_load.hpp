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

#ifndef NET_LOAD_HPP
#define NET_LOAD_HPP

#include <boost/extension/extension.hpp>
#include <boost/extension/factory.hpp>
#include <boost/extension/type_map.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <sys/utsname.h>
#include <syslog.h>

#include <plugins/plugin.hpp>

#include <glibtop.h>
#include <glibtop/netlist.h>
#include <glibtop/netload.h>
#include <iostream>
#include <arpa/inet.h>

#include <ndds/ndds_cpp.h>
#include "net_load_dds.h"
#include "net_load_ddsSupport.h"


class net_load : public plugin {
public:
  net_load(std::string plugin_id);
  virtual void publish_information(void);
  virtual void clean_dds_stuff(void);
  
private:
  host_info hi_;
  glibtop_netlist buf_;
  glibtop_netload netload_;
  char** devices_;
  struct in_addr addr_, subnet_;
  //DDS Stuff
  DDSDomainParticipant *participant_;
  DDSPublisher *publisher_;
  DDSTopic *topic_;
  DDSDataWriter *writer_;
  netloadDataWriter * netload_writer_;
  std::map<char*, netload*> instance_map_;
  std::map<char*,DDS_InstanceHandle_t> instance_handle_map_;
  DDS_ReturnCode_t retcode_;
  const char *type_name_;
  DDS_Duration_t send_period_;
  int domain_id_;
  std::string topic_name_;
  std::string qos_profile_;
  std::string qos_library_;
  std::string plugin_id_;
};

BOOST_EXTENSION_TYPE_MAP_FUNCTION
{
  using namespace boost::extensions;
  std::map<std::string, factory<plugin, std::string> > &plugin_factories(types.get());
  plugin_factories["net_load"].set<net_load>();
}


#endif //NET_LOAD_HPP

