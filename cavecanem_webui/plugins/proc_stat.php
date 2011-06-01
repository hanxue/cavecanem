<?php

require_once("./db/db_manager.php");

class proc_stat {

    function get_all_data_from_table_proc_stat()
    {
    
      list($db_host,$db_name,$db_user_name,$db_user_password) = get_db_configuration();

	//Result of the query stored in a map of maps
	$data_map;
	$hostname = "";
	$name="";
	$connection = mysql_connect($db_host,$db_user_name,$db_user_password);
	$numeric_fields_array = array();

	/* if(!$connection) { */
	/*     die("Could not connect " . mysql_error()); */
	/* } */

	$bd = mysql_select_db($db_name,$connection);
	
	
        $result = mysql_query("SELECT * FROM proc_stat ORDER BY hostname\$str, RTIRTC_HISTORY_ORDER DESC");

	/* if(!$result) { */
	/*     die("(proc_stat) Error in query: " . mysql_error()); */
	/* } */
	
	while($row = mysql_fetch_array($result)) {
	    $hostname = $row['hostname$str'];
	    foreach($row as $key => $value) {
	       if(!is_int($key) && $value != $hostname) {
		   $value_str = "$value";
		   if(substr_count($value_str,'.') == 1) {
		       $data_map[$hostname][$key][] = number_format($value,2,'.','');
		   }
		   else {
		       $data_map[$hostname][$key][] = $value;
		   }		   
	       }
	    }	    
	}


	$fields = mysql_num_fields($result);

	//Get numeric fields of the table
	for ($i=0; $i < $fields; $i++) {
	    $field_type = mysql_field_type($result, $i);
	    $field_name = mysql_field_name($result,$i);
	    if($field_name == 'total' || $field_name == 'sleeping' ||
	       $field_name == 'runnnig' || $field_name == 'zombie' ||
	       $field_name == 'stopped' || $field_name == 'idle' ||
	       $field_name == 'threads') {
		$aux_numeric = array($field_name,"procs");
		array_push($numeric_fields_array, $aux_numeric);
	    }
	}
    
	mysql_close($connection);

	//Returns both data_map and numeric_fields_array
	return array($data_map,$numeric_fields_array);

    }

    function get_host_data_from_table_proc_stat($hostname)
    {

list($db_host,$db_name,$db_user_name,$db_user_password) = get_db_configuration();
    
      //Result of the query stored in a map of maps
      $data_map;
      $name="";
      $connection = mysql_connect($db_host,$db_user_name,$db_user_password);

      /* if(!$connection) { */
      /* 	die("Could not connect " . mysql_error()); */
      /* } */

      $bd = mysql_select_db($db_name,$connection);
	
      $result = mysql_query("SELECT * FROM proc_stat WHERE hostname\$str='$hostname' ORDER BY RTIRTC_HISTORY_ORDER DESC");

      /* if(!$result) { */
      /* 	  die("(cpu) Error in query: " . mysql_error()); */
      /* } */
      
      $real_values = array();
	       
      while($row = mysql_fetch_array($result)) {
	  foreach($row as $key => $value) {
	      if(!is_int($key) && $value != $hostname) {
		  $value_str = "$value";
		  if(substr_count($value_str,'.') > 0) {
		      $data_map[$key][] = number_format($value,2,'.','');
		  }
		  else {
		      $data_map[$key][] = $value;
		  }
	      }
	  }
      }


      $fields = mysql_num_fields($result);
      $numeric_fields_array = array();
      $not_numeric_fields_array = array();
      //Get numeric fields of the table
      for ($i=0; $i < $fields; $i++) {
	$field_type = mysql_field_type($result, $i);
	$field_name = mysql_field_name($result,$i);
	    if($field_name == 'total' || $field_name == 'sleeping' ||
	       $field_name == 'runnnig' || $field_name == 'zombie' ||
	       $field_name == 'stopped' || $field_name == 'idle' ||
	       $field_name == 'threads') {
	    $aux_numeric = array($field_name,"procs");
	    array_push($numeric_fields_array, $aux_numeric);
	    }
      }
	    
    
      mysql_close($connection);

      //Returns both data_map and numeric_fields_array
      return array($data_map,$numeric_fields_array,
		   $not_numeric_fields_array,"");

    }


}

?>
