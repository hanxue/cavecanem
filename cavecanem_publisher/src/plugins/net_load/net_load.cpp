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

#include "net_load.hpp"

using namespace std;
using boost::property_tree::ptree;

net_load::net_load(string plugin_id) : plugin_id_(plugin_id)
{
  // Getting QoS files
  string sysconf_dir(SYSCONFDIR);
  string conf_file(sysconf_dir + "cavecanem_publisher.xml");

  // Getting user configuration parameters
  try {
    ptree pt;
    read_xml(conf_file,pt);
    domain_id_ = pt.get<int>("plugins." + plugin_id + ".domain_id");
    topic_name_ = pt.get<string>("plugins." + plugin_id + ".topic_name");
    qos_library_ = pt.get<string>("plugins." + plugin_id + ".qos_library");
    qos_profile_ = pt.get<string>("plugins." + plugin_id + ".qos_profile");
  }
  catch(exception &e) {
    throw runtime_error(e.what());
  }
  
  //Creating Domain Participant
  if(qos_profile_ == "default") {
    participant_ = DDSTheParticipantFactory->
      create_participant(domain_id_, /* Domain ID */
			 DDS_PARTICIPANT_QOS_DEFAULT,/* QoS */
			 NULL,/* Listener */
			 DDS_STATUS_MASK_NONE);
    if(participant_ == NULL) {
      throw runtime_error("Unable to create domain participant");
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

  
  // Registering type before creating topic
  type_name_ = netloadTypeSupport::get_type_name();
  retcode_ = netloadTypeSupport::register_type(participant_, type_name_);
  if (retcode_ != DDS_RETCODE_OK) {
    clean_dds_stuff();
    throw runtime_error("register_type error");
  }  
  
  // Definition of the net_load topic
  topic_ = participant_->
    create_topic(topic_name_.c_str(),
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
  
  netload_writer_ = netloadDataWriter::narrow(writer_);
  if (netload_writer_ == NULL) {
    clean_dds_stuff();
    throw runtime_error("DataWriter narrow error");
  }
  
  glibtop_init();
  static struct utsname name; 
  uname(&name);            
  
  hi_.hostname = name.nodename;
  hi_.sysname = name.sysname;
  hi_.release_name =  name.release;
  hi_.machine = name.machine;     

  devices_ = glibtop_get_netlist(&buf_);
  
  for (int i = 0; i < buf_.number; ++i) {

    instance_map_[devices_[i]] = NULL;
    instance_handle_map_[devices_[i]] = DDS_HANDLE_NIL;
    instance_map_[devices_[i]] = netloadTypeSupport::create_data();
    if (instance_map_[devices_[i]] == NULL) {
      clean_dds_stuff();
      throw runtime_error("netloadTypeSupport::create_data error");
    }
    instance_map_[devices_[i]]->host = hi_;
    strcpy(instance_map_[devices_[i]]->device, devices_[i]);
    
    instance_handle_map_[devices_[i]] = 
      netload_writer_->register_instance(*instance_map_[devices_[i]]);
  }
  
}    


void net_load::publish_information()
{
  for(int i = 0; i < buf_.number; ++i) {
    glibtop_get_netload(&netload_, devices_[i]);
    
    //    strcpy(instance_->device, devices_[i]);
    instance_map_[devices_[i]]->flags = netload_.flags;
    instance_map_[devices_[i]]->if_flags = netload_.if_flags;
    
    //Dealing with network addresses
    addr_.s_addr = netload_.address;
    subnet_.s_addr = netload_.subnet;
    strcpy(instance_map_[devices_[i]]->address_str, inet_ntoa(addr_));
    strcpy(instance_map_[devices_[i]]->subnet_str, inet_ntoa(subnet_));
        
    instance_map_[devices_[i]]->mtu = netload_.mtu;
    instance_map_[devices_[i]]->collisions = netload_.collisions;
    instance_map_[devices_[i]]->packets_in = netload_.packets_in;
    instance_map_[devices_[i]]->packets_out = netload_.packets_out;
    instance_map_[devices_[i]]->packets_total = netload_.packets_total;
    instance_map_[devices_[i]]->bytes_in = netload_.bytes_in;
    instance_map_[devices_[i]]->bytes_out = netload_.bytes_out;
    instance_map_[devices_[i]]->bytes_total = netload_.bytes_total;  
    instance_map_[devices_[i]]->errors_in = netload_.errors_in;
    instance_map_[devices_[i]]->errors_out = netload_.errors_out;
    instance_map_[devices_[i]]->errors_total = netload_.errors_total;
    
    char hwaddres_char[32];
    sprintf(hwaddres_char,"%02x:%02x:%02x:%02x:%02x:%02x",
            (netload_.hwaddress)[0]  & 0xff,
            (netload_.hwaddress)[1]  & 0xff,
            (netload_.hwaddress)[2]  & 0xff,
            (netload_.hwaddress)[3]  & 0xff,
            (netload_.hwaddress)[4]  & 0xff,
            (netload_.hwaddress)[5]  & 0xff);
    
    strcpy(instance_map_[devices_[i]]->hwaddress_str, hwaddres_char);
    // instance_->host = hi_;
    
    retcode_ = netload_writer_->
      write(*instance_map_[devices_[i]], instance_handle_map_[devices_[i]]);
    if (retcode_ != DDS_RETCODE_OK) {
      syslog(LOG_ERR,"Error in %s plugin. Reason: write error %d", plugin_id_.c_str(), retcode_);
    }
    
  }
  
}

void net_load::clean_dds_stuff(void) 
{
  if (participant_ != NULL) {
    for(map<char*,netload*>::iterator it = instance_map_.begin();
	it != instance_map_.end(); ++it) {
      retcode_ = netload_writer_->unregister_instance(*it->second, instance_handle_map_[it->first]);
      if(retcode_ != DDS_RETCODE_OK)
	syslog(LOG_ERR,"Error in %s plugin. Reason: error unregistering instance", plugin_id_.c_str());
    }
    retcode_ = participant_->delete_contained_entities(); 
    if (retcode_ != DDS_RETCODE_OK)
      syslog(LOG_ERR, "Error in %s plugin. Reason: contained entities deletion failed.", plugin_id_.c_str());
    
    retcode_ = DDSTheParticipantFactory->delete_participant(participant_);
    if (retcode_ != DDS_RETCODE_OK) 
      syslog(LOG_ERR, "Error in %s plugin. Reason: participant deletion error.", plugin_id_.c_str());
  }
}
