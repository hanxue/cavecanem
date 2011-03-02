/*   
 *   Cave Canem Subscriber is part of Cave Canem, an extensible DDS-based 
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

#include <boost/extension/extension.hpp>
#include <boost/extension/factory.hpp>
#include <boost/extension/type_map.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <mysql++/mysql++.h>

#include <syslog.h>
#include <plugins/plugin.hpp>
#include <map>

#include <ndds/ndds_cpp.h>
#include "system_monitor_dds.h"
#include "system_monitor_ddsSupport.h"

#ifndef SYSCONFDIR
#  define SYSCONFDIR ""
#endif

class sysmon_statusListener : public DDSDataReaderListener {
public:
  sysmon_statusListener(std::string plugin_id);
  ~sysmon_statusListener(void);
  virtual void on_requested_deadline_missed(DDSDataReader* /*reader*/,
					    const DDS_RequestedDeadlineMissedStatus& /*status*/) {}
  
  virtual void on_requested_incompatible_qos(DDSDataReader* /*reader*/,
					     const DDS_RequestedIncompatibleQosStatus& /*status*/) {}
  
  virtual void on_sample_rejected(DDSDataReader* /*reader*/,
				  const DDS_SampleRejectedStatus& /*status*/) {}
  
  virtual void on_liveliness_changed(DDSDataReader* /*reader*/,
				     const DDS_LivelinessChangedStatus& /*status*/) {}

  virtual void on_sample_lost(DDSDataReader* /*reader*/,
			      const DDS_SampleLostStatus& /*status*/) {}

  virtual void on_subscription_matched(DDSDataReader* /*reader*/,
				       const DDS_SubscriptionMatchedStatus& /*status*/) {}
  
  virtual void on_data_available(DDSDataReader* reader);
  
private:
  std::map<std::string,std::string> hostinfo_map_;
  std::map<std::string,int> rowcount_map_;
  mysqlpp::Connection conn_;
  std::string database_server_;
  std::string database_name_;
  std::string database_user_;
  std::string database_password_;
  int rows_;
  std::string plugin_id_;
  
};


class system_monitor : public plugin {
public:
  system_monitor(std::string plugin_id);
  virtual void receive_information(void);
  virtual void clean_dds_stuff(void);
  
private:
  //DDS stuff
  DDSDomainParticipant *participant_;
  DDSSubscriber *subscriber_;
  DDSTopic *topic_;
  DDSTopicDescription* topic_or_cft_;
  sysmon_statusListener *reader_listener_;
  DDSDataReader *reader_;
  DDS_ReturnCode_t retcode_;
  const char *type_name_;
  DDS_Duration_t receive_period_;
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
