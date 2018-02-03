<?php
/**
 * Created by PhpStorm.
 * User: cedrickummer
 * Date: 04.02.18
 * Time: 00:30
 */
$servername = "localhost";
$username = "Website";
$password = "Rdt-bEX-Z37-ov5";
$dbname = "DPSG-Windrose-Test";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);
// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$sql = "SELECT Username , Password FROM User WHERE Username='Cedric'";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    // output data of each row
    while ($row = mysqli_fetch_assoc($result)) {
        echo "Username: " . $row["Username"] . " - Password: " . $row["Password"] . " " . "<br>";
    }
} else {
    echo "0 results";
}

mysqli_close($conn);

function LoginVerification(){

}

?>