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

              <ul class='mdl-list'>
                  <form action="http://yourserver/contact.php" method="post">

                <select name="Abteilung">
                  <option value="Vorstand">Vorstand</option>
                  <option value="Woelflingsleiter">Woelflingsleiter</option>
                  <option value="Jupfleiter">Jupfleiter</option>
                  <option value="Pfadleiter">Pfadleiter</option>
                  <option value="Roverleiter">Roverleiter</option>
                  <option value="Webmaster">Webmaster</option>
                  <option value="Zeltverleih">Zeltverleih</option>
                  <option value="Bootsverleih">Bootsverleih</option>
                  <option value="Platzwart">Platzwart</option>
                  <option value="Foerderkreis">Foerderkreis</option>
                </select>

                <li class="mdl-list__item">
                  <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                    <input class="mdl-textfield__input" type="text" id="sample3">
                    <label class="mdl-textfield__label" for="sample3">Vorname...</label>
                  </div>
                </li>
                <li class="mdl-list__item">
                  <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                    <input class="mdl-textfield__input" type="text" id="sample3">
                    <label class="mdl-textfield__label" for="sample3">Nachname...</label>
                  </div>
                </li>
                <li class="mdl-list__item">
                  <label class="mdl-radio mdl-js-radio mdl-js-ripple-effect" for="option-1">
                    <input type="radio" id="option-1" class="mdl-radio__button" name="options" value="1" checked>
                    <span class="mdl-radio__label">Herr</span>
                  </label>
                  <label class="mdl-radio mdl-js-radio mdl-js-ripple-effect" for="option-2">
                    <input type="radio" id="option-2" class="mdl-radio__button" name="options" value="2">
                    <span class="mdl-radio__label">Frau</span>
                  </label>
                </li>

                <li class="mdl-list__item">
                  <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                    <input class="mdl-textfield__input" type="text" id="sample3">
                    <label class="mdl-textfield__label" for="sample3">E-Mail...</label>
                  </div>
                </li>
                <li class="mdl-list__item">
                  <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                    <input class="mdl-textfield__input" type="text" id="sample3">
                    <label class="mdl-textfield__label" for="sample3">Betreff...</label>
                  </div>
                </li>
                <li class="mdl-list__item">
                <div class="mdl-textfield mdl-js-textfield">
                  <textarea class="mdl-textfield__input" type="text" rows= "3" id="sample5" ></textarea>
                  <label class="mdl-textfield__label" for="sample5">Mitteilung...</label>
                </div>
              </li>
                  <button class="mdl-button mdl-js-button mdl-button--raised mdl-button--colored">
                    Senden
                  </button>
                  <input type="submit" value="Abschicken" />
                  </form>
              </ul>
            </div>
            <?php
            include 'php-helper/footer.php';
            ?>
        </div>
    </main>
</div>


</body>
</html>
