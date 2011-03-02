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

#include "net_load.hpp"

using namespace std;
using boost::property_tree::ptree;

net_load::net_load(string plugin_id) : plugin_id_(plugin_id)
{
  string sysconf_dir(SYSCONFDIR);
  string conf_file(sysconf_dir + "cavecanem_subscriber.xml");
  string filter;

  try {
    ptree pt;
    read_xml(conf_file,pt);
    domain_id_ = pt.get<int>("plugins." + plugin_id + ".domain_id");
    topic_name_ = pt.get<string>("plugins." + plugin_id + ".topic_name");
    qos_library_ = pt.get<string>("plugins." + plugin_id + ".qos_library");
    qos_profile_ = pt.get<string>("plugins." + plugin_id + ".qos_profile");
    filter = pt.get<string>("plugins." + plugin_id + ".filter_expresion");
  }
  catch(exception &e) {
    throw runtime_error(e.what());
  }

  if(qos_profile_ == "default") {
    participant_ = DDSTheParticipantFactory->
      create_participant(domain_id_ /*Domain id*/,
			 DDS_PARTICIPANT_QOS_DEFAULT /*QoS*/,
			 NULL /*listener*/,
			 DDS_STATUS_MASK_NONE);
    if(participant_ == NULL) {
      throw runtime_error("unable to create domain  participant");
    }
  }
  else {
    participant_ = DDSTheParticipantFactory->
      create_participant_with_profile(domain_id_,
				      qos_library_.c_str(),
				      qos_profile_.c_str(),
				      NULL,
				      DDS_STATUS_MASK_NONE);
    if(participant_ == NULL) {
      throw runtime_error("unable to create domain participant with profile");
    }

  }

  /* Register type before creating topic */
  type_name_ = netloadTypeSupport::get_type_name();
  retcode_ = netloadTypeSupport::register_type(participant_, type_name_);
  if (retcode_ != DDS_RETCODE_OK) {
    clean_dds_stuff();
    throw runtime_error("register_type error");
  }  
    
  topic_ = participant_->create_topic(topic_name_.c_str(),
				      type_name_, 
				      DDS_TOPIC_QOS_DEFAULT, 
				      NULL /* listener */,
				      DDS_STATUS_MASK_NONE);
  if (topic_ == NULL) {
    clean_dds_stuff();
    throw runtime_error("create_topic error");
  }

  topic_or_cft_ = topic_;
  
  const DDS_StringSeq parameters;
  if(filter != "none" && filter.length() > 0) {
    topic_or_cft_ = participant_->
      create_contentfilteredtopic((topic_name_ + "(filtered)").c_str(),
				  topic_,
				  filter.c_str(),
				  parameters);
    if(topic_or_cft_ == NULL) {
      clean_dds_stuff();
      throw runtime_error("create_contentfilteredtopic error");
    }
  }
  
  try {
    reader_listener_ = new netloadListener(plugin_id_);
  }
  catch (exception &e) {
    clean_dds_stuff();
    throw runtime_error("error creating netloadListener; " + string(e.what()));
  }
  
  if(qos_profile_ == "default") {
    subscriber_ = participant_->
      create_subscriber(DDS_SUBSCRIBER_QOS_DEFAULT,
			NULL,
			DDS_STATUS_MASK_NONE);
    if(subscriber_ == NULL) {
      clean_dds_stuff();
      throw runtime_error("create_subscriber error");
    }
  }
  else {
    subscriber_ = participant_->
      create_subscriber_with_profile(qos_library_.c_str(),
				     qos_profile_.c_str(),
				     NULL,
				     DDS_STATUS_MASK_NONE);
    if(subscriber_ == NULL) {
      clean_dds_stuff();
      throw runtime_error("create_subscriber_with_profile error");
    }
  }
  
}

void net_load::receive_information(void) 
{

  if(qos_profile_ == "default") {
    reader_ = subscriber_->create_datareader(topic_or_cft_,
					     DDS_DATAREADER_QOS_DEFAULT,
					     reader_listener_,
					     DDS_STATUS_MASK_ALL);
  }
  else {
    reader_ = subscriber_->
      create_datareader_with_profile(topic_or_cft_, 
				     qos_library_.c_str(),
				     qos_profile_.c_str(),
				     reader_listener_,
				     DDS_STATUS_MASK_ALL);
  }

  if (reader_ == NULL) {
    clean_dds_stuff();
    throw runtime_error("create_datareader error");
  }
  

}

void net_load::clean_dds_stuff(void)
{
  if(reader_listener_ != NULL) 
    delete reader_listener_;
  
  if(participant_ != NULL) {
    retcode_ = participant_->delete_contained_entities();
    if(retcode_ != DDS_RETCODE_OK)
      syslog(LOG_ERR, "Error in %s plugin. Reason: contained entities deletion failed", plugin_id_.c_str());
    
    retcode_ = DDSTheParticipantFactory->delete_participant(participant_);
    if(retcode_ != DDS_RETCODE_OK) 
      syslog(LOG_ERR, "Error in %s plugin. Reason: delete participant error", plugin_id_.c_str());
  }

}

netloadListener::netloadListener(string plugin_id) : plugin_id_(plugin_id)
{

  string sysconf_dir(SYSCONFDIR);
  string filename(sysconf_dir + "cavecanem_subscriber.xml");
  
  try {
    ptree pt;
    read_xml(filename,pt);
    //Reading database data
    database_server_ = pt.get<string>("database.server");
    database_name_ = pt.get<string>("database.name");
    database_user_ = pt.get<string>("database.user");
    database_password_ = pt.get<string>("database.password");
    rows_ = pt.get<int>("plugins." + plugin_id + ".max_rows");
  }
  
  catch(std::exception &e) {
    throw runtime_error("problems reading configuration file");
  }
  
  if(!conn_.connect(database_name_.c_str(), 
		database_server_.c_str(), 
		database_user_.c_str(),
		    database_password_.c_str())) {
    throw runtime_error("error connecting " + database_name_ + " database");
  }
  
  mysqlpp::Query query = conn_.query();
  
  query << "CREATE TABLE IF NOT EXISTS hosts (" << 
    "hostname VARCHAR(30) NOT NULL PRIMARY KEY," <<
    "sysname VARCHAR(30)," <<
    "release_name VARCHAR(30)," <<
    "machine VARCHAR(30))";
  query.execute();	
  
  query.exec("DROP TABLE IF EXISTS net_load");
  
  query << "CREATE TABLE net_load (" <<
    "rrd_nl_seq_id INT UNSIGNED NOT NULL DEFAULT 0," <<
    "hostname VARCHAR(30) NOT NULL," <<
    "ts TIMESTAMP NOT NULL," <<
    "device VARCHAR(20) NOT NULL," <<
    "flags INT," <<
    "if_flags INT," <<
    "mtu INT," <<
    "net_addr VARCHAR(30)," <<
    "subnet_addr VARCHAR(30)," <<
    "hwaddress VARCHAR(30)," <<            			
    "packets_in INT UNSIGNED," <<
    "packets_out INT UNSIGNED," <<
    "bytes_in INT UNSIGNED," <<
    "bytes_out INT UNSIGNED," <<
    "bytes_total INT UNSIGNED," <<
    "errors_in INT UNSIGNED," <<
    "errors_out INT UNSIGNED," <<
    "errors_total INT UNSIGNED," <<
    "collisions INT UNSIGNED," <<			
    "PRIMARY KEY(rrd_nl_seq_id,hostname,device)," <<
    "FOREIGN KEY(hostname) REFERENCES hosts(hostname))";
  query.execute();
}

void netloadListener::on_data_available(DDSDataReader* reader)
{
  netloadDataReader *netload_reader = NULL;
  netloadSeq data_seq;
  DDS_SampleInfoSeq info_seq;
  DDS_ReturnCode_t retcode;
  int i;

  netload_reader = netloadDataReader::narrow(reader);
  if (netload_reader == NULL) {
    syslog(LOG_ERR,"Error in %s plugin. Reason: DataReader narrow error", plugin_id_.c_str());
    return;
  }
  
  retcode = netload_reader->take(data_seq, 
				 info_seq, 
				 DDS_LENGTH_UNLIMITED,
				 DDS_ANY_SAMPLE_STATE, 
				 DDS_ANY_VIEW_STATE, 
				 DDS_ANY_INSTANCE_STATE);
  
  if (retcode == DDS_RETCODE_NO_DATA) {
    syslog(LOG_ERR, "Error in %s plugin. Reason: there is no data to take", plugin_id_.c_str());
    return;
  } else if (retcode != DDS_RETCODE_OK) {
    syslog(LOG_ERR,"Error in %s plugin. Reason: take error %d", plugin_id_.c_str(), retcode);
    return;
  }
  
  for (i = 0; i < data_seq.length(); ++i) {
    if (info_seq[i].valid_data) {
      
      mysqlpp::Query query = conn_.query();
	    
      map<string,string>::iterator hostinfo_map_it;
      hostinfo_map_it = hostinfo_map_.find(data_seq[i].host.hostname);
      //Dealing with hosts table
      if(hostinfo_map_it == hostinfo_map_.end()) {
	hostinfo_map_[data_seq[i].host.hostname] = data_seq[i].host.hostname;
	query << "REPLACE INTO hosts VALUES (" <<
	  "'" << data_seq[i].host.hostname << "'," << 
	  "'" << data_seq[i].host.sysname << "'," <<
	  "'" << data_seq[i].host.release_name << "'," <<
	  "'" << data_seq[i].host.machine << "')";
	query.execute();
      }    
      
      //Round Robin storage
      string aux = data_seq[i].host.hostname;
      aux += data_seq[i].device;
      if(rowcount_map_[aux] >= rows_)
	rowcount_map_[aux] = 0;          
      
      query << "REPLACE INTO net_load VALUES (" <<
	rowcount_map_[aux] << "," <<
	"'" << data_seq[i].host.hostname << "'," <<
	"null" << "," <<
	"'" << data_seq[i].device << "'," <<
	data_seq[i].flags << "," <<
	data_seq[i].if_flags << "," <<
	data_seq[i].mtu << "," <<
	"'" << data_seq[i].address_str << "'," <<
	"'" << data_seq[i].subnet_str << "'," <<
	"'" << data_seq[i].hwaddress_str << "'," <<
	data_seq[i].packets_in << "," <<
	data_seq[i].packets_out << "," <<
	data_seq[i].bytes_in << "," <<
	data_seq[i].bytes_out << "," <<
	data_seq[i].bytes_total << "," <<
	data_seq[i].errors_in << "," <<
	data_seq[i].errors_out << "," <<
	data_seq[i].errors_total << "," <<
	data_seq[i].collisions << ")";
      
      query.execute();
      rowcount_map_[aux]++;
    }
    
  }
  
  retcode = netload_reader->return_loan(data_seq, info_seq);
  if (retcode != DDS_RETCODE_OK) {
    syslog(LOG_ERR,"Error in %s plugin. Reason: return loan error %d", plugin_id_.c_str(), retcode);
  }
}

netloadListener::~netloadListener(void)
{
  conn_.disconnect();
}
