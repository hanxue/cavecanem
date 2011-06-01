<?php

class ui {
    function print_header()
    {
echo <<<END
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="es-es" lang="es-es">
<head>
    <meta http-equiv="content-type" content="text/html; charset=ISO-8859-15" />
    <link rel="stylesheet" href="css/tema.css" type="text/css" />
    <link rel="shortcut icon" href="images/favicon.ico"/>
    <title>Cave Canem</title>
    <link href="css/layout.css" rel="stylesheet" type="text/css"></link>    
    <!--[if lte IE 8]><script language="javascript" type="text/javascript" src="js/excanvas.min.js"></script><![endif]-->
    <script language="javascript" type="text/javascript" src="js/jquery.js"></script>
    <script language="javascript" type="text/javascript" src="js/jquery.flot.js"></script>

  
</head>

<body style="background-color: rgb(51, 51, 51);">
<div id="wrapper"> <!-- Recorta el espacio de la web-->
    <div class="inside"> <!--Hace el borde gris de la pagina-->
        <div id="wrapper-inner"> <!-- Da el color blanco del interior -->
            <div class="inside">
                <div align="left" style="border:none;"><a href="index.php"><img src="images/cavecanem.png" height="120" width="500" alt="Cave Canem Logo"/></a></div>
                    <div id="elements"> <!-- Barra de arriba-->
                        <div class="clr"></div>
                    </div><!-- Fin Barra de arriba -->		    	
END;
    }
    
    function print_pathway($hostname,$sensor)
    {
        echo "<div class=\"pathway\">";
        if($hostname != "" && $sensor != "") {
            echo "<a href=\"index.php\">home</a> <img src=\"./images/pathway.png\"> <a href=\"index.php?host=$hostname\">$hostname</a> <img src=\"./images/pathway.png\"> $sensor";
        }
        else if($hostname != "") {
            echo "<a href=\"index.php\">home</a> <img src=\"./images/pathway.png\"> $hostname";
        }
        else {
            echo "home";
        }
        echo "</div>";
    }
    
    function print_menu()
    {

//Aquí hay que hacer la consulta para obtener los canales y añadirlos abajo
echo <<<END

                    <div id="navigation"> <!--Barra de navegacion -->
                        <div class="moduletable">
                            <ul id="mainlevel-nav">
                                <li>Mierda</li>
                            </ul>
                        </div>
			
                        <div class="clr"></div>
                    </div> <!-- Fin de la barra de navegacion -->


                    <div id="elements"> <!-- Barra de arriba-->
                        <div class="clr"></div>
                    </div><!-- Fin Barra de arriba -->
END;
    }


    function print_bottom()
    {
echo <<<END

                <!--</div>--><!-- Fin del cuerpo-->
                <div id="footer">
                    <div class="clr"></div>
                    <p>
                    <!--    <a href="http://validator.w3.org/check?uri=referer"><img
                            src="http://www.w3.org/Icons/valid-xhtml10"
                            alt="Valid XHTML 1.0 Transitional" height="31" width="88" /></a>
                    </p> -->
	        </div> <!-- Cierra el footer -->
        </div><!--Cierra inside -->
    </div> <!-- Cierra wrapper-inner -->

</div> <!--Cierra inside -->
</div> <!-- Cierra wrapper -->

</body>

</html>
END;
    }
    
    function init_script()
    {
echo <<<END

        <script id="source" language="javascript" type="text/javascript">
                $(function () {
                
END;
    }
    
    function end_script()
    {
echo <<<END

        });
        </script>

END;
    }

    function draw_plugin_with_devices_overall_info($table_name,$data_map, $numeric_fields_array)
    {
		
      /* $this->open_table($table_name,$numeric_fields_array,true);  */
      
      $labeler_div = $table_name . '_labeler';
      $separator_div = $table_name . '_separator';
      $chart_div = $table_name . '_chart';
      $choices_div = $table_name . '_choices';
	
      /* $this->close_table();       */
      //Labels and choices will appear here
	
      echo "<div id=\"$labeler_div\"></div>\n";
      echo "<div id=\"$separator_div\" style=\"width:790px;height:15px;\"></div>\n";
      echo "<div id=\"$chart_div\" style=\"width:790px;height:350px;\"></div>\n";
      echo "<div id=\"$choices_div\" class=\"scroll\"></div>\n";
      
      echo "<script type=\"text/javascript\">\n";
      echo "$(function () {\n";
      echo "var datasets = new Object(); \n\n";
      echo "var options = new Object();\n";
      echo "var current_option = \"\";";
      echo "var current_dataset;\n";
      echo "var current_field = \"\";\n";
      
      for($i = 0; $i < sizeof($numeric_fields_array); $i++) {
	$field = $numeric_fields_array[$i][0];
	$unit = $numeric_fields_array[$i][1];
	
	echo "datasets.$field = {\n";
	$label_color = 0;
	foreach($data_map as $key => $value) {
	    $last_key = end(array_keys($value_2));
	    foreach($value as $key_2 => $value_2) {
		$free_per_js = "";
		$j = 0;
		echo "\"$key;$key_2\": {";
		echo "label: \"$key;$key_2\",";
		echo "color: $label_color,";
		$label_color++;
		//Here we get the data
		foreach($data_map[$key][$key_2][$field] as $num) {
		    $free_per_js[] = array(intval($data_map[$key][$key_2]['ts'][$j])*1000, 
					   floatval($num));
		    $j++;
		}
		$data = json_encode($free_per_js);
		echo "data: $data}";
		if($key_2 != $last_key) {
 		    echo ",\n";
		}
		
	    }
	    
	}
       
	echo "\n};";
	
	echo "options.$field = {\n";
	echo "xaxis: {mode: \"time\", timeformat:\"%y-%m-%d %H:%M:%S\"},\n";
	echo "yaxis: {min:0, tickFormatter: function (v,axis) { return v.toFixed(axis.tickDecimals) + \" $unit\"; } },\n";
	echo "legend: {noColumns: 4, container: $(\"#$labeler_div\")}\n";
	echo "}\n";
	
	echo"\n$(\"#$field\").click(function () {\n";
	echo "current_dataset = datasets.$field;\n";
	echo "current_option = options.$field;\n";
	echo "current_field = \"$field\";";
	echo "plotAccordingToChoices();\n";
	echo "})\n";
      }
      
      $aux_field = $numeric_fields_array[0][0];
      echo "current_dataset = datasets.$aux_field;";
      echo "current_field = \"$aux_field\";";
      echo "current_option = options.$aux_field;\n";
      	
echo<<<END
    // hard-code color indices to prevent them from shifting as
    // countries are turned on/off
    
  
  var interfaces_array = [];
var current_host = "";

var i = -1;
var j = 0;

var max_i = 0;
var max_j = 0;

$.each(current_dataset, function(key, val) {
	var aux = key.split(";");
	/* document.write(aux); */
	if(current_host != aux[0]) {
	    current_host = aux[0];
	    j = 0;
	    i++;
	    interfaces_array[i] = [];
	    interfaces_array[i][j] = key; /* aux[1]; */
	    if(i > max_i) {
		max_i = i;
	    }	    
	}
	else {
	    interfaces_array[i][++j] = key;/* aux[1]; */
	    if(j > max_j) {
		max_j = j;
	    }

	}
    });



//Insert Checkboxes
var choiceContainer = $("#$choices_div");

//Begin checkboxes' table
choiceContainer.append('<table class="main"> <thead>');

//Hostnames are the head of the table
for(i = 0; i < interfaces_array.length; i++) {
    var th = interfaces_array[i][0].split(";");
    choiceContainer.append('<th>'+ '<a href="index.php?host='+ th[0] +
			   '">'+th[0]+'</a></th>');
}
choiceContainer.append('</thead>');


//Filling the tables with all the network interfaces
for(i = 0; i <= max_j; i++) {
    choiceContainer.append('<tr>');
    for(j = 0; j <= max_i; j++) {
	var c_key = interfaces_array[j][i];

	if(c_key != undefined) {
	    var l = c_key.split(";");
	    choiceContainer.append('<td> <input type="checkbox" name="' + c_key +
    				   '" checked="checked" id="id' + c_key + '">' +
    				   '<label for="id' + c_key + '">'
				   + l[1] + '</label> </td>');
	}
	else {
	    choiceContainer.append('<td></td>');
	}
    }
    choiceContainer.append('</tr>');
}
choiceContainer.append('</table>');


choiceContainer.find("input").click(plotAccordingToChoices); 


function plotAccordingToChoices() {
    var data = [];
    
    choiceContainer.find("input:checked").each(function () {
            var key = $(this).attr("name");
            if (key && current_dataset[key])
                data.push(current_dataset[key]);

        });
    
    if (data.length > 0)
	$.plot($("#$chart_div"), data, current_option);
    
    $("#$chart_div").append('<div style="font-size:11pt;position:absolute;right:' + 0 + 'px;top:' +  -23 + 'px;"><b>' + current_field + '</b></div>');
}
plotAccordingToChoices();

});

</script>
END;

}


function draw_plugin_with_devices_host_info($table_name,$data_map, $numeric_fields_array)
{
  
  /* $this->open_table($table_name,$numeric_fields_array,true);  */
  
  $labeler_div = $table_name . '_labeler';
  $separator_div = $table_name . '_separator';
  $chart_div = $table_name . '_chart';
  
  
  /* $this->close_table();       */
  //Labels and choices will appear here
  
  echo "<div id=\"$labeler_div\"></div>\n";
  echo "<div id=\"$separator_div\" style=\"width:790px;height:15px;\"></div>\n";
  echo "<div id=\"$chart_div\" style=\"width:790px;height:350px;\"></div>\n";
  
  echo "<script type=\"text/javascript\">\n";
  echo "$(function () {\n";
  echo "var datasets = new Object(); \n\n";
  echo "var options = new Object(); \n";
  echo "var current_option = \"\";";
  echo "var current_dataset;\n";
  echo "var current_field = \"\";\n";
    
  
  for($i = 0; $i < sizeof($numeric_fields_array); $i++) {

    $field = $numeric_fields_array[$i][0];
    $unit = $numeric_fields_array[$i][1];
	  
    echo "datasets.$field = {\n";
    $label_color = 0;
    $last_key = end(array_keys($data_map));
    foreach($data_map as $key => $value) {
      $free_per_js = "";
      $j = 0;
      echo "\"$key\": {";
      echo "label: \"$key\",";
      echo "color: $label_color,";
      $label_color++;
      //Here we get the data
      foreach($data_map[$key][$field] as $num) {
	  $free_per_js[] = array(intval($data_map[$key]['ts'][$j])*1000, floatval($num));
	$j++;
      }
      $data = json_encode($free_per_js);
      echo "data: $data}";
      
      if($key != $last_key) {
	echo ",\n";
      }
      
    }
    
    echo "\n};";

    echo "options.$field = {\n";
    echo "xaxis: {mode: \"time\", timeformat:\"%y-%m-%d %H:%M:%S\"},\n";
    echo "yaxis: {min:0, tickFormatter: function (v) { return v.toFixed(0) + \" $unit\"; } },\n";
    echo "legend: {noColumns: 4, container: $(\"#$labeler_div\")}\n";
    echo "};\n";
      

    echo"\n$(\"#$field\").click(function () {\n";
    echo "current_dataset = datasets.$field;\n";
    echo "current_field = \"$field\";\n";
    echo "current_option = options.$field;\n";
    echo "plotAccordingToChoices();\n";
    echo "})\n";
  }
  
  $aux_field = $numeric_fields_array[0][0];
  echo "current_dataset = datasets.$aux_field;";
  echo "current_field = \"$aux_field\";";
  echo "current_option = options.$aux_field;\n";
	
echo<<<END

function plotAccordingToChoices() {
    var data = [];

    $.each(current_dataset, function(key,val) {
	data.push(current_dataset[key]);
      });
    
    
    $.plot($("#$chart_div"), data, current_option);
    
    $("#$chart_div").append('<div style="font-size:11pt;position:absolute;right:' + 0 + 'px;top:' +  -23 + 'px;"><b>' + current_field + '</b></div>');
}
plotAccordingToChoices();

});

</script>
END;

}


function draw_plugin_without_devices_overall_info($table_name,$data_map, $numeric_fields_array)
{

  /* $this->open_table($table_name,$numeric_fields_array,true); */
  
  $labeler_div = $table_name . '_labeler';
  $separator_div = $table_name . '_separator';
  $chart_div = $table_name . '_chart';
  $choices_div = $table_name . '_choices';
  
  /* $this->close_table();       */
  //Labels and choices will appear here
  
  echo "<div id=\"$labeler_div\"></div>\n";
  echo "<div id=\"$separator_div\" style=\"width:790px;height:15px;\"></div>\n";
  echo "<div id=\"$chart_div\" style=\"width:790px;height:350px;\"></div>\n";
  echo "<div id=\"$choices_div\" class=\"scroll\"></div>\n";
  
  echo "<script type=\"text/javascript\">\n";
  echo "$(function () {\n";
  echo "var datasets = new Object(); \n\n";
  echo "var options = new Object(); \n";
  echo "var current_option = \"\";";
  echo "var current_dataset;\n";
  echo "var current_field = \"\";\n";
  

for($i = 0; $i < sizeof($numeric_fields_array); $i++) {

    $field = $numeric_fields_array[$i][0];
    $unit = $numeric_fields_array[$i][1];
	
    echo "datasets.$field = {\n";
    $label_color = 0;
    $last_key = end(array_keys($data_map));
    foreach($data_map as $key => $value) {

	$free_per_js = "";
	$j = 0;
	echo "\"$key\": {";
	echo "label: \"$key\",";
	echo "color: $label_color,";
	$label_color++;
	//Here we get the data
	foreach($data_map[$key][$field] as $num) {
	    $free_per_js[] = array(intval($data_map[$key]['ts'][$j])*1000, 
				   $num);
	    $j++;
	}
	$data = json_encode($free_per_js);
	echo "data: $data}";
	    
	if($key != $last_key) {
	    echo ",\n";
	}

    }

    echo "\n};\n";
    echo "options.$field = {\n";
    echo "xaxis: {mode: \"time\", timeformat:\"%y-%m-%d %H:%M:%S\"},\n";
    echo "yaxis: {min:0, tickFormatter: function (v,axis) { return v.toFixed(axis.tickDecimals) + \" $unit\"; } },\n";
    echo "legend: {noColumns: 4, container: $(\"#$labeler_div\")}\n";
    echo "};\n";

    echo"\n$(\"#$field\").click(function () {\n";
    echo "current_dataset = datasets.$field;\n";
    echo "current_field = \"$field\";\n";
    echo "current_option = options.$field;\n";
    echo "plotAccordingToChoices();\n";
    echo "})\n";
}

$aux_field = $numeric_fields_array[0][0];
echo "current_dataset = datasets.$aux_field;";
echo "current_field = \"$aux_field\";";
echo "current_option = options.$aux_field;\n";



echo<<<END
  // hard-code color indices to prevent them from shifting as
  // countries are turned on/off
  
  var interfaces_array = [];
var current_host = "";


//Insert Checkboxes
var choiceContainer = $("#$choices_div");

//Begin checkboxes' table
//choiceContainer.append('<div class="scroll">');
choiceContainer.append('<table class="main"> <thead>');


$.each(current_dataset, function(key, val) {
    choiceContainer.append('<th>'+ '<input type="checkbox" name="' + key +
			   '" checked="checked" id="id' + key + '">' +
			   '<label for="id' + key + '"> '
			   + '<a href="index.php?host='+ key +
			   '">'+ key +' </a></label></th>');
    });

choiceContainer.append('</thead><tbody></tbody></table><div id="' +
		       '$field_second_separator"style=\"height:15px\"></div>');

choiceContainer.find("input").click(plotAccordingToChoices); 

/* choiceContainer.append('</thead>'); */


/* choiceContainer.find("input").click(plotAccordingToChoices);  */


function plotAccordingToChoices() {
    var data = [];
    
    choiceContainer.find("input:checked").each(function () {
            var key = $(this).attr("name");
            if (key && current_dataset[key])
                data.push(current_dataset[key]);
        });
    
    if (data.length > 0)
	$.plot($("#$chart_div"), data, current_option);/*  /\* { *\/ */
	    /* /\* yaxis: { min: 0 }, *\/ */
	    /* /\* 	    xaxis: { mode: "time", timeformat:"%y-%m-%d %H:%M:%S" }, *\/ */
		    
	    /* /\* legend :{ *\/ */
	    /* /\* 	    /\\* noColumns: 2, *\\/ *\/ */
	    /* /\* 	    /\\* margin: [-230,0] *\\/ *\/ */
	    /* /\* 	noColumns: 8, *\/ */
	    /* /\* 		container: $("#$labeler_div") *\/ */
			
	    /* /\* 		} *\/ */
	    /* /\* } *\/); */
    
    $("#$chart_div").append('<div style="font-size:11pt;position:absolute;right:' + 0 + 'px;top:' +  -23 + 'px;"><b>' + current_field + '</b></div>');
}

plotAccordingToChoices();

});

</script>
END;

}

function draw_plugin_without_devices_host_info($table_name,$data_map, $numeric_fields_array)
{
  
  /* $this->open_table($table_name,$numeric_fields_array,true); */
  
  $labeler_div = $table_name . '_labeler';
  $separator_div = $table_name . '_separator';
  $chart_div = $table_name . '_chart';
  
  /* $this->close_table();       */
  //Labels and choices will appear here
  
  echo "<div id=\"$labeler_div\"></div>\n";
  echo "<div id=\"$separator_div\" style=\"width:790px;height:15px;\"></div>\n";
  echo "<div id=\"$chart_div\" style=\"width:790px;height:350px;\"></div>\n";

  echo "<script type=\"text/javascript\">\n";
  echo "$(function () {\n";
  echo "var datasets = new Object(); \n\n";
  echo "var options = new Object(); \n";
  echo "var current_option = \"\";";
  echo "var current_dataset;\n";
  echo "var current_field = \"\";\n";

  $label_color = 0;

  for($i = 0; $i < sizeof($numeric_fields_array); $i++) {
  
      $field = $numeric_fields_array[$i][0];
      $unit = $numeric_fields_array[$i][1];
      
      echo "datasets.$field = {\n";
      
      /* foreach($data_map as $key => $value) { */
      $last_key = end(array_keys($value));
      $free_per_js = "";
      $j = 0;
      echo "\"$field\": {";
      echo "label: \"$field\",";
      echo "color: $label_color,";
      //Here we get the data
      for($j = 0; $j < sizeof($data_map[$field]); $j++) {
	  $free_per_js[] = array(intval($data_map['ts'][$j])*1000, 
				 floatval($data_map[$field][$j]));
      }
      $data = json_encode($free_per_js);
      echo "data: $data}";
      
      /* if($key != $last_key) { */
      
      /* } */
      
      echo "\n};";
      
      echo "options.$field = {\n";
      echo "xaxis: {mode: \"time\", timeformat:\"%y-%m-%d %H:%M:%S\"},\n";
      echo "yaxis: {min:0, tickFormatter: function (v,axis) { return v.toFixed(axis.tickDecimals) + \" $unit\"; } },\n";
      echo "legend: {noColumns: 4, container: $(\"#$labeler_div\")}\n";
      echo "};\n";
      
      
      echo"\n$(\"#$field\").click(function () {\n";
      echo "current_dataset = datasets.$field;\n";
      echo "current_field = \"$field\";";
      echo "current_option = options.$field;\n";
      echo "plotAccordingToChoices();\n";
      echo "})\n";
  }

  $aux_field = $numeric_fields_array[0][0];
  echo "current_dataset = datasets.$aux_field;";
  echo "current_field = \"$aux_field\";";
  echo "current_option = options.$aux_field;\n";


echo<<<END

function plotAccordingToChoices() {
    var data = [];
    
    data.push(current_dataset[current_field]);

     /* document.write(data); */
    $.plot($("#$chart_div"), data, current_option);/* { */
      /* 	    yaxis: { min: 0 }, */
      /* 		xaxis: { mode: "time", timeformat:"%y-%m-%d %H:%M:%S"}, */
		
      /* 		legend :{ */
      /* 		/\* noColumns: 2, *\/ */
      /* 		/\* margin: [-230,0] *\/ */
      /* 	    noColumns: 8, */
      /* 		    container: $("#$labeler_div") */
	    
      /* 	    } */
      /* }); */
    
    $("#$chart_div").append('<div style="font-size:11pt;position:absolute;right:' + 0 + 'px;top:' +  -23 + 'px;"><b>' + current_field + '</b></div>');
}

plotAccordingToChoices();

});

</script>
END;

}


function open_table($table_name,$fields_array)
{
echo <<<END
    <table class="main">
    <caption>$table_name</caption>
    <thead>
    <tr>
END;

for($i=0; $i<sizeof($fields_array); $i++) {
    $aux_field = $fields_array[$i][0];
    echo "<th scope=\"col\"><a id=\"$aux_field\">$aux_field</a></th>";
}


echo <<<END
    </tr>
    </thead>
END;

}

function open_host_table_single_data($table_name, $numeric_fields_array, 
				     $not_numeric_fields_array,$hostname) 
{
echo<<<END
  <table class="main">
  <caption><a href="index.php?host=$hostname&$table_name=true">$table_name</a></caption>
  <thead>
  <tr>
END;

for($i = 0; $i < sizeof($not_numeric_fields_array); $i++) {
  $splited_str = explode('$str',$not_numeric_fields_array[$i]);
  echo "<th scope=\"col\">$splited_str[0]</th>\n";
}


for($i = 0; $i < sizeof($numeric_fields_array); $i++) {
    $aux_numeric_field = $numeric_fields_array[$i][0];
  echo "<th scope=\"col\"><a id=\"$aux_numeric_field\">$aux_numeric_field</th>\n";
}
echo "\n<tr>\n</thead>";
}

function open_host_table_all_data($table_name, $numeric_fields_array, 
				  $not_numeric_fields_array,$hostname)
{

echo<<<END
  <table class="main">
  <caption><a href="$table_name">$table_name</a></caption>
  <thead>
  <tr>
END;

echo "<th scope=\"col\">timestamp (UTC)</th>\n";
for($i = 0; $i < sizeof($not_numeric_fields_array); $i++) {
  $splited_str = explode('$str',$not_numeric_fields_array[$i]);
  /* $final_str = explode($splited_str[0],'_str'); */
  echo "<th scope=\"col\">$splited_str[0]</th>\n";
}

for($i = 0; $i < sizeof($numeric_fields_array); $i++) {
    $aux_numeric_field = $numeric_fields_array[$i][0];
    echo "<th scope=\"col\">$aux_numeric_field</th>\n";
}
echo "\n<tr>\n</thead>";


}


function fill_host_table_single_data($table_data,$numeric_fields_array, 
		    $not_numeric_fields_array, $key_name)
{
  echo "<tbody>";

  if($key_name != "" && $key_name != "none") {
    foreach($table_data as $key => $value) {
      echo "<tr>\n";
      echo "<td>$key</td>";
      foreach($not_numeric_fields_array as $key_2) {
	if($key_2 != $key_name) {
	  echo "<td>";
	  echo $value[$key_2][0];
	  echo "</td>";
	}
      }
      
      foreach($numeric_fields_array as $key_2) {
	echo "<td>";
	/* print_r($value[$key_2][0]); */
	echo $value[$key_2[0]][0];
	echo "</td>";
      }
    
      echo "\n</tr>";
    }
  }
  else {
    echo "<tr>";
    foreach($not_numeric_fields_array as $key_2) {
      if($key_2 != $key_name) {
	echo "<td>";
	echo $table_data[$key_2][0];
	echo "</td>";
      }
    }
    
    foreach($numeric_fields_array as $key_2) {
      echo "<td>";
      echo $table_data[$key_2[0]][0];

      echo "</td>";
    }
    echo "</tr>";
    
  }
  /* print($table_data["lo"]["hwaddress_str\$str"][0]); */
  /* foreach($table_data as $key => $value) { */
  /*   echo "<tr>\n"; */
  /*   for($i = 0; $i < sizeof($fields_array); $i++) { */
  /*     echo "<td>$value[eth0][name$str][0]</td>\n"; */
  /*   } */
  /*   echo "</tr>\n"; */
  /* } */
  echo "</tbody>";
}

function fill_host_table_all_data($table_data,$numeric_fields_array, 
				  $not_numeric_fields_array, $key_name)
{
  echo "<tbody>";
  date_default_timezone_set('UTC');
  $i = 0;
  $quit_loop = false;

  if($key_name != "" && $key_name != "none") {
      while($quit_loop == false) {
	  foreach($table_data as $key => $value) {
	      echo "<tr>\n";
	      echo "<td>\n";
	      echo date("Y-m-d H:i:s",$value["ts"][$i]);
	      echo "</td>\n";
	      echo "<td>$key</td>\n";
	      foreach($not_numeric_fields_array as $key_2) {
		  if($key_2 != $key_name) {
		      echo "<td>";
		      echo $value[$key_2][$i];
		      echo "</td>";
		  }
	      }
	      
	      foreach($numeric_fields_array as $key_2) {
		  echo "<td>";

		  if(sizeof($value[$key_2[0]]) == $i+1) {
		      $quit_loop = true;
		  }
		  
		  echo $value[$key_2[0]][$i];
		  echo "</td>";
	      }
	      
	      echo "\n</tr>";
	  }
	  $i++;
      }
  }
  else {
      while($quit_loop == false) {
	  echo "<tr>";
	  echo "<td>\n";
	  echo date("Y-m-d H:i:s",$table_data["ts"][$i]);
	  echo "</td>\n";
	  foreach($not_numeric_fields_array as $key_2) {
	      if($key_2 != $key_name) {
	      echo "<td>";
	      print_r ($table_data[$key_2][$i]);
	      echo "</td>";
	      }
	  }
	  
	  foreach($numeric_fields_array as $key_2) {
	      echo "<td>";
	      if(sizeof($table_data[$key_2[0]]) == $i+1) {
		  $quit_loop = true;
	      }
	      echo $table_data[$key_2[0]][$i];
	      echo "</td>";
	  }
	  echo "</tr>";				
	  $i++;
      }
      
  }
  /* print($table_data["lo"]["hwaddress_str\$str"][0]); */
  /* foreach($table_data as $key => $value) { */
  /*   echo "<tr>\n"; */
  /*   for($i = 0; $i < sizeof($fields_array); $i++) { */
  /*     echo "<td>$value[eth0][name$str][0]</td>\n"; */
  /*   } */
  /*   echo "</tr>\n"; */
  /* } */
  echo "</tbody>";
}



function open_not_numeric_table($table_name, $not_numeric_fields_array,$hostname)
{

    echo "<table class=\"main\">\n";
    if($hostname != "") {    
	echo "<caption><a href=\"index.php?host=$hostname&$table_name=true\">$table_name</a></caption>\n";
    }
    else {
	echo "<caption>$table_name</caption>\n";
    }
    
    echo "<thead>\n";
    echo "<tr>\n";
    

    for($i = 0; $i < sizeof($not_numeric_fields_array); $i++) {
	$aux_numeric_field = $not_numeric_fields_array[$i];
	echo "<th scope=\"col\">$aux_numeric_field</th>\n";
    }
    echo "\n</tr>\n</thead>";
}



function fill_not_numeric_table_all_data($table_data, $not_numeric_fields_array, $key_field)
{
    echo "<tbody>";
    date_default_timezone_set('UTC');
    $i = 0;
    $quit_loop = false;
    while($quit_loop == false) {
    	echo "<tr>\n";
	foreach($not_numeric_fields_array as $key) {
	    echo "<td>";
	    if(sizeof($table_data[$key]) == $i+1) {
		$quit_loop = true;
	    }
	    if($key_field == true  && $key == 'hostname') {
		$value = $table_data['hostname'][$i];
		echo "<a href=\"index.php?host=$value\"> $value </a>";
	    }
	    else if($key == 'timestamp' || $key == 'timestamp (UTC)') {
		echo date("Y-m-d H:i:s",$table_data['timestamp (UTC)'][$i]);
	    }
	    else {
		/* echo $key; */
		echo $table_data[$key][$i];
	    }
	    echo "</td>";
	}
	echo "</tr>\n";				
	$i++;
    }
    echo "</tbody>";
}

function fill_not_numeric_table_host_data($table_data, $not_numeric_fields_array,$hostname)
{
    echo "<tbody>";
    date_default_timezone_set('UTC');
    $i = 0;
    $quit_loop = false;
    while($quit_loop == false) {
    	echo "<tr>\n";
	foreach($not_numeric_fields_array as $key) {
	    echo "<td>\n";
	    if(sizeof($table_data[$hostname][$key]) == $i+1) {
		$quit_loop = true;
	    }
	    if($key == 'timestamp (UTC)') {
		echo date("Y-m-d H:i:s",$table_data[$hostname]['timestamp (UTC)'][$i]);
	    }
	    else {
		/* echo $key; */
		echo $table_data[$hostname][$key][$i];
	    }
	    echo "</td>\n";
	}
	echo "</tr>\n";				
	$i++;
    }
    echo "</tbody>\n";
}


function close_table()
{
echo <<<END
	</table>
END;
}

}



?>
