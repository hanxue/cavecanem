<?php

require_once("./db/db_manager.php");

class ids_alert {

    function get_all_data_from_table_ids_alert($limit)
    {
    	list($db_host,$db_name,$db_user_name,$db_user_password) = get_db_configuration();
	
    	//Result of the query stored in a map of maps
    	$data_map;
    	$hostname = "";
    	$name="";
    	$connection = mysql_connect($db_host,$db_user_name,$db_user_password);
	$not_numeric_fields_array = array();
    	/* if(!$connection) { */
    	/*     die("Could not connect " . mysql_error()); */
    	/* } */

    	$bd = mysql_select_db($db_name,$connection);
	
	if($limit > 0)
	    $result = mysql_query("SELECT * FROM ids_alert ORDER BY hostname\$str, RTIRTC_HISTORY_ORDER DESC LIMIT $limit");
	else {
	    $result = mysql_query("SELECT * FROM ids_alert ORDER BY hostname\$str, RTIRTC_HISTORY_ORDER DESC");
	}

	/* if(!$result) { */
	/*     die("(ids_alert) Error in query: " . mysql_error()); */
	/* } */
	
    	while($row = mysql_fetch_array($result)) {
    	    foreach($row as $key => $value) {
		if($key == 'host$hostname$str') {
		    $data_map['hostname'][] = $value;
		}
		else if($key == 'ts') {
		    $data_map['timestamp (UTC)'][] = $value;
		}
		else if($key == 'msg$str') {
		    $data_map['alert'][] = $value;
		}
		else if($key == 'source$network_addr$str') {
		    $data_map['src_net'][] = $value;
		}
		else if($key == 'source$prt') {
		    $data_map['src_port'][] = $value;
		}
		else if($key == 'source$mac$str') {
		    $data_map['src_mac'][] = $value;
		}
		else if($key == 'target$network_addr$str') {
		    $data_map['target_net'][] = $value;
		}
		else if($key == 'target$prt') {
		    $data_map['target_port'][] = $value;
		}
		else if($key == 'target$mac$str') {
		    $data_map['target_mac'][] = $value;
		}
	    }
	}

		
    	$fields = mysql_num_fields($result);
    	$not_numeric_fields_array = array();

	array_push($not_numeric_fields_array,"hostname");
	array_push($not_numeric_fields_array, "timestamp (UTC)");
	array_push($not_numeric_fields_array, "alert");
	array_push($not_numeric_fields_array, "src_net");
	array_push($not_numeric_fields_array, "src_port");
	array_push($not_numeric_fields_array, "src_mac");
	array_push($not_numeric_fields_array, "target_net");
	array_push($not_numeric_fields_array, "target_port");
	array_push($not_numeric_fields_array, "target_mac");

    	mysql_close($connection);

    	return array($data_map,$not_numeric_fields_array);

    }

    function get_host_data_from_table_ids_alert($hostname, $limit)
    {
    	list($db_host,$db_name,$db_user_name,$db_user_password) = get_db_configuration();
    	//Result of the query stored in a map of maps
    	$data_map;
    	$name="";
    	$connection = mysql_connect($db_host,$db_user_name,$db_user_password);
    	$numeric_fields_array = array();
	
    	/* if(!$connection) { */
    	/*     die("Could not connect " . mysql_error()); */
    	/* } */
	
    	$bd = mysql_select_db($db_name,$connection);
	
	if($limit > 0) {
 	    $result = mysql_query("SELECT * FROM ids_alert WHERE hostname\$str='$hostname' ORDER BY RTIRTC_HISTORY_ORDER DESC LIMIT $limit");
	}
	else {
	    $result = mysql_query("SELECT * FROM ids_alert WHERE hostname\$str='$hostname' ORDER BY RTIRTC_HISTORY_ORDER DESC");
	}

	/* if(!$result) { */
	/*     die("(ids_alert) Error in query: " . mysql_error()); */
	/* } */
	
    	while($row = mysql_fetch_array($result)) {
    	    foreach($row as $key => $value) {
		if($key == 'host$hostname$str') {
		    $data_map[$hostname]['hostname'][] = $value;
		}
		else if($key == 'ts') {
		    $data_map[$hostname]['timestamp (UTC)'][] = $value;
		}
		else if($key == 'msg$str') {
		    $data_map[$hostname]['alert'][] = $value;
		}
		else if($key == 'source$network_addr$str') {
		    $data_map[$hostname]['src_net'][] = $value;
		}
		else if($key == 'source$prt') {
		    $data_map[$hostname]['src_port'][] = $value;
		}
		else if($key == 'source$mac$str') {
		    $data_map[$hostname]['src_mac'][] = $value;
		}
		else if($key == 'target$network_addr$str') {
		    $data_map[$hostname]['target_net'][] = $value;
		}
		else if($key == 'target$prt') {
		    $data_map[$hostname]['target_port'][] = $value;
		}
		else if($key == 'target$mac$str') {
		    $data_map[$hostname]['target_mac'][] = $value;
		}
	    }
	}

	
    	$fields = mysql_num_fields($result);
    	$not_numeric_fields_array = array();
	array_push($not_numeric_fields_array, "timestamp (UTC)");
	array_push($not_numeric_fields_array, "alert");
	array_push($not_numeric_fields_array, "src_net");
	array_push($not_numeric_fields_array, "src_port");
	array_push($not_numeric_fields_array, "src_mac");
	array_push($not_numeric_fields_array, "target_net");
	array_push($not_numeric_fields_array, "target_port");
	array_push($not_numeric_fields_array, "target_mac");
	


    	mysql_close($connection);

    	return array($data_map,$not_numeric_fields_array);

    }

}


?>
