<?php
require_once('/home/www/rover/forum/SSI.php');

$_SESSION['login_url'] = 'http://test.dpsg-windrose.de/LogIn.php' . $_SERVER['PHP_SELF'];
$_SESSION['logout_url'] = 'http://test.dpsg-windrose.de/logout.php' . $_SERVER['PHP_SELF'];

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
?>