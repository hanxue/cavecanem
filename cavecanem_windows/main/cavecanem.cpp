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

#include <iostream>
#include <signal.h>
#include <cstdlib>

#include <ndds/dds_c/dds_c_xml.h>
#include <ndds/osapi/osapi_library.h>
#include <ndds/ndds_cpp.h>

#include "plugin_manager.hpp"


using namespace std;

void signal_handler(int signal);
bool quit_signal = false;

int main()
{
    //First we add Sigar library to the PATH
    _putenv("PATH=./shared/hyperic_sigar-1.6.4/lib");

    //This is the default configuration file
    string cfg_file("./config/cavecanem.xml");
    
    plugin_manager *manager;
    
    //Associate signals to the signal handler
    signal(SIGTERM, signal_handler); //Terminate
    signal(SIGINT,  signal_handler); //Interrupt
    signal(SIGABRT, signal_handler); //Abort
   
    try {
		manager = new plugin_manager(cfg_file);
    }
    catch(exception &e) {
		cerr << e.what() << endl;
		return 0;
    }

    cout << "Starting Cave Canem Publisher..." << endl;

    //We publish information and terminate in case of receiving a quit signal
    while(!quit_signal) {
		manager->publish_plugins_information();
    }
    
    delete(manager);

    return 1;
}

/** 
 * @brief Receives OS signals and orders the main() function to quit.
 * 
 * Sets the <code>quit_signal</code> global variable to true to stop the publishing loop.
 * @param signal Number of the signal.
 */
void signal_handler(int signal)
{
    cerr << "Received (Signal " << signal << "), ...";
    cerr << " Terminating program" << endl;
    quit_signal = true;
}

