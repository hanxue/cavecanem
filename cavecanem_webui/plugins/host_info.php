<?php

require_once("./db/db_manager.php");


class host_info {

    function print_host_info($hostname) 
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
	
	$result = mysql_query("SELECT * FROM host_info  WHERE hostname\$str='$hostname'");

	$row = mysql_fetch_array($result);

	$value = $row['uptime'];
	      	  $d = $value / 86400 % 7;
                  $h = $value / 3600 % 24;
	      	  $m = $value / 60 % 60;
	      	  $se = $value % 60;
	      	  $uptime = $d . "d " . $h . "h" . $m . "m" .  $se . "s";




	if($row['sys_name$str'] == "Win32") {
	    echo "<h1>" . $hostname . "</h1>";
	    echo "<img src=\"images/Free_Windows_Logo64x64.png\" align=\"left\" alt=\"windows\">";
	    echo "<h2>" . $row['sys_description$str'] . "</h2>";

	    echo $row['sys_name$str'] . " " .  $row['sys_version$str'] . "&mdash;" . $row['sys_arch$str'];
	    echo "<br>uptime: $uptime";

	    echo "<div id=\"host_info\" style=\"width:790px;height:30px;\"></div>\n";

	}
	else if($row['sys_name$str'] == "Linux") {
            echo "<h1>" . $hostname . "</h1>";
	    echo "<img src=\"images/linux-logo.png\" align=\"left\" alt=\"windows\">";
	    echo "<h2>" . $row['sys_description$str'] . "</h2>";

	    echo $row['sys_name$str'] . " " .  $row['sys_version$str'] . "&mdash;" . $row['sys_arch$str'];
	    echo "<br>uptime: $uptime";
	    echo "<div id=\"host_info\" style=\"width:790px;height:30px;\"></div>\n";
	
	}


    }


}

?>
