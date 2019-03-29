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
<body  style="background-image: url('images/Backgound/ImpressungBackground.JPG'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;">
<div class="mdl-layout mdl-js-layout">
    <?php
    require_once('/home/www/rover/forum/SSI.php');
    include "php-helper/header.php";
    ?>
    <main class="mdl-layout__content">
        <div class="page-content"><!-- Your content goes here -->
            <div class="mdl-grid">
                <style>
                    .demo-card-wide.mdl-card {
                        width: 80%;
                        margin: 0 auto;
                        margin-bottom: 10px;
                    }
                </style>



                <div class="mdl-layout-spacer"></div>
                <div class="mdl-cell mdl-cell--10-col mdl-cell--10-col-tablet mdl-cell--12-col-phone">
                    <div class="demo-card-wide mdl-card mdl-shadow--4dp CN_index_Main_Card">
                        <div class="mdl-card__title">
                            <h2 class="mdl-card__title-text">Stammesvorstand</h2>
                        </div>
                        <div class="mdl-card__supporting-text">
                            <ul class="demo-list-icon mdl-list">
                                <li class="mdl-list__item">
                        <span class="mdl-list__item-primary-content">
                        <i class="material-icons mdl-list__item-icon">person</i>
                        Kilian Hohl</br>
                            Inzeller Weg 1</br>
                            81825 München</br>
                            E-Mail: stavo@dpsg-windrose.de
                    </span>
                                </li>
                                <li class="mdl-list__item">
                        <span class="mdl-list__item-primary-content">
                        <i class="material-icons mdl-list__item-icon">person</i>
                        Dominik Hohl</br>
                            Zugspitzstraße 16</br>
                            85586 Poing</br>
                            E-Mail: stavo@dpsg-windrose.de
                      </span>
                                </li>
                            </ul>
                            <div class="mdl-card__menu">
                                <a class="mdl-button mdl-button--icon mdl-js-button mdl-js-ripple-effect" href="mailto:stavo@dpsg-windrose.de">
                                    <i class="material-icons">share</i>
                                </a>
                            </div>
                        </div>
                              </div>
                          </div>
                <!-- -->
                <div class="mdl-layout-spacer"></div>
            </div>
            <div class="mdl-grid">

                <style>
                    .demo-card-wide.mdl-card {
                        width: 80%;
                        margin: 0 auto;
                        margin-bottom: 10px;
                    }
                </style>

                <div class="mdl-layout-spacer"></div>
                <div class="mdl-cell mdl-cell--10-col mdl-cell--10-col-tablet mdl-cell--12-col-phone">
                    <div class="demo-card-wide mdl-card mdl-shadow--4dp CN_index_Main_Card">
                        <div class="mdl-card__title">
                            <h2 class="mdl-card__title-text">Administrator</h2>
                        </div>
                        <div class="mdl-card__supporting-text">
                            <ul class="demo-list-icon mdl-list">
                                <li class="mdl-list__item">
                      <span class="mdl-list__item-primary-content">
                      <i class="material-icons mdl-list__item-icon">person</i>
                      Martin Donauer </br>
                          Siglfinger Straße 1A</br>
                          85435 Erding</br>
                          E-Mail: webmaster@dpsg-windrose.de
                          </br>

                      </span>
                                </li>
                                <li class="mdl-list__item">
                                    <span class="mdl-list__item-primary-content">
                                <i class="material-icons mdl-list__item-icon">person</i>
                                Cedric Kummer </br>
                                Flurstraße 10 </br>
                                85646 Anzing </br>
                                E-Mail: webmaster@dpsg-windrose.de
                                    </span>
                                </li>

                            </ul>
                            <div class="mdl-card__menu">
                                <a class="mdl-button mdl-button--icon mdl-js-button mdl-js-ripple-effect" href="mailto:webmaster@dpsg-windrose.de">
                                    <i class="material-icons">share</i>
                                </a>

                            </div>
                        </div>
                    </div>
                </div>
                <div class="mdl-layout-spacer"></div>

               <!-- <div class="mdl-layout-spacer"></div>-->

                <span class="ImpressumHaftungshinweis">
                    </br>
                    </br>
                    </br>
                    </br>
                    Haftungshinweis: Trotz sorgfältiger inhaltlicher Kontrolle übernehmen wir keine Haftung für die Inhalte externer Links. Für den Inhalt der verlinkten Seiten sind ausschließlich deren Betreiber verantwortlich
                </span>
            </div>
        </div>
            <?php
            include 'php-helper/footer.php';
            ?>
    </main>
</div>
</body>
</html>