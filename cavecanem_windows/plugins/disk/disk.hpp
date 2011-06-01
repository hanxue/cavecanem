/*   
 *   This file is part of Cave Canem, an extensible DDS-based monitoring and 
 *   intrusion detection system.
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

#include <ctime>
#include <map>

extern "C" {
#include <sigar.h>
}
#include <ndds/ndds_cpp.h>
#include <plugin.hpp>

/** 
 * @class disk 
 * This class defines the disk plugin. The objective of this plugin is to
 * get and publish the status of the filesystems of a machine. To achieve 
 * this objetive it uses the Hyperic Sigar library.
 */
class disk : public cc_plugin {
 public:
    __declspec(dllexport) disk(std::string plugin_id, std::map<std::string,std::string> properties);
    __declspec(dllexport) virtual ~disk(void);
    __declspec(dllexport) virtual bool generate_and_publish_information(DDSDynamicDataWriter *writer,
						  DDS_DynamicData *data);

    __declspec(dllexport)virtual std::string plugin_class() 
      { 
	    return "disk";
      }
    
 private:
    __declspec(dllexport)  bool initialize_plugin(std::map<std::string, std::string> properties);  
    sigar_t *sig_;
    sigar_file_system_list_t fslist_;
    long timestamp_;
    char hostname_[SIGAR_MAXHOSTNAMELEN];
};

/** 
 * @brief Defines the "C" create function of the disk plugin (class factory).
 * 
 * Defines the "C" create function of the disk plugin. It returns a new
 * object of the class <code>disk</code>.
 * @param plugin_id The name of the plugin
 * @param properties Map of the properties of the plugin.
 * 
 * @return 
 */
extern "C" __declspec(dllexport)  cc_plugin* create_disk(std::string plugin_id,
				  std::map<std::string,std::string> properties) {
    return new disk(plugin_id,properties);
}

#endif //DISK_HPP
