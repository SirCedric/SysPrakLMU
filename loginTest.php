<!DOCTYPE html>
<html class="mdl-js">
<head>
    <meta charset="utf-8">
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <meta name="description" content="A front-end template that helps you build fast, modern mobile web apps.">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, minimum-scale=1.0">
    <title>DPSG Windrose Anzing/Poing</title>

    <link rel="shortcut icon" href="images/favicon.png">

    <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
    <link rel="stylesheet" href="https://code.getmdl.io/1.3.0/material.indigo-pink.min.css">
    <link rel="stylesheet" href="css/main.css">
    <script defer src="https://code.getmdl.io/1.3.0/material.min.js"></script>
</head>
<body class="mainColor">
<div class="mdl-layout mdl-js-layout">

<?php

require_once('/home/www/rover/forum/SSI.php');
$_SESSION['login_url']='http://test.dpsg-windrose.de/index.php';
$_SESSION['logout_url']='http://test.dpsg-windrose.de/index.php';
/*

if ($context['user']['is_guest'])
{
	ssi_login();
}
else
{
	//You can show other stuff here.  Like ssi_welcome().  That will show a welcome message like.
	//Hey, username, you have 552 messages, 0 are new.
	ssi_logout();
}
*/
?>
<?php
include "php-helper/headerTest.php";
?>
<?php
include 'logInOutDialog.php';
?>
<?php
include 'php-helper/footer.php';
?>
</div>
</body>
</html>
