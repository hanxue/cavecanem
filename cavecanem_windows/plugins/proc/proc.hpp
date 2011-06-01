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

#ifndef PROC_HPP
#define PROC_HPP

#include <ctime>
#include <map>
extern "C" {
#include <sigar.h>
#include <sigar_format.h>
}
#include <plugin.hpp>


/** 
 * @class proc
 * This class defines the proc plugin. The objective of this plugin is to 
 * get and publish the status of the processes running on a machine. To achieve
 * this objetive it uses the Hyperic Sigar library.
 */
class proc : public cc_plugin {
 public:
    __declspec(dllexport) proc(std::string plugin_id,
	     std::map<std::string,std::string> properties);
    __declspec(dllexport) virtual ~proc();
    
    __declspec(dllexport) bool generate_and_publish_information(DDSDynamicDataWriter *writer,
					  DDS_DynamicData *data);

    __declspec(dllexport) virtual std::string plugin_class() 
    { 
	    return "proc";
    }

 private:
    __declspec(dllexport) bool initialize_plugin(std::map<std::string, std::string> properties);  
    sigar_t *sig_;
    sigar_proc_list_t proclist_;
    sigar_proc_state_t procstate_;
    sigar_proc_mem_t procmem_;
    sigar_proc_cred_t proccred_;
    sigar_proc_cred_name_t proccredname_;
    sigar_proc_cpu_t proccpu_;

    long timestamp_;
    char hostname_[SIGAR_MAXHOSTNAMELEN];

};

/** 
 * @brief Defines the "C" create function of the plugin create_proc
 * (class factory).
 * 
 * Defines the "C" create function of the plugin memory. It returns a new
 * object of the class <code>proc</code>.
 * @param plugin_id The name of the plugin
 * @param properties Map of the properties of the plugin.
 * 
 * @return 
 */
extern "C" __declspec(dllexport) cc_plugin* create_proc(std::string plugin_id,
				  std::map<std::string,std::string> properties) {
    return new proc(plugin_id,properties);
}

#endif //PROC_HPP
