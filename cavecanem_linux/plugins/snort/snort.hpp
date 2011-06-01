/*   
 *   This file is part of Cave Canem, an extensible DDS-based  monitoring and 
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

#ifndef SNORT_HPP
#define SNORT_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <ctime>
#include <vector>
#include <algorithm>
#include <sstream>

extern "C" {
#include <sigar.h>
}


#include <plugin.hpp>


/** 
 * @class ids_alert_without_timestamp
 * 
 * Stores the fiels of an IDS alert read from a Snort's
 * CSV log file--all the field except the timestamp.
 */
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
};

/** 
 * @class date 
 * Represents a date using integers to 
 * store a year, month day, month, hour, minute and second.
 * 
 */
struct date {
    int year;
    int mday;
    int mon;
    int hour;
    int min;
    int sec;
};


/** 
 * @class snort
 * This class defines the snort plugin. The objective of this plugin
 * is to get and publish alerts generated from the IDS Snort, by reading
 * its output from a CSV log file.
 */
class snort : public cc_plugin {
public:
    snort(std::string plugin_id,
	  std::map<std::string,std::string> properties);
    virtual ~snort(void);
    virtual bool generate_and_publish_information(DDSDynamicDataWriter *writer,
						  DDS_DynamicData *data);
    virtual std::string plugin_class()
    {
	return "snort";
    }

private:
    bool initialize_plugin(std::map<std::string, std::string> properties);  

    void update_alertsmap(void);
    bool is_newer(std::string timestamp);
    date get_date_from_timestamp(std::string timestamp);
    std::vector<std::string> split_string(std::string str, char element);

    int this_year_;
    int domain_id_;
    date latest_date_;
    std::map<std::string, struct ids_alert_without_timestamp> alert_map_;
    
    std::string log_file_;
    sigar_t *sig_;
    char hostname_[SIGAR_MAXHOSTNAMELEN];
      
};


/** 
 * @brief Defines the "C" create function of the plugin snort (class factory).
 * 
 * Defines the "C" create function of the plugin snort. It returns a new
 * object of the class <code>snort</code>.
 * @param plugin_id The name of the plugin
 * @param properties Map of the properties of the plugin.
 * 
 * @return 
 */
extern "C" cc_plugin* create_snort(std::string plugin_id,
				   std::map<std::string,std::string> properties) {
    return new snort(plugin_id,properties);
}


#endif //SNORT_HPP
