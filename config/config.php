<?php
$dbServer = "localhost";
$dbUsername = "wa3292_5";
$dbPassword = "Rdt-bEX-Z37-ov5";
$dbName = "wa3292_db5";
$dbPort = "3306";

//user: wa3292_5
//db: wa3292_db5
/* Attempt to connect to MySQL database */
$link = mysqli_connect($dbServer, $dbUsername, $dbPassword, $dbName, $dbPort);
mysqli_set_charset($link, "utf8");


// Check connection
if($link === false){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}
?>