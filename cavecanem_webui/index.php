<?php
require_once("./ui/ui.php");
require_once("./plugins/cpu.php");
require_once("./plugins/memory.php");
require_once("./plugins/disk.php");
require_once("./plugins/net_load.php");
require_once("./plugins/ids.php");
require_once("./plugins/host_info.php");
require_once("./plugins/proc.php");
require_once("./plugins/proc_stat.php");



$ui = new ui;
$ui->print_header();


if(isset($_REQUEST['host'])) {

    $hostname = $_REQUEST['host'];
    
    //CPU (index.php?host=x&cpu=true
    if(isset($_REQUEST['cpu'])) {
	$ui->print_pathway($hostname,"cpu");
	$cpu = new cpu;
	list($data_map,$numeric_fields_array,$not_numeric_fields_array,$key_name) = $cpu->get_host_data_from_table_cpu($hostname);
	
	if(sizeof($data_map) > 0) {
	    $ui->open_host_table_all_data("cpu",$numeric_fields_array,
					  $not_numeric_fields_array,$hostname);
	    $ui->fill_host_table_all_data($data_map,$numeric_fields_array,
					  $not_numeric_fields_array, $key_name);
	    
	    $ui->close_table();
	}
    }

    //MEMORY (index.php?host=x&memory=true
    else if(isset($_REQUEST['memory'])) {
	$ui->print_pathway($hostname,"memory");
	$memory = new memory;
	list($data_map,$numeric_fields_array,$not_numeric_fields_array,$key_name) = 
	    $memory->get_host_data_from_table_memory($hostname);
	
	if(sizeof($data_map) > 0) {
	    $ui->open_host_table_all_data("memory",$numeric_fields_array,
					  $not_numeric_fields_array,$hostname);
	    $ui->fill_host_table_all_data($data_map,$numeric_fields_array,
					  $not_numeric_fields_array, $key_name);
	    
	    $ui->close_table();
	}
    }

    
    //DISK SCENARIO (index.php?host=x&disk=true
    else if(isset($_REQUEST['disk'])) {
    	$ui->print_pathway($hostname,"disk");
    	$disk = new disk;
    	list($data_map,$numeric_fields_array,$not_numeric_fields_array,$key_name) = $disk->get_host_data_from_table_disk($hostname);
    	if(sizeof($data_map) > 0) {
    	    $ui->open_host_table_all_data("disk",$numeric_fields_array,
    					  $not_numeric_fields_array,$hostname);
    	    $ui->fill_host_table_all_data($data_map,$numeric_fields_array,
    					  $not_numeric_fields_array, $key_name);
	    
    	    $ui->close_table();
    	}

    }
    
    //NET LOAD SCENARIO (index.php?host=x&net_load=true
    else if(isset($_REQUEST['net_load'])){
    	$ui->print_pathway($hostname,"net_load");
    	$net_load = new net_load;
    	list($data_map,$numeric_fields_array,$not_numeric_fields_array,$key_name) = $net_load->get_host_data_from_table_net_load($hostname);
    	if(sizeof($data_map) > 0) {
    	    $ui->open_host_table_all_data("net_load",$numeric_fields_array,
    				     $not_numeric_fields_array,$hostname);
    	    $ui->fill_host_table_all_data($data_map,$numeric_fields_array,
    					  $not_numeric_fields_array, $key_name);
	    
    	    $ui->close_table();
    	}

    }

    //PROC_STAT SCENARIO(index.php?host=x&proc_stat=true
    else if(isset($_REQUEST['proc_stat'])) {
	$ui->print_pathway($hostname,"proc_stat");
	$proc_stat = new proc_stat;
	list($data_map,$numeric_fields_array,$not_numeric_fields_array,$key_name) = 
	    $proc_stat->get_host_data_from_table_proc_stat($hostname);
	
	if(sizeof($data_map) > 0) {
	    $ui->open_host_table_all_data("proc_stat",$numeric_fields_array,
					  $not_numeric_fields_array,$hostname);
	    $ui->fill_host_table_all_data($data_map,$numeric_fields_array,
					  $not_numeric_fields_array, $key_name);
	    
	    $ui->close_table();
	}
    }


    //PROC SCENARIO(index.php?host=x&proc=true
    else if(isset($_REQUEST['proc'])){
	$ui->print_pathway($hostname,"proc");
	$proc = new proc;
	list($data_map,$not_numeric_fields_array) =
	    $proc->get_host_data_from_table_proc($hostname);

	if(sizeof($data_map) > 0) {
	    $ui->open_not_numeric_table("proc",$not_numeric_fields_array,
					$hostname);
	    $ui->fill_not_numeric_table_host_data($data_map,
						  $not_numeric_fields_array,$hostname);
	    $ui->close_table();
	}

    }

    //IDS ALERT SCENARIO (index.php?host=x&ids_alerts=true
    else if(isset($_REQUEST['ids_alerts'])){
	$ui->print_pathway($hostname,"ids_alerts");
	$ids_alert = new ids_alert;
	list($data_map,$not_numeric_fields_array) = 
	    $ids_alert->get_host_data_from_table_ids_alert($hostname,-1);
	
	if(sizeof($data_map) > 0) {
	    $ui->open_not_numeric_table("ids_alerts",$not_numeric_fields_array,
					"");
	    $ui->fill_not_numeric_table_host_data($data_map, 
						  $not_numeric_fields_array,$hostname);
	    $ui->close_table();
	}
    }
    
    
    //SINGLE HOST SCENARIO (index.php?host=x)
    else {
	$ui->print_pathway($hostname,"");
	
	$host_info = new host_info;
	$host_info->print_host_info($hostname);

	$cpu = new cpu;
	list($data_map,$numeric_fields_array,$not_numeric_fields_array,$key_name) = $cpu->get_host_data_from_table_cpu($hostname);
	
	if(sizeof($data_map) > 0) {
	    $ui->open_host_table_single_data("cpu",$numeric_fields_array,
					     $not_numeric_fields_array,$hostname);
	    $ui->fill_host_table_single_data($data_map,$numeric_fields_array,
					     $not_numeric_fields_array, $key_name);
	    
	    $ui->close_table();
	    $ui->draw_plugin_without_devices_host_info("cpu",$data_map,$numeric_fields_array);
	}

	$memory = new memory;
	list($data_map,$numeric_fields_array,$not_numeric_fields_array,$key_name) = $memory->get_host_data_from_table_memory($hostname);
	
	if(sizeof($data_map) > 0) {
	    $ui->open_host_table_single_data("memory",$numeric_fields_array,
					     $not_numeric_fields_array,$hostname);
	    $ui->fill_host_table_single_data($data_map,$numeric_fields_array,
					     $not_numeric_fields_array, $key_name);
	    
	    $ui->close_table();
	    $ui->draw_plugin_without_devices_host_info("memory",$data_map,$numeric_fields_array);
	}

	
    	$disk = new disk;
    	list($data_map,$numeric_fields_array,$not_numeric_fields_array, $key_name) =
    	    $disk->get_host_data_from_table_disk($hostname);
    	if(sizeof($data_map) > 0) {
    	    $ui->open_host_table_single_data("disk",
    					     $numeric_fields_array,
    					     $not_numeric_fields_array,
    					     $hostname);
    	    $ui->fill_host_table_single_data($data_map,$numeric_fields_array,
    					     $not_numeric_fields_array,
    					     $key_name);
	    
    	    $ui->close_table();
    	    $ui->draw_plugin_with_devices_host_info("disk",$data_map,$numeric_fields_array);
    	}
	
    	$net_load = new net_load;
    	list($data_map,$numeric_fields_array,$not_numeric_fields_array, $key_name) =
    	    $net_load->get_host_data_from_table_net_load($hostname);
    	if(sizeof($data_map) > 0) {
    	    $ui->open_host_table_single_data("net_load",
    					     $numeric_fields_array,
    					     $not_numeric_fields_array,
    					     $hostname);
    	    $ui->fill_host_table_single_data($data_map,$numeric_fields_array,
    					     $not_numeric_fields_array,
    					     $key_name);
	    
    	    $ui->close_table();
    	    $ui->draw_plugin_with_devices_host_info("net_load",$data_map,
    						    $numeric_fields_array);
    	}


	$proc_stat = new proc_stat;
	list($data_map,$numeric_fields_array,$not_numeric_fields_array,$key_name) = 
	    $proc_stat->get_host_data_from_table_proc_stat($hostname);
	
	if(sizeof($data_map) > 0) {
	    $ui->open_host_table_single_data("proc_stat",$numeric_fields_array,
					     $not_numeric_fields_array,$hostname);
	    $ui->fill_host_table_single_data($data_map,$numeric_fields_array,
					     $not_numeric_fields_array, $key_name);
	    
	    $ui->close_table();
	    $ui->draw_plugin_without_devices_host_info("proc_stat",$data_map,$numeric_fields_array);
	}


	$proc = new proc;
	list($data_map,$not_numeric_fields_array) =
	    $proc->get_host_data_from_table_proc($hostname,15);

	if(sizeof($data_map) > 0) {
	    $ui->open_not_numeric_table("proc",$not_numeric_fields_array,
					$hostname);
	    $ui->fill_not_numeric_table_host_data($data_map,
						  $not_numeric_fields_array,$hostname);
	    $ui->close_table();
	}


	$ids_alert = new ids_alert;
	list($data_map,$not_numeric_fields_array) =
	    $ids_alert->get_host_data_from_table_ids_alert($hostname,5);

	if(sizeof($data_map) > 0) {
	    $ui->open_not_numeric_table("ids_alerts",$not_numeric_fields_array,
					$hostname);
	    $ui->fill_not_numeric_table_host_data($data_map,
						  $not_numeric_fields_array,$hostname);
	    $ui->close_table();
	}
	
    }
    
}

//HOME SCENARIO (index.php)
else {
  $ui->print_pathway("","");

    $cpu = new cpu;
    list($data_map,$numeric_fields_array) = $cpu->get_all_data_from_table_cpu();
    if(sizeof($data_map) > 0) {
    	$ui->open_table("cpu",$numeric_fields_array);
    	$ui->close_table();
    	$ui->draw_plugin_without_devices_overall_info("cpu",$data_map,$numeric_fields_array);
    }

    $memory = new memory;
    list($data_map,$numeric_fields_array) = $memory->get_all_data_from_table_memory();
    if(sizeof($data_map) > 0) {
    	$ui->open_table("memory",$numeric_fields_array);
    	$ui->close_table();
    	$ui->draw_plugin_without_devices_overall_info("memory",$data_map,$numeric_fields_array);
    }

	
    $disk = new disk;
    list($data_map,$numeric_fields_array) = $disk->get_all_data_from_table_disk();
    if(sizeof($data_map) > 0) {
    	$ui->open_table("disk",$numeric_fields_array);
    	$ui->close_table();
    	$ui->draw_plugin_with_devices_overall_info("disk",$data_map,$numeric_fields_array);
    }
    
    $nl = new net_load;
    list($data_map,$numeric_fields_array) = $nl->get_all_data_from_table_net_load();
    if(sizeof($data_map) > 0) {
    	$ui->open_table("net_load",$numeric_fields_array, true);
    	$ui->close_table();
    	$ui->draw_plugin_with_devices_overall_info("net_load",$data_map,$numeric_fields_array);
    }

    $proc_stat = new proc_stat;
    list($data_map,$numeric_fields_array) = 
	$proc_stat->get_all_data_from_table_proc_stat();
    if(sizeof($data_map) > 0) {
    	$ui->open_table("proc_stat",$numeric_fields_array);
    	$ui->close_table();
    	$ui->draw_plugin_without_devices_overall_info("proc_stat",$data_map,$numeric_fields_array);
    }


    $ids_alert = new ids_alert;
    list($data_map,$not_numeric_fields_array) =
    	$ids_alert->get_all_data_from_table_ids_alert(5);
    if(sizeof($data_map) > 0) {
    	    $numeric_fields_array = array();
	    
    	    $ui->open_not_numeric_table("ids_alerts", $not_numeric_fields_array,"");
    	    $ui->fill_not_numeric_table_all_data($data_map, $not_numeric_fields_array, true);
    	    $ui->close_table();
    }
    
    
}


$ui->print_bottom();


?>

