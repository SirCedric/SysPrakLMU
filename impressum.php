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
    include "php-helper/headerTest.php";
    ?>
    <main class="mdl-layout__content">
        <div class="page-content"><!-- Your content goes here -->
            <div class="mdl-grid">
                <style>
                    .demo-card-wide.mdl-card {
                        width: 512px;
                    }
                </style>

                <div class="mdl-layout-spacer"></div>

                <div class="mdl-cell mdl-cell--4-col mdl-cell--6-col-tablet mdl-cell--4-col-phone">
                    <div class="demo-card-wide mdl-card mdl-shadow--2dp">
                        <div class="mdl-card__title">
                            <h2 class="mdl-card__title-text">Stammesvorstand</h2>
                        </div>
                        <div class="mdl-card__supporting-text">
                            <ul class="demo-list-icon mdl-list">
                                <li class="mdl-list__item">
                        <span class="mdl-list__item-primary-content">
                        <i class="material-icons mdl-list__item-icon">person</i>
                        Rosalie Nitzl </br>
                            Bahnhofstr. 1A</br>
                            85591 Vaterstetten</br>
                            E-Mail:</br>
                            <a href="mailto:stavo@dpsg-windrose.de">stavo@dpsg-windrose.de</a>
                    </span>
                                </li>
                                <li class="mdl-list__item">
                        <span class="mdl-list__item-primary-content">
                        <i class="material-icons mdl-list__item-icon">person</i>
                        Dominik Hohl</br>
                            Zugspitzstraße 16</br>
                            85586 Poing</br>
                            E-Mail:</br>
                            <a href="mailto:stavo@dpsg-windrose.de">stavo@dpsg-windrose.de</a>
                      </span>
                                </li>
                            </ul>
                            <div class="mdl-card__menu">
                                <button class="mdl-button mdl-button--icon mdl-js-button mdl-js-ripple-effect">
                                    <i class="material-icons">share</i>
                                </button>
                            </div>
                        </div>
                    </div>
                </div>

                <div class="mdl-layout-spacer"></div>

                <div class="mdl-cell mdl-cell--4-col mdl-cell--6-col-tablet mdl-cell--4-col-phone">
                    <div class="demo-card-wide mdl-card mdl-shadow--2dp">
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
                          E-Mail:</br>
                          <a href="mailto:webmaster@dpsg-windrose.de">webmaster@dpsg-windrose.de</a>
                      </span>
                                </li>
                            </ul>
                            <div class="mdl-card__menu">
                                <button class="mdl-button mdl-button--icon mdl-js-button mdl-js-ripple-effect">
                                    <i class="material-icons">share</i>
                                </button>
                            </div>
                        </div>
                    </div>
                </div>

                <div class="mdl-layout-spacer"></div>

                <span class="ImpressumHaftungshinweis">
                    </br>
                    </br>
                    </br>
                    </br>
                    Haftungshinweis: Trotz sorgfältiger inhaltlicher Kontrolle übernehmen wir keine Haftung für die Inhalte externer Links. Für den Inhalt der verlinkten Seiten sind ausschließlich deren Betreiber verantwortlich
                </span>
            </div>
            <?php
            include 'php-helper/footer.php';
            ?>
        </div>
    </main>
</div>
</body>
</html>