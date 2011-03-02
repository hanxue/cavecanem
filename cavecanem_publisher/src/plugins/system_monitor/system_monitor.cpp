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

#include "system_monitor.hpp"

using namespace std;
using boost::property_tree::ptree;

system_monitor::system_monitor(string plugin_id) : plugin_id_(plugin_id)
{
  //Getting QoS files
  string sysconf_dir(SYSCONFDIR);
  string conf_file(sysconf_dir + "cavecanem_publisher.xml");

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
 
  /* Register type before creating topic */
  type_name_ = sysmon_statusTypeSupport::get_type_name();
  retcode_ = sysmon_statusTypeSupport::register_type(participant_,type_name_);
  if (retcode_ != DDS_RETCODE_OK) {
    clean_dds_stuff();
    throw runtime_error("register_type error. sysmon_statusTypeSupport");
  }
  
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
      throw runtime_error("create_publisher error");
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
  
  else { //Qos setting using a defined profile
    publisher_ = participant_->
      create_publisher_with_profile(qos_library_.c_str() /*library*/,
				    qos_profile_.c_str() /*profile*/,
				    NULL /*listener*/,
				    DDS_STATUS_MASK_NONE);
    if(publisher_ == NULL) {
      clean_dds_stuff();
      throw runtime_error("create_publisher_with_profile error");
    }
    
    writer_ = publisher_->
      create_datawriter_with_profile(topic_, 
				     qos_library_.c_str(),
				     qos_profile_.c_str(), 
				     NULL /* listener */,
				     DDS_STATUS_MASK_NONE);
    if (writer_ == NULL) {
      clean_dds_stuff();
      throw runtime_error("create_datawriter_with_profile error");
    }
  }
  
  sysmon_status_writer_ = sysmon_statusDataWriter::narrow(writer_);
  if (sysmon_status_writer_ == NULL) {
    clean_dds_stuff();
    throw runtime_error("DataWriter narrow error");
  }

  instance_handle_ = DDS_HANDLE_NIL;
  instance_ = NULL;

  /* Create data sample for writing */
  instance_ = sysmon_statusTypeSupport::create_data();
  if (instance_ == NULL) {
    clean_dds_stuff();
    throw runtime_error("sysmon_statusTypeSupport::create_data error");
  }
   
  glibtop_init();
  temperature_init();
  static struct utsname name; 
  uname(&name);            
  
  hi_.hostname = name.nodename;
  hi_.sysname = name.sysname;
  hi_.release_name =  name.release;
  hi_.machine = name.machine;

  instance_->host = hi_;
  instance_handle_ = sysmon_status_writer_->register_instance(*instance_);
  
}

/* Temperature stuff code is a C++ translation from the englightenment 
 * module "temperature". Original is available at: 
 * http://trac.enlightenment.org/e/browser/trunk/e/src/modules/temperature/tempget.c
 */

void system_monitor::temperature_init(void)
{
  list <string> therms;
  string path;
  sensor_type_ = SENSOR_TYPE_NONE;
  sensor_name_ = NULL;
  sensor_path_ = NULL;
  sensor_alarm_value_ = 60;
  
  if ((!sensor_type_) || ((!sensor_name_) || (sensor_name_[0] == 0))) {
    if (sensor_name_) free(sensor_name_);
    if (sensor_path_) free(sensor_path_);
    sensor_path_ = NULL;
    
    therms = fm_.ls("/proc/acpi/thermal_zone");
    if (!therms.empty()) {
      string name;
      name = therms.back();
      sensor_type_ = SENSOR_TYPE_LINUX_ACPI;
      sensor_name_ = strdup(name.c_str());
      
      therms.clear();
    }
    else {
      therms.clear();
      if (fm_.exists("/sys/devices/virtual/thermal")) {
	sensor_type_ = SENSOR_TYPE_LINUX_VIRTUAL;
	sensor_name_ = strdup("dummy");
      } 
      else if (fm_.exists("/proc/omnibook/temperature")) {
	sensor_type_ = SENSOR_TYPE_OMNIBOOK;
	sensor_name_ = strdup("dummy");
      } 
      else if (fm_.exists("/sys/devices/temperatures/sensor1_temperature")) {
	sensor_type_ = SENSOR_TYPE_LINUX_PBOOK;
	sensor_name_ = strdup("dummy");
      } 
      else if (fm_.exists("/sys/devices/temperatures/cpu_temperature")) {
	sensor_type_ = SENSOR_TYPE_LINUX_MACMINI;
	sensor_name_ = strdup("dummy");
      } 
      else if (fm_.exists("/sys/devices/platform/coretemp.0/temp1_input")) {
	sensor_type_ = SENSOR_TYPE_LINUX_INTELCORETEMP;
	sensor_name_ = strdup("dummy");
      }                ///*
      else {
	// try the i2c bus
	
	therms = temperature_get_bus_files("i2c");
	if (!therms.empty()) {
	  string name;
	  name = therms.back();
	  if (fm_.exists(name)) {
	    path = fm_.file_get(name);
	    sensor_type_ = SENSOR_TYPE_LINUX_I2C;
	    sensor_path_ = strdup(name.c_str());
	    sensor_name_ = strdup(path.c_str());
	  }
	  therms.clear();
	}
	if (!sensor_path_) {
	  // try the pci bus
	  therms = temperature_get_bus_files("pci");
	  if (!therms.empty()) {
	    string name;
	    
	    name = therms.back();
	    
	    if (fm_.exists(name)) {
	      path = fm_.file_get(name);
	      sensor_type_ = SENSOR_TYPE_LINUX_PCI;
	      sensor_path_ = strdup(name.c_str());
	      sensor_name_ = strdup(path.c_str());
	    }
	    
	    therms.clear();
	  }
	}
      }
    }
    
  }
  
  if ((sensor_type_) && (sensor_name_) && (!sensor_path_)) {
    switch (sensor_type_) {
    case SENSOR_TYPE_NONE:
      break;
    case SENSOR_TYPE_OMNIBOOK:
      sensor_path_ = strdup("/proc/omnibook/temperature");
      break;
    case SENSOR_TYPE_LINUX_MACMINI:
      sensor_path_ = strdup("/sys/devices/temperatures/cpu_temperature");
      break;
    case SENSOR_TYPE_LINUX_PBOOK:
      sensor_path_ = strdup("/sys/devices/temperatures/sensor1_temperature");
      break;
    case SENSOR_TYPE_LINUX_INTELCORETEMP:
      sensor_path_ = strdup("/sys/devices/platform/coretemp.0/temp1_input");
      break;
    case SENSOR_TYPE_LINUX_I2C:
      therms = fm_.ls("/sys/bus/i2c/devices");
      
      for (list<string>::iterator it = therms.begin(); it != therms.end(); ++it) {
	path = "/sys/bus/i2c/devices/" + *it + "/" + sensor_name_ + "_input";
	if (fm_.exists(path)) {
	  sensor_path_ = strdup(path.c_str());
	  /* We really only care about the first
	   * one for the default. */
	  break;
	}
      }
      break;
    case SENSOR_TYPE_LINUX_PCI:
      therms = fm_.ls("/sys/bus/pci/devices");
      for (list<string>::iterator it = therms.begin(); it != therms.end(); ++it) {
	path = "/sys/bus/pci/devices/" + *it + "/" + sensor_name_ + "_input";
	if (fm_.exists(path)) {
	  sensor_path_ = strdup(path.c_str());
	  /* We really only care about the first
	   * one for the default. */
	  break;
	}
      }
      
      break;
      
    case SENSOR_TYPE_LINUX_ACPI:
      path = "/proc/acpi/thermal_zone/" + string(sensor_name_) + "/temperature";
      sensor_path_ = strdup(path.c_str());
      break;
    case SENSOR_TYPE_LINUX_VIRTUAL:
      string busdir = "/sys/devices/virtual/thermal";
      therms = fm_.ls(busdir);
      for (list<string>::iterator name = therms.begin(); name != therms.end(); ++name) {
	path = busdir + "/" + *name + "/" + "temp";
	if (fm_.exists(path)) {
	  sensor_path_ = strdup(path.c_str());
	  /* We really only care about the first
	   * one for the default. */
	  break;
	  
	}
      }
      break;
    }
  }
}


list <string> system_monitor::temperature_get_bus_files(string bus) {
  
  string path, busdir;
  list <string> result, therms;
  
  busdir = "/sys/bus/" + bus + "/devices";
  
  therms = fm_.ls(busdir);
  
  
  for (list<string>::iterator name = therms.begin(); name != therms.end(); ++name) {
    
    list<string> files;
    path = busdir + "/" + *name;
    files = fm_.ls(path);
    
    for (list<string>::iterator file = files.begin(); file != files.end(); ++file) {
      
      if ((!strncmp("temp", (*file).c_str(), 4)) &&
	  (!strcmp("_input", &((*file).c_str())[strlen((*file).c_str()) - 6]))) {
	
	char *f;
	path = busdir + "/" + *name + "/" + *file;
	
	f = strdup(path.c_str());
	if (f)
	  result.push_back(string(f));
      }
    }
  }
  
  return result;
  
}

/*
 * This method is another C++ translation of the Enlightenment's temperature module, available at: 
 * http://trac.enlightenment.org/e/browser/trunk/e/src/modules/temperature/tempget.c
 */

double system_monitor::get_temperature(void)
{
  FILE *f;
  bool error = false;
  int ret = 0;
  double temp = 0.0;
  char buf[PATH_MAX];
  
  switch (sensor_type_) {
  case SENSOR_TYPE_NONE:
    break;
    
  case SENSOR_TYPE_OMNIBOOK:
    f = fopen(sensor_path_, "rb");
    
    if (f) {
      char dummy[4096];
      
      fgets(buf, sizeof (buf), f);
      buf[sizeof (buf) - 1] = 0;
      if (sscanf(buf, "%s %s %f", dummy, dummy, &temp) == 3)
	ret = 1;
      else {
	error = true;
	break;
      }
      fclose(f);
    } else
      error = true;

    break;
  case SENSOR_TYPE_LINUX_MACMINI:
  case SENSOR_TYPE_LINUX_PBOOK:
    f = fopen(sensor_path_, "rb");
    if (f) {
      fgets(buf, sizeof (buf), f);
      buf[sizeof (buf) - 1] = 0;
      if (sscanf(buf, "%f", &temp) == 1)
	ret = 1;
      else {
	error = true;
	break;
      }
      fclose(f);
    } else
      error = true;
    break;
  case SENSOR_TYPE_LINUX_VIRTUAL:
  case SENSOR_TYPE_LINUX_INTELCORETEMP:
  case SENSOR_TYPE_LINUX_I2C:
    f = fopen(sensor_path_, "r");
    if (f) {
      fgets(buf, sizeof (buf), f);
      buf[sizeof (buf) - 1] = 0;
      
      /* actually read the temp */
      if (sscanf(buf, "%f", &temp) == 1)
	ret = 1;
      else {
	error = true;
	break;
      }
      temp = temp / 1000.;
      fclose(f);
    } else
      error = true;
    break;
  case SENSOR_TYPE_LINUX_PCI:
    f = fopen(sensor_path_, "r");
    if (f) {
      fgets(buf, sizeof (buf), f);
      buf[sizeof (buf) - 1] = 0;
      
      /* actually read the temp */
      if (sscanf(buf, "%f", &temp) == 1)
	ret = 1;
      else {
	error = true;
	break;
      }
      /* Hack for temp */
      temp = temp / 1000.;
      fclose(f);
    } else
      error = true;
    break;
  case SENSOR_TYPE_LINUX_ACPI:
    f = fopen(sensor_path_, "r");
    if (f) {
      char *p, *q;
      
      fgets(buf, sizeof (buf), f);
      buf[sizeof (buf) - 1] = 0;
      fclose(f);
      p = strchr(buf, ':');
      if (p) {
	p++;
	while (*p == ' ') p++;
	q = strchr(p, ' ');
	if (q) *q = 0;
	temp = atoi(p);
	ret = 1;
      } else
	error = true;
    } else
      error = true;
    break;
  }
  if (ret) {
    return temp;
  }
  else if(error) {
    sensor_type_ = SENSOR_TYPE_NONE;
    if (sensor_name_) free(sensor_name_);
    sensor_name_ = NULL;
    if (sensor_path_) free(sensor_path_);
    sensor_path_ = NULL;
  }
  return -1.0;
}


void system_monitor::publish_information()
{

  //sysmon_status sm;
  //Temperature (ºC)
  instance_->cpu_temp = get_temperature();
  //CPU (%)
  glibtop_get_cpu (&cpu_);
  instance_->cpu_user = cpu_.user*100./cpu_.total;
  instance_->cpu_system = cpu_.sys*100./cpu_.total;
  instance_->cpu_idle = cpu_.idle*100./cpu_.total;
  //Load average
  glibtop_get_loadavg(&loadavg_);
  instance_->lavg.load_one = loadavg_.loadavg [0];
  instance_->lavg.load_five = loadavg_.loadavg [1];
  instance_->lavg.load_fifteen = loadavg_.loadavg [2];
  //Memory (KB)
  glibtop_get_mem(&memory_);
  instance_->mem_total = memory_.total/(1024.0);
  instance_->mem_used = memory_.used/(1024.0);
  instance_->mem_free = memory_.free/(1024.0);
  //Swap (KB)
  glibtop_get_swap(&swap_);
  instance_->swap_total = swap_.total/(1024.0);
  instance_->swap_used = swap_.used/(1024.0);
  instance_->swap_free = swap_.free/(1024.0);
  
  //Publish DDS
  retcode_ = sysmon_status_writer_->write(*instance_, instance_handle_);
  if (retcode_ != DDS_RETCODE_OK) {
    syslog(LOG_ERR,"Error in %s plugin. Reason: write error %d", plugin_id_.c_str(), retcode_);
  }
    
}


void system_monitor::clean_dds_stuff(void)
{
  if(participant_ != NULL) {
    retcode_ = sysmon_status_writer_->unregister_instance(*instance_, instance_handle_);
    if(retcode_ != DDS_RETCODE_OK) 
      syslog(LOG_ERR,"Error in %s plugin. Reason: error unregistering instance", plugin_id_.c_str());
  
    retcode_ = participant_->delete_contained_entities();
    if(retcode_ != DDS_RETCODE_OK)
      syslog(LOG_ERR,"Error in %s plugin. Reason: contained entities deletion failed", plugin_id_.c_str());
    retcode_ = DDSTheParticipantFactory->delete_participant(participant_);

    if(retcode_ != DDS_RETCODE_OK)
      syslog(LOG_ERR,"Error in %s plugin. Reason: participant deletion error", plugin_id_.c_str());
  }
}

//file_management class

bool file_management::is_dir(string file)
{
  struct stat st;
  
  if (stat(file.c_str(), &st) < 0) return false;
  if (S_ISDIR(st.st_mode)) return true;
  return false;
}

string file_management::get_realpath(string file)
{
  char buf[PATH_MAX];
  if (!file.c_str()) return string(strdup(""));
  if (!realpath(file.c_str(), buf)) return string(strdup(""));
  return string(strdup(buf));
}

bool file_management::mkidr(string dir)
{
  if (mkdir(dir.c_str(), default_mode) < 0) return false;
  return true;
}

bool file_management::rmmdir(string dir)
{
  if (rmdir(dir.c_str()) < 0) return false;
  return true;
}

string file_management::dir_get(string file)
{
  char *p;
  char buf[PATH_MAX];
  strncpy(buf, file.c_str(), PATH_MAX);
  p = strrchr(buf, '/');
  if (!p) {
    return strdup(file.c_str());
  }
  
  if (p == buf) return strdup("/");
  
  *p = 0;
  return string(strdup(buf));
}

string file_management::file_get(string str)
{
  size_t found;
  found = str.find_last_of("/\\");
  return str.substr(found + 1);
}

bool file_management::has_extension(string file, string extension)
{
  size_t found;
  found = file.find_last_of(".");
  if (file.substr(found + 1) == extension)
    return true;
  return false;
}

list<string> file_management::ls_r_by_extension(string dir, string extension)
{
  
  std::list<string> file_list;
  DIR *dirp = opendir(dir.c_str());
  
  if (dirp) {
    struct dirent *dp = NULL;
    
    while ((dp = readdir(dirp)) != NULL) {
      std::string file(dp->d_name);
      
      if (file == "." || file == "..") // skip these
	continue;
      
      if (dp->d_type & DT_DIR) {
	// found a directory; recurse into it.
	string file_path = dir + "/" + file;
	list <string> aux = ls_r_by_extension(file_path, extension);
	file_list.insert(file_list.end(), aux.begin(), aux.end());
      } else {
	if (has_extension(file, extension)) {
	  file_list.push_back(dir + "/" + file);
	}
      }
    }
    
    closedir(dirp);
  }
  
  return file_list;
  
}

list <string> file_management::ls(string dir)
{
  string f;
  DIR *dirp;
  list <string> files;
  struct dirent *dp;
  
  dirp = opendir(dir.c_str());
  if (!dirp) return files;
  
  while ((dp = readdir(dirp))) {
    if ((strcmp(dp->d_name, ".")) && (strcmp(dp->d_name, ".."))) {
      f = string(strdup(dp->d_name));
			files.push_back(f);
    }
  }
  
  closedir(dirp);
  
  return files;
  
}

bool file_management::exists(string file)
{
  struct stat st;
  
  if (stat(file.c_str(), &st) < 0 && file != "/")
    return false;
  
  return true;
  
}
