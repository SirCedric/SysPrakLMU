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
    session_start();
    if(isset($_SESSION['username'])){
        include "php-helper/header_loggedIn.php";
    }else {
        include "php-helper/header.php";
    }
    ?>
    <main class="mdl-layout__content">
        <div class="page-content"><!-- Your content goes here -->
            <div class="mdl-grid">

              <div class="mdl-cell mdl-cell--8-col mdl-cell--8-col-tablet mdl-cell--12-col-phone">
                <div class="demo-card-wide mdl-shadow--2dp CN_index_Main_Card">
                  <div class="mdl-card__title">
                    <h2 class="mdl-card__title-text">Herzlich Willkommen</h2>
                  </div>
                  <div>
                    <div class="CN_index_Main_Card-text mdl-cell mdl-cell--10-col mdl-cell--10-col-tablet mdl-cell--12-col-phone">
                      bei den Pfadfindern des Stammes Windrose aus Anzing und Poing. </br>
                      Unser Stamm hat ungefähr 80 Mitglieder im Alter von 7 bis ... Jahren.</br>
                      Wir <b>Pfadfinder</b> treffen uns regelmäßig in den Stufen zu Gruppenstunden</br>
                      und zu gemeinsamen Aktionen entweder im Pfarrheim in <b>Poing</b> oder auf unserem Stammesplatz in <b>Anzing</b>.
                    </div>
                    <div class="CN_index_Main_Card-logo mdl-cell mdl-cell--2-col mdl-cell--2-col-tablet mdl-cell--0-col-phone">
                        <img src="images/logo/stammeslogo_home.png" alt="stammeslogo_home">
                    </div>
                  </div>
                </div>
              </div>
              <div class="mdl-cell mdl-cell--4-col mdl-cell--4-col-tablet mdl-cell--0-col-phone">
                <div class="mdl-card mdl-shadow--2dp CN_full-size_card">
                    <div class="mdl-card__title attention_message">
                        <h2 class="mdl-card__title-text">Achtung</h2>
                    </div>
                    <div class="mdl-card__supporting-text attention_message">
                        Diese seite befindet sich derzeit unter Wartungsarbeiten. und ist noch nicht final
                    </div>
                </div>
              </div>


              <div class="mdl-cell mdl-cell--6-col mdl-cell--6-col-tablet mdl-cell--12-col-phone">
                <div class="mdl-card mdl-shadow--2dp CN_full-size_card">
                    <div class="mdl-card__title">
                        <h2 class="mdl-card__title-text">Pfadfinder bringen Friedenslicht nach Anzing und Poing</h2>
                    </div>
                    <div class="mdl-card__supporting-text">
                      Am 4. Advent haben wir das Friedenslicht von der Frauenkirche geholt, den Gottesdienst zum Friedenslicht mitgestaltet und den Kindergottesdienst besucht. </br>
                      Auch ihr könnt Euch bis Weihnachten noch das Friedenslicht in der Kirche in Poing und Anzing abholen.
                    </div>
                    <div class="mdl-card__actions mdl-card--border">
                        <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="contentPage.php?article=1">
                            Mehr
                        </a>
                    </div>
                </div>
              </div>
              <div class="mdl-cell mdl-cell--6-col mdl-cell--6-col-tablet mdl-cell--12-col-phone">
                <div class="mdl-card mdl-shadow--2dp CN_full-size_card">
                    <div class="mdl-card__title">
                        <h2 class="mdl-card__title-text">Ramadama Poing 2016</h2>
                    </div>
                    <div class="mdl-card__supporting-text">
                      Auch dieses Jahr haben wir wieder beim Ramadama in Poing teilgenommen.</br>
                      Mit 16 Personen waren wir diesmal echt viele und haben unser Gebiet schnell abgearbeitet. </br>
                      Anschließend haben wir uns auf die reichhaltige Brotzeit im Bauhof gefreut.</br>
                      </br></br>
                      Danke an alle die da waren, vor allem an die Eltern! :)
                    </div>
                    <div class="mdl-card__actions mdl-card--border">
                        <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="contentPage.php?article=2">
                            Mehr
                        </a>
                    </div>
                </div>
              </div>
              <div class="mdl-cell mdl-cell--6-col mdl-cell--6-col-tablet mdl-cell--12-col-phone">
                <div class="mdl-card mdl-shadow--2dp CN_full-size_card">
                    <div class="mdl-card__title">
                        <h2 class="mdl-card__title-text">Übergabeevent 2016</h2>
                    </div>
                    <div class="mdl-card__supporting-text">
                      Liebe Pfadfinder,</br>
                      wir laden Euch herzlich zu unserem diesjährigen Übergabeevent ein.</br>
                      Wir werden gemeinsam einen aufregenden Tag im....</br>
                    </div>
                    <div class="mdl-card__actions mdl-card--border">
                        <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="contentPage.php?article=3">
                            Mehr
                        </a>
                    </div>
                </div>
              </div>
              <div class="mdl-cell mdl-cell--6-col mdl-cell--6-col-tablet mdl-cell--12-col-phone">
                <div class="mdl-card mdl-shadow--2dp CN_full-size_card">
                    <div class="mdl-card__title">
                        <h2 class="mdl-card__title-text">Stammesversammlung 2016</h2>
                    </div>
                    <div class="mdl-card__supporting-text">
                      Liebe Pfadfinder des DPSG Stammes Windrose,</br>
                      wir laden euch herzlich Stammesversammlung am....</br>
                    </div>
                    <div class="mdl-card__actions mdl-card--border">
                        <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="contentPage.php?article=4">
                            Mehr
                        </a>
                    </div>
                </div>
              </div>
            </div>
            <?php
            include 'php-helper/footer.php';
            ?>
        </div>
    </main>
</div>


</body>
</html>
