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

#include "snort.hpp"


using namespace std;
using boost::property_tree::ptree;

snort::snort(string plugin_id) : plugin_id_(plugin_id)
{
  //Getting QoS files
  string sysconf_dir(SYSCONFDIR);
  string conf_file(sysconf_dir + "cavecanem_publisher.xml");
  string qos_profile_name;
    
  try {
    ptree pt;
    read_xml(conf_file,pt);
    domain_id_ = pt.get<int>("plugins." + plugin_id + ".domain_id");
    topic_name_ = pt.get<string>("plugins." + plugin_id + ".topic_name");
    qos_library_ = pt.get<string>("plugins." + plugin_id + ".qos_library");
    qos_profile_ = pt.get<string>("plugins." + plugin_id + ".qos_profile");
    log_file_ = pt.get<string>("plugins." + plugin_id + ".log_file");
  }
  catch(exception &e) {
    throw runtime_error(e.what());
  }
  
  //Setting today's date
  time_t rawtime;
  struct tm * timeinfo;
    
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );	
  latest_date_.mon = timeinfo->tm_mon + 1;
  latest_date_.mday = timeinfo->tm_mday;
  // latest_date_.hour = 0;
  // latest_date_.min = 0;
  // latest_date_.sec = 0;
  latest_date_.hour = timeinfo->tm_hour;
  latest_date_.min = timeinfo->tm_min;
  latest_date_.sec = timeinfo->tm_sec;

  this_year_ = timeinfo->tm_year;
    
    
  //Getting today's alerts
  update_alertsmap();
    
    
  //DDS Stuff
  if(qos_profile_ == "default") {
    participant_ = DDSTheParticipantFactory->
      create_participant(domain_id_, /* Domain ID */
			 DDS_PARTICIPANT_QOS_DEFAULT,/* QoS */
			 NULL,/* Listener */
			 DDS_STATUS_MASK_NONE);
    if (participant_ == NULL) {
      throw runtime_error("unable to create domain participant.");
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
      throw runtime_error("Unable to create domian participant with profile");
    }
  }

    
  // Register type before creating topic
  type_name_ = ids_alertTypeSupport::get_type_name();
  retcode_ = ids_alertTypeSupport::register_type(participant_, type_name_);
  if (retcode_ != DDS_RETCODE_OK) {
    clean_dds_stuff();
    throw runtime_error("register_type error %d");
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
    
  //Creating Publisher and DataWriter
  if(qos_profile_ == "default") { //QoS default setting
    publisher_ = participant_->create_publisher(DDS_PUBLISHER_QOS_DEFAULT,
						NULL,
						DDS_STATUS_MASK_NONE);
    if (publisher_ == NULL) {
      clean_dds_stuff();
      throw runtime_error("create_publisher_with_profile error");
    }
    
    writer_ = publisher_->create_datawriter(topic_,
					    DDS_DATAWRITER_QOS_DEFAULT,
					    NULL,
					    DDS_STATUS_MASK_NONE);
    if (writer_ == NULL) {
      clean_dds_stuff();
      throw runtime_error("create_datawriter error");
    }
    
  }

  else { //QoS setting using a defined profile
    publisher_ = participant_->
      create_publisher_with_profile(qos_library_.c_str() /*library*/, 
				    qos_profile_.c_str() /*profile*/,
				    NULL /* listener */, 
				    DDS_STATUS_MASK_NONE);    	
    if (publisher_ == NULL) {
      clean_dds_stuff();
      throw runtime_error("create_publisher_with_profile error");
    }
    
    writer_ = publisher_->
      create_datawriter_with_profile(topic_, 
				     qos_library_.c_str() /*library*/,
				     qos_profile_.c_str() /*profile*/,
				     NULL /* listener */,
				     DDS_STATUS_MASK_NONE);
    if (writer_ == NULL) {
      clean_dds_stuff();
      throw runtime_error("create_datawriter error");
    }
  }

  //Creating ids_alert_writer
  ids_alert_writer_ = ids_alertDataWriter::narrow(writer_);
  if (ids_alert_writer_ == NULL) {
    clean_dds_stuff();
    throw runtime_error("DataWriter narrow error");
  }
    
    
  static struct utsname name; 
  uname(&name);            
    
  hi_.hostname = name.nodename;
  hi_.sysname = name.sysname;
  hi_.release_name =  name.release;
  hi_.machine = name.machine; 	
    
}

void snort::update_alertsmap()
{
  
  ifstream file(log_file_.c_str());
  
  string line;
  vector<string> alert;
  char buf;
  bool force_exit = false;
  bool first_line = false;
  
  file.seekg(0,ios::beg);
  ifstream::pos_type pos_beg = file.tellg();
  file.seekg(-1,ios::end);
  
  date next_latest_date = latest_date_;
  
  //Processing newer alerts from snort's alert.csv
  while(file.tellg() != pos_beg && !force_exit) {
    buf = static_cast <char>(file.peek());
    
    if(buf != '\n')
      line += buf;
    else if(!line.empty()) {
      reverse(line.begin(),line.end());
      std::vector<std::string> strs;
      boost::split(strs, line, boost::is_any_of(","));			
      if(strs.size()==27) {
	if(is_newer(strs[0])) {	
	  struct ids_alert_without_timestamp aux;
	  aux.sig_generator = strs[1];
	  aux.sig_id = strs[2];
	  aux.sig_rev  = strs[3];
	  aux.msg  = strs[4];
	  aux.proto = strs[5];
	  aux.src = strs[6];
	  aux.srcport = strs[7];
	  aux.dst = strs[8];
	  aux.dstport = strs[9];
	  aux.ethsrc = strs[10];
	  aux.ethdst = strs[11];
	  aux.ethlen = strs[12];
	  aux.tcpflags = strs[13];
	  aux.tcpseq = strs[14];	
	  aux.tcpack = strs[15];
	  aux.tcplen = strs[16];
	  aux.tcpwindow = strs[17];
	  aux.ttl = strs[18];
	  aux.tos = strs[19];
	  aux.id = strs[20];
	  aux.dgmlen = strs[21];
	  aux.iplen = strs[22];
	  aux.icmptype = strs[23];
	  aux.icmpcode = strs[24];
	  aux.icmpid = strs[25];
	  aux.icmpseq = strs[26];
	  alert_map_[strs[0]] = aux;
	  if(first_line) {
	    next_latest_date = get_date_from_timestamp(strs[0]);
	    next_latest_date.sec += 1;
	    first_line = false;
	  }
	}
	
	else force_exit = true;
      }
      
      line.clear();
      
    }
    
    else {
      first_line = true;
    }
    
    file.seekg(-1,ios::cur);
  }
  
  //Latest line processing
  if(force_exit == false) {
    buf = static_cast <char>(file.peek());	
    line += buf;
    reverse(line.begin(),line.end());
    std::vector<std::string> strs;
    boost::split(strs, line, boost::is_any_of(","));			
    if(strs.size()==27 && is_newer(strs[0])) {			
      struct ids_alert_without_timestamp aux;
      aux.sig_generator = strs[1];
      aux.sig_id = strs[2];
      aux.sig_rev  = strs[3];
      aux.msg  = strs[4];
      aux.proto = strs[5];
      aux.src = strs[6];
      aux.srcport = strs[7];
      aux.dst = strs[8];
      aux.dstport = strs[9];
      aux.ethsrc = strs[10];
      aux.ethdst = strs[11];
      aux.ethlen = strs[12];
      aux.tcpflags = strs[13];
      aux.tcpseq = strs[14];	
      aux.tcpack = strs[15];
      aux.tcplen = strs[16];
      aux.tcpwindow = strs[17];
      aux.ttl = strs[18];
      aux.tos = strs[19];
      aux.id = strs[20];
      aux.dgmlen = strs[21];
      aux.iplen = strs[22];
      aux.icmptype = strs[23];
      aux.icmpcode = strs[24];
      aux.icmpid = strs[25];
      aux.icmpseq = strs[26];
      alert_map_[strs[0]] = aux;			
    }
    line.clear();
  }
  
  file.close();
  
  //Updating latest line transmited date
  latest_date_ = next_latest_date;

}

date snort::get_date_from_timestamp(string timestamp)
{
  vector<string> vec;
  date dat;
  
  //Getting month
  boost::split(vec,timestamp,boost::is_any_of("/"));
  dat.mon = atoi(vec[0].c_str());
  //Getting month day
  boost::split(vec,vec[1],boost::is_any_of("-"));
  dat.mday = atoi(vec[0].c_str());
  //Getting hour, minute and second
  boost::split(vec,vec[1],boost::is_any_of("."));
  boost::split(vec,vec[0],boost::is_any_of(":"));
  dat.hour = atoi(vec[0].c_str());
  dat.min = atoi(vec[1].c_str());
  dat.sec = atoi(vec[2].c_str());
  
  return dat;
}

bool snort::is_newer(string timestamp)
{
  date timestamp_date;
  timestamp_date = get_date_from_timestamp(timestamp);
  
  //Newer month
  if(latest_date_.mon < timestamp_date.mon)
    return true;
  //Newer mday		
  if(latest_date_.mon == timestamp_date.mon &&	\
     latest_date_.mday  < timestamp_date.mday)
    return true;
  //Newer hour	   	
  if(latest_date_.mon  == timestamp_date.mon &&			      \
     latest_date_.mday  == timestamp_date.mday  &&		      \
     latest_date_.hour < timestamp_date.hour)
    return true;
  //Newer min           	
  if(latest_date_.mon   == timestamp_date.mon &&		      \
     latest_date_.mday  == timestamp_date.mday  &&		      \
     latest_date_.hour  == timestamp_date.hour  &&		      \
     latest_date_.min   < timestamp_date.min)
    return true;
  //Newer sec		
  if(latest_date_.mon   == timestamp_date.mon &&		       \
     latest_date_.mday  == timestamp_date.mday  &&		       \
     latest_date_.hour  == timestamp_date.hour  &&		       \
     latest_date_.min   == timestamp_date.min    &&		       \
     latest_date_.sec   <= timestamp_date.sec)
    return true;
  
  return false;
  
}



void snort::publish_information()
{
  
  update_alertsmap();
  map<string,struct ids_alert_without_timestamp>::iterator it;
  
  ids_alert alert;
  node_info source, target;
  
  for(it = alert_map_.begin(); it != alert_map_.end(); ++it) {
    alert.timestamp_string = (char*)it->first.c_str();
    instance_ = NULL;
    instance_handle_ = DDS_HANDLE_NIL;
    instance_ = ids_alertTypeSupport::create_data();
    if (instance_ == NULL) {
      clean_dds_stuff();
      throw runtime_error("netloadTypeSupport::create_data error");
    }

    instance_->timestamp_string = alert.timestamp_string;
    instance_->host = hi_;
    
    instance_handle_ = 
      ids_alert_writer_->register_instance(*instance_);
     
       
    //Source node
    source.prt = atoi(it->second.srcport.c_str());
    source.network_addr = (char*)it->second.src.c_str();
    source.mac = (char*)it->second.ethsrc.c_str();
    alert.source = source;
    
    //Target node
    target.prt = atoi(it->second.dstport.c_str());
    target.network_addr =(char*) it->second.dst.c_str();
    target.mac = (char*)it->second.ethdst.c_str();
    alert.target = target;
    
    //Timestamp
    struct date aux = get_date_from_timestamp(it->first);
    alert.ts.year = this_year_ + 1900;
    alert.ts.mday = aux.mday;
    alert.ts.mon = aux.mon;
    alert.ts.hour = aux.hour;
    alert.ts.min = aux.min;
    alert.ts.sec = aux.sec;
    
    //Message
    alert.msg = (char*) it->second.msg.c_str();
    
    //Publish DDS
    instance_->source = alert.source;
    instance_->target = alert.target;
    instance_->ts = alert.ts;
    instance_->msg = alert.msg;
    
    
    retcode_ = ids_alert_writer_->
      write(*instance_, instance_handle_);
    if (retcode_ != DDS_RETCODE_OK) {
      syslog(LOG_ERR,"Error in %s plugin. Reason: write error %d", plugin_id_.c_str(),retcode_);
    }
    
    retcode_ = ids_alert_writer_->unregister_instance(*instance_,instance_handle_);
    if(retcode_ != DDS_RETCODE_OK)
      syslog(LOG_ERR,"Error in %s plugin. Reason: error unregistering instance", plugin_id_.c_str());
    
  }
  
  alert_map_.clear();
  
}

void snort::clean_dds_stuff(void)
{
  if (participant_ != NULL) {
    retcode_ = ids_alert_writer_->unregister_instance(*instance_, instance_handle_);
    if(retcode_ != DDS_RETCODE_OK) {
      syslog(LOG_ERR,"Error in %s plugin. Reason: error unregistering instance", plugin_id_.c_str());
    }
    retcode_ = participant_->delete_contained_entities(); 
    if (retcode_ != DDS_RETCODE_OK)
      syslog(LOG_ERR, "Error in %s plugin. Reason: contained entities deletion failed.", plugin_id_.c_str());
    
    retcode_ = DDSTheParticipantFactory->delete_participant(participant_);
    if (retcode_ != DDS_RETCODE_OK) 
      syslog(LOG_ERR, "Error in %s plugin. Reason: Participant deletion error.", plugin_id_.c_str());
  }
}
