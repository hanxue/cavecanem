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

#include "snort.hpp"


using namespace std;


/** 
 * @brief Constructor of the class snort.
 * 
 * The constructor calls initialize_plugin() to load the properties.
 * @param plugin_id Name of the plugin
 * @param properties Map of properties.
 */
snort::snort(string plugin_id, map<string,string> properties)
{
    
    if(!initialize_plugin(properties))
	throw runtime_error("Snort plugin could not be initialized");

}

/** 
 * @brief Destructor of the class snort.
 *  
 * Destructor of the class snort.
 */
snort::~snort(void)
{
    //Customize if needed
}

/** 
 * @brief Initializes the plugin.
 * 
 * This method gets the Snort's log file from the map of properties. Then
 * it checks that the file exists and gets the current date.
 * @param properties Properties of the plugin.
 * 
 * @return True if the initialization was correct and false if it was not.
 */
bool snort::initialize_plugin(std::map<std::string, std::string> properties)
{
    log_file_ = properties["log_file"];
    
    ifstream file(log_file_.c_str());
    if(!file) {
	cerr << "Log file does not exist or your user cannot read it" << endl;
	return false;
    }
    file.close();

    sigar_open(&sig_);

    sigar_net_info_t net_info;
    sigar_net_info_get(sig_, &net_info);
    
    strcpy(hostname_,net_info.host_name);

    
    //Setting today's date
    time_t rawtime;
    struct tm * timeinfo;
    
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );	
    latest_date_.mon = timeinfo->tm_mon + 1;
    latest_date_.mday = timeinfo->tm_mday;
    latest_date_.hour = timeinfo->tm_hour;
    latest_date_.min = timeinfo->tm_min;
    latest_date_.sec = timeinfo->tm_sec;
    
    this_year_ = timeinfo->tm_year;
    
    
    return true;

}


/** 
 * @brief Updates the alert map with new alerts from log file.
 * 
 * Reads the log file looking for new alerts, if it finds new alerts, 
 * it stores them in  <code>alert_map_</code>.
 */
void snort::update_alertsmap()
{
  
    ifstream file(log_file_.c_str());
  
    string line;
    vector<string> alert;
    char buf;
    bool first_time = true;
  
    file.seekg(0,ios::beg);
    ifstream::pos_type pos_beg = file.tellg();
    file.seekg(0,ios::end);
    ifstream::pos_type pos_end = file.tellg();
    
    //Reposition the file pointer to the last byte in the file
    file.seekg(-1,ios::end);

  
    date next_latest_date = latest_date_;
  
    //Processing newer alerts from snort's alert.csv
    if(pos_beg != pos_end) { //Checks if the file is not empty
	while(file.tellg() != pos_beg) { //Checks whether there are more lines

	    buf = (char ) (file.peek());

	    if(buf != '\n') { //Skips '\n'
		line += buf;
	    }

	    else if(!line.empty()) { //Skips empty lines
		reverse(line.begin(),line.end());

		std::vector<std::string> strs;
		strs = split_string(line,',');
		

		if(strs.size()==26 ||strs.size()==27) { //Checks that the line is OK
		    if(is_newer(strs[0])) { //Checks alos that the alert is newer
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
			alert_map_[strs[0]] = aux;
			if(first_time) { //Stores the timestamp of the latest alert
			    next_latest_date = get_date_from_timestamp(strs[0]);
			    next_latest_date.sec += 1;
			    first_time = false;
			}
			// if(first_line == true)
			//     end = true;
		    }
		    else {
			file.close();
			latest_date_ = next_latest_date;
			return;
		    }
		}
      

		line.clear();      
		
		
	    }

	    file.seekg(-1,ios::cur); //Next line (line-1)
	}
    }
    file.close();

    // Changes the timestamp of the latest alert
    latest_date_ = next_latest_date;

}


/** 
 * @brief Returns a date structure given a string timestamp.
 * 
 * Returns a date structure given a string timestamp.
 * @param timestamp The timestamp we want to transform.
 * 
 * @return Timestamp in a date structure.
 */
date snort::get_date_from_timestamp(string timestamp)
{

    vector<string> vec;
    date dat;
  
    //Getting month
    vec = split_string(timestamp,'/');
    dat.mon = atoi(vec[0].c_str());
    //Getting month day
    vec = split_string(vec[1],'-');
    dat.mday = atoi(vec[0].c_str());
    //Getting hour, minute and second
    vec = split_string(vec[1],'.');
    vec = split_string(vec[0],':');
    dat.hour = atoi(vec[0].c_str());
    dat.min = atoi(vec[1].c_str());
    dat.sec = atoi(vec[2].c_str());
  
    
    return dat;
}


/** 
 * Checks if a alert is newer than the latest alert sent.
 * 
 * Checks if the timestamp of the alert is newer than the 
 * latest alert sent timestamp.
 * @param timestamp Timestamp of the read alert.
 * 
 * @return True if it is newer or false if it is not.
 */
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
    if(latest_date_.mon == timestamp_date.mon &&		      \
       latest_date_.mday == timestamp_date.mday  &&		      \
       latest_date_.hour < timestamp_date.hour)
	return true;
    //Newer min           	
    if(latest_date_.mon == timestamp_date.mon &&		      \
       latest_date_.mday == timestamp_date.mday  &&		      \
       latest_date_.hour == timestamp_date.hour  &&		      \
       latest_date_.min < timestamp_date.min)
	return true;
    //Newer sec		
    if(latest_date_.mon == timestamp_date.mon &&		       \
       latest_date_.mday == timestamp_date.mday  &&		       \
       latest_date_.hour == timestamp_date.hour  &&		       \
       latest_date_.min == timestamp_date.min    &&		       \
       latest_date_.sec <= timestamp_date.sec)
	return true;
  
    return false;
  
}


/** 
 * @brief Gets new alerts from Snort's logfile using update_alertsmap() and publishes them.
 * 
 * Gets new alerts from Snort's logfile using update_alertsmap() and publishes them
 * if they are found.
 * @param writer DDS Dynamic DataWriter.
 * @param data DDS Dynamic DataWriter to fill--using DDS Dynamic Data methdos.
 * 
 * @return True if everything was good.
 */
bool snort::generate_and_publish_information(DDSDynamicDataWriter *writer,
					     DDS_DynamicData *data)
{

    DDS_DynamicData *source_node_info_t_data =
	new DDS_DynamicData(NULL, DDS_DYNAMIC_DATA_PROPERTY_DEFAULT);
    DDS_DynamicData *target_node_info_t_data =
	new DDS_DynamicData(NULL, DDS_DYNAMIC_DATA_PROPERTY_DEFAULT);


    update_alertsmap();
    
    if(!alert_map_.empty()) {
	
	// Filling Host Information--------------------------------------------------
	
	
	data->set_string("hostname",
			 DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED,
			 hostname_);
	

	map<string,struct ids_alert_without_timestamp>::iterator it;
	for(it = alert_map_.begin(); it != alert_map_.end(); ++it) {
	  	  
	    //Information related to the source of the alert
	    data->bind_complex_member(*source_node_info_t_data, "source",
				      DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED);
	  
	    source_node_info_t_data->set_long("prt",
					      DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED,
					      atoi(it->second.srcport.c_str()));

	    source_node_info_t_data->set_string("network_addr",
						DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED,
						(char*)it->second.src.c_str());

	    source_node_info_t_data->set_string("mac",
						DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED,
						(char*)it->second.ethsrc.c_str());

	    data->unbind_complex_member(*source_node_info_t_data);
	    


	    //Information related to the target of the alert
	    data->bind_complex_member(*target_node_info_t_data, "target",
				      DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED);

	    target_node_info_t_data->set_long("prt",
					      DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED,
					      atoi(it->second.dstport.c_str()));
	  
	    target_node_info_t_data->set_string("network_addr",
						DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED,
						(char*) it->second.dst.c_str());
	  
	    target_node_info_t_data->set_string("mac",
						DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED,
						(char*)it->second.ethdst.c_str());


	    data->unbind_complex_member(*target_node_info_t_data);



	    //Timestamp of the alert
	    struct date aux = get_date_from_timestamp(it->first);
	  

	    struct tm *timeinfo_aux;
	    time_t rawtime;
	    time(&rawtime);
	    
	    timeinfo_aux = localtime ( &rawtime );
	    timeinfo_aux->tm_year = this_year_;
	    timeinfo_aux->tm_mon = aux.mon -1;
	    timeinfo_aux->tm_mday = aux.mday;
	    timeinfo_aux->tm_hour = aux.hour;
	    timeinfo_aux->tm_min = aux.min;
	    timeinfo_aux->tm_sec = aux.sec;
	    rawtime = mktime(timeinfo_aux);

	    data->set_long("ts",
			   DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED,
			   rawtime);
			   

	    //Alert message
	    data->set_string("msg",
			     DDS_DYNAMIC_DATA_MEMBER_ID_UNSPECIFIED,
			     (char*) it->second.msg.c_str());

	    
	    
	    publish_information(writer, data);
	}
	
	alert_map_.clear();	
	
    }
    
    return true;
}


/** 
 * @brief It splits an string in newer strings given a char.
 * 
 * Divides a string in substrings according to the appearance of a character. It 
 * stores the resulting strings in a <code>std::vector</code> of strings.
 * @param str String to split.
 * @param element Division character.
 * 
 * @return A  <code>std::vector</code> of substrings.
 */
vector<string> snort::split_string(string str, char element)
{
    
    istringstream str_to_split(str);
    vector<string> tokens;
    string aux_string;
    
    while(getline(str_to_split,aux_string,element)) {
	tokens.push_back(aux_string);
    }
    
    return tokens;
}


