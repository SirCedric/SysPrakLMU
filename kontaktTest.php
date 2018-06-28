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

    <!-- Start Cookie Plugin -->
    <script type="text/javascript">
        window.cookieconsent_options = {
            message: 'Diese Website nutzt Cookies, um bestmögliche Funktionalität bieten zu können.',
            dismiss: 'Ok, verstanden',
            learnMore: 'Mehr Infos',
            link: 'http://test.dpsg-windrose.de/datenschutzerklarung.php',
            theme: 'light-floating'
        };
    </script>
    <script type="text/javascript" src="//s3.amazonaws.com/valao-cloud/cookie-hinweis/script-v2.js"></script>
    <!-- Ende Cookie Plugin -->

</head>

<?php
session_start();
if(isset($_SESSION['username'])){
    include "php-helper/header_loggedIn.php";
}else {
    include "php-helper/header.php";
}
?>
<?php
// Ausführen wenn Formular gesendet
if (isset($_POST["submit"]))
{
// Sammeln der Formulardaten
$an = "meine@email.de";
$name = $_POST['name'];
$email = $_POST['email'];
$betreff = $_POST['betreff'];
$nachricht = $_POST['nachricht'];
// Mailheader UTF-8 fähig machen
$mail_header = 'From:' . $email . "n";
$mail_header .= 'Content-type: text/plain; charset=UTF-8' . "rn";
// Nachrichtenlayout erstellen
$message = "
Name:       $namen
Email:      $emailn
Nachricht:  $nachrichtn
";
// Verschicken der Mail
mail($an, $betreff, $message, $mail_header );
};
?>

<form id="form" action="form2email.php" method="post">
    <label for="name">Name</label>
    <input id="name" name="name" size="25" type="text" />
    <label for="email">Email</label>
    <input id="email" name="email" size="25" type="text" />
    <label for="betreff">Betreff</label>
    <input id="betreff" name="betreff" size="25" type="text" />
    <label for="nachricht">Nachricht</label>
    <textarea id="nachricht" cols="50" rows="6" name="nachricht"></textarea>
    <input id="submit" name="submit" type="submit" value="Formular senden" />
</form>
