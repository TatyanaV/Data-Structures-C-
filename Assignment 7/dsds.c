<?php
ini_set('display_errors',1);
error_reporting(E_ALL ^ E_NOTICE);
session_start();
if(!isset($_SESSION['username'])){
header('Location: index.php');
}
$username = $_SESSION['username'];
?>
<!DOCTYPE html>
<!--
Jonathan Ziefle
CS494
Project - GPS Sport Tracker
-->
<html>
<head>
<title>Activities</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet" href="project.css" type="text/css"/>
<script src="js/jquery.js"></script>
<script>
var username = "<?php echo $username; ?>";
$(document).ready(function(){
$("#header1").append(username + "!");
});
</script>
<style>
#full-screen-background-image {
  z-index: -999;
  min-height: 100%;
  min-width: 1024px;
  width: 100%;
  height: auto;
  position: fixed;
  top: 0;
  left: 0;
}
.background1{
    width:100%;
    height:100%;
    top:0px;
    left:0px;
    bottom:0px;
    right:0px;
}
.bgcolor {
    position:absolute;
    width:100%;
    height:100%;
    top:0px;
    left:0px;
    bottom:0px;
    right:0px;
    background-color:#000000;
    opacity:0.5;
}

.box {
    min-width:220px;
    min-height:80px;
    background:#ffffff;
    border:1px solid grey;
    padding:20px;
    -webkit-border-radius:10px;
    border-radius:10px;
    -webkit-box-shadow:#333 5px 5px 2px;
	width: 440px;
    margin: auto;
}

.mytext {
    width: 300px;
	font-family: Arial;

}

.mytext2 {
    width: 305px;
	font-family: Arial;

}

#name{
font-family: Arial;
}


.upform {
margin-top: 15px;
}
h4 {
padding-top: 0px;
margin-top: -25px;
margin-bottom: 10px;
}
</style>


</head>
<body>
<header>

<h1 id = "header1">WELCOME, </h1>

<ul id="nav">

	<li id="activity"><a href="activities.php">ACTIVITIES</a></li>
	<li id="upload"><a href="upload.php">UPLOAD FILE</a></li>
	<li id="logout"><a href="logout.php">LOGOUT</a></li>
			<li><a href="#">FAQs</a></li>
		<li><a href="#">Contact</a></li>
		<li><a href="#">About Us</a></li>
        <li><a href="#">Our Products</a></li>
</ul>

   <img alt="full screen background image" src="road-trip-on-historic-u-s-route-66-images-antony-ingram_100430531_l.jpg" id="full-screen-background-image" />
</header>

<div class="contents">
<div class="title">
<h2 id="name1">LIST OF YOUR TRIPS:</h2>
</div>
<div id="activities">

<div align="center">
<table style = "font-size:18px;">
<?php

	$mysql_db_hostname = "oniddb.cws.oregonstate.edu";
	$mysql_db_user = "vlaskint-db";
	$mysql_db_password = "tb0NGWMdrkGhe2mA";
	$mysql_db_database = "vlaskint-db";


	//http://www.sitepoint.com/avoid-the-original-mysql-extension-1/
	$con = mysqli_connect($mysql_db_hostname, $mysql_db_user, $mysql_db_password) or die("Could not connect database");

	mysqli_select_db($con, $mysql_db_database) or die("Could not select database");
	//mysqli_select_db($mysql_db_database, $con) or die("Could not select database");

	// Procedural API connection method #1
	//$db = mysqli_connect('host', 'username', 'password');
	//mysqli_select_db($con, $mysql_db_database);

	//http://php.net/manual/en/mysqli.query.php
	//http://stackoverflow.com/questions/20875113/php-mysql-select-using-mysqli-query
	//http://stackoverflow.com/questions/20875113/php-mysql-select-using-mysqli-query
	//http://www.w3schools.com/php/func_mysqli_num_rows.asp




$query = "SELECT * FROM activities WHERE username='$username' ORDER BY start DESC";
$result = mysqli_query($con, $query)or die(mysqli_error($con));
$num_row = mysqli_num_rows($result);


echo "<table><tr id='top_row'style='background-color:#728C00;'><th>View</th><th>Name</th><th>Type</th><th>Start</th><th>Distance</th><th>Time</th><th>Speed/Pace</th><th>Elevation Gain</th><th>Delete</th></tr>";
while ($row = mysqli_fetch_array($result))
{
echo "<tr>";
echo
"<td><form method = 'GET' action = 'analysis.php'>
<input type='hidden' name='filename' value='" . $row['filename'] . "'>
<input type='hidden' name='type' value='" . $row['type'] . "'>
<input type='submit' value='View'></form></td>";
echo "<td>" . $row['name'] . "</td>";
echo "<td>" . $row['type'] . "</td>";
$datetime = strtotime($row['start']);
$mysqldate = date("m/d/y g:i A", $datetime);
echo "<td>" . $mysqldate . "</td>";
echo "<td>" . round($row['distance'], 1) . " mi</td>";
echo "<td>" . gmdate("H:i:s", $row['time']) . "</td>";
if ($row['type'] == "Run") {
$pace = 1 / ($row['speed'] / 60);
$minute = floor($pace);
$second = round(($pace - $minute) * 60, 0);
echo "<td>" . $minute . ":" . $second . " min/mi</td>";
} else {
echo "<td>" . round($row['speed'], 1) . " mph</td>";
}
echo "<td>" . round($row['elevation'], 0) . " ft</td>";
$delete = 'Are you sure you want to delete \"' . $row['name'] . '\"?';
echo
"<td><form method = 'POST' action = 'database.php'>
<input type='hidden' name='filename' value='" . $row['filename'] . "'>
<input type='hidden' name='type' value='delete'>
<input type='submit' value='Delete' onclick='return confirm(\"Delete \u0022" . $row['name'] ."\u0022?\")'></form></td></tr>";
}
echo "</table>";
?>
</div>
</div>
</body>
</html>
