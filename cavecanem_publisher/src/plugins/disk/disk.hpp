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

#ifndef DISK_HPP
#define DISK_HPP

#include <syslog.h>
#include <map>
#include <string>
#include <cstring>
#include <glibtop.h>
#include <glibtop/mountlist.h>
#include <glibtop/fsusage.h>
#include <sys/utsname.h>

#include <boost/extension/extension.hpp>
#include <boost/extension/factory.hpp>
#include <boost/extension/type_map.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>


#include <plugins/plugin.hpp>

#include <ndds/ndds_cpp.h>
#include "disk_dds.h"
#include "disk_ddsSupport.h"


class disk : public plugin {
public:
  disk(std::string plugin_id);
  virtual void publish_information(void);
  virtual void clean_dds_stuff(void);
private:
  host_info hi_;
  int domain_id_;
  //DDS Stuff
  DDSDomainParticipant *participant_;
  DDSPublisher *publisher_;
  DDSTopic *topic_;
  DDSDataWriter *writer_;
  filesystemDataWriter * filesystem_writer_;
  DDS_ReturnCode_t retcode_;
  std::map<char *, filesystem *> instance_map_;
  std::map<char *, DDS_InstanceHandle_t> instance_handle_map_;
  const char *type_name_;
  DDS_Duration_t send_period_;
  glibtop_mountentry *entries_;
  glibtop_mountlist mountlist_;
  std::string plugin_id_;
  std::string topic_name_;
  std::string qos_library_;
  std::string qos_profile_;
};


BOOST_EXTENSION_TYPE_MAP_FUNCTION
{
  using namespace boost::extensions;
  std::map<std::string, factory<plugin, std::string> > &plugin_factories(types.get());
  plugin_factories["disk"].set<disk>();
}

#endif //DISK_HPP
