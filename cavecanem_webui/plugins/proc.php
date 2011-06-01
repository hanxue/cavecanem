<?php

require_once("./db/db_manager.php");

class proc {


    function get_host_data_from_table_proc($hostname, $limit)
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
 	    $result = mysql_query("SELECT * FROM proc WHERE hostname\$str='$hostname' ORDER BY cpu_percent DESC LIMIT $limit");
	}
	else {
	    $result = mysql_query("SELECT * FROM proc WHERE hostname\$str='$hostname' ORDER BY cpu_percent DESC");
	}

	/*if(!$result) {*/
	/*    die("(proc) Error in query: " . mysql_error());*/
	/*}*/
	
    	while($row = mysql_fetch_array($result)) {
	    $data_map[$hostname]['pid'][] = $row['pid'];
	    $data_map[$hostname]['name'][] = $row['name$str'];
	    $data_map[$hostname]['mem_size (KB)'][] = $row['mem_size'];
	    $data_map[$hostname]['mem_resident (KB)'][] = $row['mem_resident'];
	    $data_map[$hostname]['mem_share (KB)'][] = $row['mem_share'];
	    $data_map[$hostname]['cpu_percent'][] = 
		number_format($row['cpu_percent'], 2, '.', '');
	    $data_map[$hostname]['user'][] = $row['user$str'];
	    $data_map[$hostname]['group'][] = $row['group$str'];
	
	}
	
    	$fields = mysql_num_fields($result);
    	$not_numeric_fields_array = array();
	array_push($not_numeric_fields_array, 'pid');
	array_push($not_numeric_fields_array, "name");
	array_push($not_numeric_fields_array, "mem_size (KB)");
	array_push($not_numeric_fields_array, "mem_resident (KB)");
	array_push($not_numeric_fields_array, "mem_share (KB)");
	array_push($not_numeric_fields_array, "cpu_percent");
	array_push($not_numeric_fields_array, "user");
	array_push($not_numeric_fields_array, "group");
	


    	mysql_close($connection);

    	return array($data_map,$not_numeric_fields_array);

    }

}


?>
