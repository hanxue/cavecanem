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

#include "disk.hpp"

using namespace std;
using boost::property_tree::ptree;

disk::disk(string plugin_id) : plugin_id_(plugin_id)
{
  //Getting configuration file
  string sysconf_dir(SYSCONFDIR);
  string conf_file (sysconf_dir + "cavecanem_publisher.xml");
      
  //DDS Stuff
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
  
  if(qos_profile_ == "default") {
    participant_ = DDSTheParticipantFactory->
      create_participant(domain_id_, /* Domain ID */
			 DDS_PARTICIPANT_QOS_DEFAULT,/* QoS */
			 NULL,/* Listener */
			 DDS_STATUS_MASK_NONE);
    if (participant_ == NULL) {
      throw runtime_error("Unable to create domain participant.");
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
      throw runtime_error("Unable to create domain participant with profile");
    }
  }




  /* Register type before creating topic */
  type_name_ = filesystemTypeSupport::get_type_name();
  retcode_ = filesystemTypeSupport::register_type(participant_,type_name_);
  if(retcode_ != DDS_RETCODE_OK) {
    clean_dds_stuff();
    throw runtime_error("Register_type error. filesystemTypeSupport");
  }
  
  // Definition of the FileSystem Topic
  topic_ = participant_->create_topic(topic_name_.c_str(),
  				      type_name_, 
  				      DDS_TOPIC_QOS_DEFAULT,
  				      NULL /* listener */,
  				      DDS_STATUS_MASK_NONE);
  if (topic_ == NULL) {
    clean_dds_stuff();
    throw runtime_error("create_topic error");
  }

  if(qos_library_ != "none" && qos_library_.length() > 0) {
    retcode_ = participant_->set_default_library(qos_library_.c_str());
    if(retcode_ != DDS_RETCODE_OK) {
      clean_dds_stuff();
      throw runtime_error("error in participant_->set_default_library(" +
			  qos_library_ +
			  ")");
    }
  }

  //Creating publisher and DataWriter
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
      create_publisher_with_profile(NULL /*library*/, 
  				    qos_profile_.c_str() /*profile*/,
  				    NULL /* listener */, 
  				    DDS_STATUS_MASK_NONE);
    if (publisher_ == NULL) {
      clean_dds_stuff();
      throw runtime_error("create_publisher_with_profile error");
    }
    
    writer_ = publisher_->
      create_datawriter_with_profile(topic_, 
  				     NULL /*library*/, 
  				     qos_profile_.c_str() /*profile*/,
  				     NULL /* listener */,
  				     DDS_STATUS_MASK_NONE);
    if (writer_ == NULL) {
      clean_dds_stuff();
      throw runtime_error("create_datawriter error");
    }
    
  }
  
  //Creating filesystemWriter
  filesystem_writer_ = filesystemDataWriter::narrow(writer_);
  if (filesystem_writer_ == NULL) {
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

  entries_ = glibtop_get_mountlist(&mountlist_, 0);
  
  for (int i = 0; i != mountlist_.number; ++i) {
    if (string(entries_[i].devname).find("/dev/") == 0 || 
	string(entries_[i].mountdir).find("/media/") == 0) {
      // Creating data sample for writing
      instance_map_[entries_[i].devname] = NULL;
      instance_handle_map_[entries_[i].devname] = DDS_HANDLE_NIL;
      instance_map_[entries_[i].devname] = 
	filesystemTypeSupport::create_data();
      if (instance_map_[entries_[i].devname] == NULL) {
	clean_dds_stuff();
	throw runtime_error("filesystemTypeSupport::create_data error");
      }
      instance_map_[entries_[i].devname]->host = hi_;
      strcpy(instance_map_[entries_[i].devname]->name, entries_[i].devname);
      instance_handle_map_[entries_[i].devname] = 
	filesystem_writer_->register_instance(*instance_map_[entries_[i].devname]);
    }
  }
								
}


void disk::publish_information(void)
{
  for (int i = 0; i < mountlist_.number; i++) {
    if (string(entries_[i].devname).find("/dev/") == 0 || 
	string(entries_[i].mountdir).find("/media/") == 0) {
      glibtop_fsusage usage;
      glibtop_get_fsusage(&usage, entries_[i].mountdir);
      
      //strcpy(instance_->name, entries[i].devname);
      strcpy(instance_map_[entries_[i].devname]->mountdir, entries_[i].mountdir);
      instance_map_[entries_[i].devname]->total = 
	((usage.blocks * usage.block_size) / 1024);
      instance_map_[entries_[i].devname]->used = 
	((usage.blocks - usage.bfree) * usage.block_size) / 1024;
      instance_map_[entries_[i].devname]->free = 
	((usage.bavail * usage.block_size) / 1024);
      instance_map_[entries_[i].devname]->used_per = 
	(usage.blocks - usage.bavail) * 100.0/ (double)usage.blocks;
      instance_map_[entries_[i].devname]->free_per = 
	instance_map_[entries_[i].devname]->free* 100.0 / 
	(double)instance_map_[entries_[i].devname]->total;
      instance_map_[entries_[i].devname]->read = 
	usage.read;
      instance_map_[entries_[i].devname]->write = 
	usage.write;
      //instance_->host = hi_;
      
      retcode_ = filesystem_writer_->
      	write(*instance_map_[entries_[i].devname], instance_handle_map_[entries_[i].devname]);
      if (retcode_ != DDS_RETCODE_OK) {
      	syslog(LOG_ERR, "Error in %s plugin. Reason: write error %d", plugin_id_.c_str(),retcode_);
      }      
    }
  }
  
  //  g_free(entries_);
}

void disk::clean_dds_stuff(void)
{
  if(participant_ != NULL) {
    //Clearing instances
    for(map<char*, filesystem*>::iterator it = instance_map_.begin();
	it != instance_map_.end(); ++it) {
      retcode_ = filesystem_writer_->unregister_instance(*it->second, instance_handle_map_[it->first]);
      
      if(retcode_ != DDS_RETCODE_OK)
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

