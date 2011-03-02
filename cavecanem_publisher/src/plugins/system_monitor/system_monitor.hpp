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

#ifndef SYSTEM_MONITOR_HPP
#define SYSTEM_MONITOR_HPP

#include <glibtop.h>
#include <glibtop/cpu.h>
#include <glibtop/mem.h>
#include <glibtop/proclist.h>
#include <glibtop/loadavg.h>
#include <glibtop/swap.h>
#include <syslog.h>
#include <sys/utsname.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <list>

#include <boost/extension/extension.hpp>
#include <boost/extension/factory.hpp>
#include <boost/extension/type_map.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>


#include <plugins/plugin.hpp>

#include <ndds/ndds_cpp.h>
#include "system_monitor_dds.h"
#include "system_monitor_ddsSupport.h"

enum sensor_type {
  SENSOR_TYPE_NONE,
  SENSOR_TYPE_OMNIBOOK,
  SENSOR_TYPE_LINUX_MACMINI,
  SENSOR_TYPE_LINUX_I2C,
  SENSOR_TYPE_LINUX_ACPI,
  SENSOR_TYPE_LINUX_PCI,
  SENSOR_TYPE_LINUX_PBOOK,
  SENSOR_TYPE_LINUX_INTELCORETEMP,
  SENSOR_TYPE_LINUX_VIRTUAL
};

static mode_t default_mode = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;

class file_management {
public:
  std::string get_realpath(std::string file);
  bool has_extension(std::string file, std::string extension);
  bool is_dir(std::string file);
  std::list <std::string> ls_r_by_extension(std::string file, std::string extension);
  bool mkidr(std::string dir);
  bool rmmdir(std::string);
  std::string dir_get(std::string file);
  std::string file_get(std::string str);
  std::list <std::string> ls_extension(std::string dir, std::string extension);
  std::list <std::string> ls(std::string dir);
  bool exists(std::string file);
};


class system_monitor : public plugin {
public:
  system_monitor(std::string plugin_id);
  virtual void publish_information(void);
  virtual void clean_dds_stuff(void);
private:
  void temperature_init(void);
  double get_temperature(void);
  std::list <std::string> temperature_get_bus_files(std::string bus);
  
  glibtop_cpu cpu_;
  glibtop_mem memory_;
  glibtop_loadavg loadavg_;
  glibtop_proclist proclist_;
  glibtop_swap swap_;
  
  host_info hi_;    
  int sensor_type_;
  char *sensor_name_;
  char *sensor_path_;
  double sensor_alarm_value_;
  file_management fm_;

  //DDS Stuff
  DDSDomainParticipant *participant_;
  DDSPublisher *publisher_;
  DDSTopic *topic_;
  DDSDataWriter *writer_;
  sysmon_statusDataWriter * sysmon_status_writer_;
  sysmon_status *instance_;
  DDS_ReturnCode_t retcode_;
  DDS_InstanceHandle_t instance_handle_;
  const char *type_name_;
  DDS_Duration_t send_period_;
  int domain_id_;
  std::string topic_name_;
  std::string qos_library_;
  std::string qos_profile_;
  std::string plugin_id_;
};



BOOST_EXTENSION_TYPE_MAP_FUNCTION {
  using namespace boost::extensions;
  std::map<std::string, factory<plugin, std::string> > &plugin_factories(types.get());
  plugin_factories["system_monitor"].set<system_monitor>();
}

#endif //SYSTEM_MONITOR_HPP
