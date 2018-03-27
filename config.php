<?php
/* Database credentials. Assuming you are running MySQL
server with default setting (user 'root' with no password) */
define('DB_SERVER', 'localhost');
define('DB_USERNAME', 'wa3292_5');
define('DB_PASSWORD', 'Rdt-bEX-Z37-ov5');
define('DB_NAME', 'wa3292_db5');
define('DB-Port', '3306');

//user: wa3292_5
//db: wa3292_db5
/* Attempt to connect to MySQL database */
$link = mysqli_connect(DB_SERVER, DB_USERNAME, DB_PASSWORD, DB_NAME, DB-Port);
mysqli_set_charset($link, "utf8");


// Check connection
if($link === false){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}
?>