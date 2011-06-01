<?php

require_once("./db/db_manager.php");

class disk {


  /**
   * @brief Gets all the information needed from the table disk.
   *
   * Takes all the information from the database and organizes it in a map of
   * data. It also extracts the numeric fields of the table to ease the representation
   * of data in charts.
   * @return Returns a map with all the data, and a list with the numeric fields
   */
    function get_all_data_from_table_disk()
    {
      list($db_host,$db_name,$db_user_name,$db_user_password) = get_db_configuration();
      
      //Result of the query stored in a map of maps
      $data_map;
      $hostname = "";
      $name="";
      $connection = mysql_connect($db_host,$db_user_name,$db_user_password);
      $numeric_fields_array = array();
      
      /* if(!$connection) { */
      /* 	die("Could not connect " . mysql_error()); */
      /* } */
      
      $bd = mysql_select_db($db_name,$connection);
      
      $result = mysql_query("SELECT * FROM disk ORDER BY hostname\$str, RTIRTC_HISTORY_ORDER DESC");
	/* if(!$result) { */
	/*     die("(disk) Error in query: " . mysql_error()); */
	/* } */
      
      
      while($row = mysql_fetch_array($result)) {

	$hostname = $row['hostname$str'];
	$name = $row['name$str'];
	$name = str_replace('\\','/',$name);
	foreach($row as $key => $value) {
	  if(!is_int($key) && $value != $hostname && $value != $name) {
	      $value_str = "$value";
	      if(substr_count($value_str,'.') == 1) {
		  $data_map[$hostname][$name][$key][] =  number_format($value,2,'.','');
	      }
	      else {
		  $data_map[$hostname][$name][$key][] = $value;
	      }
	  }
	}
      }

    	$fields = mysql_num_fields($result);

    	//Get numeric fields of the table
    	for ($i=0; $i < $fields; $i++) {
    	    $field_type = mysql_field_type($result, $i);
    	    $field_name = mysql_field_name($result,$i);
	    if($field_name == 'used' || $field_name == 'free') {
		$aux_numeric = array($field_name,"KB");
		array_push($numeric_fields_array,$aux_numeric);
    	    }
	    else if($field_name == 'used_per' || $field_name == 'free_per') {
		$aux_numeric = array($field_name,"%");
		array_push($numeric_fields_array,$aux_numeric);
	    }
    	}

    
    	mysql_close($connection);

    	//Returns both data_map and numeric_fields_array
    	return array($data_map,$numeric_fields_array);

    }

    function get_host_data_from_table_disk($hostname)
    {

      list($db_host,$db_name,$db_user_name,$db_user_password) = get_db_configuration();

      //Result of the query stored in a map of maps
      $data_map;
      $name="";
      $connection = mysql_connect($db_host,$db_user_name,$db_user_password);
      $numeric_fields_array = array();

      /* if(!$connection) { */
      /* 	die("Could not connect " . mysql_error()); */
      /* } */
      
      $bd = mysql_select_db($db_name,$connection);
      
      $result = mysql_query("SELECT * FROM disk WHERE hostname\$str='$hostname' ORDER BY RTIRTC_HISTORY_ORDER DESC");
      /* if(!$result) { */
      /* 	  die("(disk) Error in query: " . mysql_error()); */
      /* } */
	

      while($row = mysql_fetch_array($result)) {
    	$name = $row['name$str'];
	$name = str_replace('\\','/',$name);
	foreach($row as $key => $value) {
	  if(!is_int($key) && $value != $hostname && $value != $name) {
	      $value_str = "$value";
	      if(substr_count($value_str,'.') == 1) {
		  $data_map[$name][$key][] = number_format($value,2,'.','');
	      }
	      else {
		  $data_map[$name][$key][] = $value;
	      }
	  }
	}
      }
	
      $not_numeric_fields_array = array();
      $fields = mysql_num_fields($result);
      
      //Get numeric fields of the table
      for ($i=0; $i < $fields; $i++) {
	$field_type = mysql_field_type($result, $i);
	$field_name = mysql_field_name($result,$i);
	if($field_name == 'used' || $field_name == 'free') {
	    $aux_numeric = array($field_name,"KB");
	    array_push($numeric_fields_array,$aux_numeric);
	}
	else if($field_name == 'used_per' || $field_name == 'free_per') {
	    $aux_numeric = array($field_name,"%");
	    array_push($numeric_fields_array,$aux_numeric);
	}
	else if($field_name == 'blocks_written' || $field_name == 'blocks_read') {
	    $aux_numeric = array($field_name,"blks");
	    array_push($numeric_fields_array,$aux_numeric);
	}
	
	else if($field_name == 'name$str' ||
		$field_name == 'mountdir$str') {
	    $splited_str = explode('$',$field_name);
	    $field_name == $splited_str[0];
	    array_push($not_numeric_fields_array, $field_name);
	}
      }
      
      
      mysql_close($connection);
      
      //Returns both data_map and numeric_fields_array
      return array($data_map,$numeric_fields_array,
		   $not_numeric_fields_array, "name\$str");
      
    }
    


}

?>
