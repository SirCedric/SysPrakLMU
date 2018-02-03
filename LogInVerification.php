<?php

/**
 * Created by PhpStorm.
 * User: cedrickummer
 * Date: 03.02.18
 * Time: 22:03
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

/*if (mysqli_num_rows($result) > 0) {
    // output data of each row
    while ($row = mysqli_fetch_assoc($result)) {
        echo "Username: " . $row["Username"] . " - Password: " . $row["Password"] . " " . "<br>";
    }
} else {
    echo "0 results";
}
*/

mysqli_close($conn);



function Login()
{
    if (empty($_POST['username'])) {
        $this->HandleError("UserName is empty!");
        return false;
    }

    if (empty($_POST['password'])) {
        $this->HandleError("Password is empty!");
        return false;
    }

    $username = trim($_POST['username']);
    $password = trim($_POST['password']);

    if (!$this->CheckLoginInDB($username, $password)) {
        return false;
    }

    session_start();

    $_SESSION[$this->GetLoginSessionVar()] = $username;

    return true;
}

function CheckLoginInDB($username, $password)
{
    if (!$this->DBLogin()) {
        $this->HandleError("Database login failed!");
        return false;
    }
    $username = $this->SanitizeForSQL($username);
    $pwdmd5 = md5($password);
    $qry = "Select name, email from $this->tablename " .
        " where username='$username' and password='$pwdmd5' " .
        " and confirmcode='y'";

    $result = mysql_query($qry, $this->connection);

    if (!$result || mysql_num_rows($result) <= 0) {
        $this->HandleError("Error logging in. " .
            "The username or password does not match");
        return false;
    }
    return true;
}
