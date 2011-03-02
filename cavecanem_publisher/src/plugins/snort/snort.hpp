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

#ifndef SNORT_HPP
#define SNORT_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <ctime>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <sys/utsname.h>
#include <sstream>
#include <syslog.h>

#include <plugins/plugin.hpp>


#include <boost/extension/extension.hpp>
#include <boost/extension/factory.hpp>
#include <boost/extension/type_map.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>


#include <ndds/ndds_cpp.h>
#include "ids_dds.h"
#include "ids_ddsSupport.h"


struct ids_alert_without_timestamp {
  std::string sig_generator;
  std::string sig_id;
  std::string sig_rev;
  std::string msg;
  std::string proto;
  std::string src;
  std::string srcport;
  std::string dst;
  std::string dstport;
  std::string ethsrc;
  std::string ethdst;
  std::string ethlen;
  std::string tcpflags;
  std::string tcpseq;
  std::string tcpack;
  std::string tcplen;
  std::string tcpwindow;
  std::string ttl;
  std::string tos;
  std::string id;
  std::string dgmlen;
  std::string iplen;
  std::string icmptype;
  std::string icmpcode;
  std::string icmpid;
  std::string icmpseq;
};

struct date {
  int mday;
  int mon;
  int hour;
  int min;
  int sec;
};

class snort : public plugin {
public:
  snort(std::string plugin_id);
  virtual void publish_information(void);
  virtual void clean_dds_stuff(void);
private:
  void update_alertsmap(void);
  void get_values(void);
  bool is_newer(std::string timestamp);
  date get_date_from_timestamp(std::string timestamp);
  date latest_date_;
  std::map<std::string, struct ids_alert_without_timestamp> alert_map_;
  std::string qos_file_;
  std::string log_file_;
  host_info hi_;
  
  //DDS_Stuff
  DDSDomainParticipant *participant_;
  DDSPublisher *publisher_;
  DDSTopic *topic_;
  DDSDataWriter *writer_;
  ids_alertDataWriter * ids_alert_writer_;
  //  std::map<char*,ids_alert *> instance_map_;
  ids_alert *instance_;
  DDS_ReturnCode_t retcode_;
  //  std::map<char*,DDS_InstanceHandle_t> instance_handle_map_;
  DDS_InstanceHandle_t instance_handle_;
  const char *type_name_;
  DDS_Duration_t send_period_;	
  int this_year_;
  int domain_id_;
  std::string topic_name_;
  std::string qos_library_;
  std::string qos_profile_;
  std::string plugin_id_;
  
};


BOOST_EXTENSION_TYPE_MAP_FUNCTION
{
  using namespace boost::extensions;
  std::map<std::string, factory<plugin, std::string> > &plugin_factories(types.get());
  plugin_factories["snort"].set<snort>();
}

#endif //SNORT_HPP
