<?php
require_once('/home/www/rover/forum/SSI.php');
?>
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
<body  class="mainColor">
<div class="mdl-layout mdl-js-layout">
    <?php
    include "php-helper/header.php";
    ?>
    <main class="mdl-layout__content">
        <div class="page-content"><!-- Your content goes here -->
            <div class="mdl-grid">

                <?php include "wartungsnachricht.php" ?>

                <div class='CN_index_Main_Card mdl-card mdl-shadow--4dp mdl-cell mdl-cell--12-col'>
                    <div class='mdl-card__title'>
                        <h4 class="mdl-card__title-text">Die <b>&nbsp;D</b>eutsche <b>&nbsp;P</b>fadfinderschaft <b>&nbsp;S</b>ankt <b>&nbsp;G</b>eorg</h4>
                        </div>
                    <div class='mdl-color-text--grey-700 mdl-card__supporting-text CN_index_Main_Card-text'>
                        <p><b><i>Der Text muss noch geschrieben werden</i></b></p>
                        <div class="mdl-card__actions mdl-card--border">
                        <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="DPSG.php">
                        Zurück zur Übersicht
                        </a>
                        </div>
                    </div>
                </div>

        </div>
            <?php
            include 'php-helper/footer.php';
            ?>
    </main>
</div>

</body>
</html>