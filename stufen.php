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
      //session_start();
      //if(isset($_SESSION['username'])){
      // include "php-helper/header_loggedIn.php";
      //}else {
      include "php-helper/header.php";
      //}
      ?>
      <main class="mdl-layout__content">
          <div class="page-content">
              <div class="mdl-grid">

                <div class="mdl-cell mdl-cell--12-col mdl-cell--12-col-tablet mdl-cell--12-col-phone">
                  <div class="mdl-card mdl-shadow--2dp CN_full-size_card">
                      <div class="mdl-card__title">
                          <h2 class="mdl-card__title-text">Unsere Stufen in der schnell uebersicht</h2>
                      </div>
                      <div class="mdl-card__supporting-text">
                        <ul class="demo-list-two mdl-list">

                          <li class="mdl-list__item mdl-list__item--two-line">
                            <span class="mdl-list__item-primary-content">
                              <i class="material-icons mdl-list__item-avatar">person</i>
                              <span>Woelflinge</span>
                              <span class="mdl-list__item-sub-title">Die erste von insgesamt 5 Stufen</span>
                            </span>
                            <span class="mdl-list__item-secondary-content">
                              <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="stufenContent.php?article=1">
                                  Hier erfahren Sie mehr zu den Woelflingen
                              </a>
                            </span>
                          </li>
                          <li class="mdl-list__item mdl-list__item--two-line">
                            <span class="mdl-list__item-primary-content">
                              <i class="material-icons mdl-list__item-avatar">person</i>
                              <span>Die Jungpfadfinder</span>
                              <span class="mdl-list__item-sub-title">Die zweite und Jugendlichere Stufen</span>
                            </span>
                            <span class="mdl-list__item-secondary-content">
                              <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="stufenContent.php?article=2">
                                  Hier erfahren Sie mehr zu den Jungpfadfindern
                              </a>
                            </span>
                          </li>
                          <li class="mdl-list__item mdl-list__item--two-line">
                            <span class="mdl-list__item-primary-content">
                              <i class="material-icons mdl-list__item-avatar">person</i>
                              <span>Die Pfadfinder</span>
                              <span class="mdl-list__item-sub-title">Der klassiker unter all den Stufen</span>
                            </span>
                            <span class="mdl-list__item-secondary-content">
                              <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="stufenContent.php?article=3">
                                  Hier erfahren Sie mehr zu den Pfadfindern
                              </a>
                            </span>
                          </li>
                          <li class="mdl-list__item mdl-list__item--two-line">
                            <span class="mdl-list__item-primary-content">
                              <i class="material-icons mdl-list__item-avatar">person</i>
                              <span>Die Rover</span>
                              <span class="mdl-list__item-sub-title">Rover sein heißt "unterwegs sein"</span>
                            </span>
                            <span class="mdl-list__item-secondary-content">
                              <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="stufenContent.php?article=4">
                                  Alles hierzu erfahren Sie hier
                              </a>
                            </span>
                          </li>
                          <li class="mdl-list__item mdl-list__item--two-line">
                            <span class="mdl-list__item-primary-content">
                              <i class="material-icons mdl-list__item-avatar">person</i>
                              <span>Die Leiterrunde</span>
                              <span class="mdl-list__item-sub-title">Hier finden sie alle Stufenleiter und mehr</span>
                            </span>
                            <span class="mdl-list__item-secondary-content">
                              <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect" href="stufenContent.php?article=5">
                                  Die Leiterrunde
                              </a>
                            </span>
                          </li>

                        </ul>
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
