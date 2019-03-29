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
<body  style="background-image: url('images/Backgound/AusruestungBackground.JPG'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;">
<div class="mdl-layout mdl-js-layout">
    <?php
    include "php-helper/header.php";
    ?>
    <main class="mdl-layout__content">
        <div class="page-content"><!-- Your content goes here -->
            <div class="mdl-grid">

                <div class="center_text mdl-cell mdl-cell--10-col mdl-cell--10-col-tablet mdl-cell--12-col-phone">
                    <div class="mdl-card mdl-shadow--2dp CN_full-size_card_stammesinfo">
                        <div class="mdl-card__title">
                            <h2 class="center_text mdl-card__title-text">Alles was es über unsere Ausrüstung zu erwähnen gibt</h2>
                        </div>
                        <div class="mdl-card__supporting-text">
                            <ul class="demo-list-two mdl-list">

                                <li class="mdl-list__item mdl-list__item--two-line">
                            <span class="mdl-list__item-primary-content">
                              <a class="center_text mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="kluft.php">
                                  Zur Kluft
                              </a>
                                <span class="mdl-list__item-sub-title"><center>Hier erfahren Sie alles wissenswerte über unsere Kluft</center></span>
                            </span>
                                </li>
                        </div>

                        <div class="mdl-card__supporting-text">
                            <ul class="demo-list-two mdl-list">

                                <li class="mdl-list__item mdl-list__item--two-line">
                            <span class="mdl-list__item-primary-content">
                              <a class="center_text mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="abPäckchen.php">
                                  Das Allzeit-Bereit-Päckchen
                              </a>
                                <span class="mdl-list__item-sub-title"><center>Das Allzeit-Bereit-Päckchen gehört zur Grundausrüstung</center></span>
                            </span>
                                </li>
                        </div>

                        <div class="mdl-card__supporting-text">
                            <ul class="demo-list-two mdl-list">

                                <li class="mdl-list__item mdl-list__item--two-line">
                            <span class="mdl-list__item-primary-content">
                              <a class="center_text mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="packliste.php">
                                  Zur Packliste
                              </a>
                                <span class="mdl-list__item-sub-title"><center>Damit nichts daheim vergessen wird</center></span>
                            </span>
                                </li>
                        </div>

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
