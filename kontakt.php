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


              <form action="http://yourserver/contact.php" method="post">
              <table border="0" cellspacing="0" cellpadding="2">
                <tbody>
                  <tr>
                    <td>Abteilung:</td>
                    <td>
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
                    </td>
                  </tr>
                  <tr>
                    <td>Anrede:</td>
                    <td>
                      <input checked="checked" name="Anrede" type="radio" value="Herr" /> Herr
                      <input name="Anrede" type="radio" value="Frau" /> Frau
                    </td>
                  </tr>
                  <tr>
                    <td>Vorname:</td>
                    <td>
                      <input maxlength="50" name="Vorname" size="45" type="text" />
                    </td>
                  </tr>
                  <tr>
                    <td>Nachname:</td>
                    <td>
                      <input name="Nachname" size="45" type="text" />
                    </td>
                  </tr>
                  <tr>
                    <td>Email:</td>
                    <td>
                      <input name="Email" size="45" type="text" />
                    </td>
                  </tr>
                  <tr>
                    <td>Betreff:</td>
                    <td>
                      <input name="Betreff" size="45" type="text" />
                    </td>
                  </tr>
                  <tr>
                    <td>Mitteilung:</td>
                    <td><textarea cols="30" rows="5" name="Mitteilung">Ihre Mitteilung</textarea></td>
                  </tr>
                  <tr>
                    <td></td>
                    <td>
                      <input type="submit" value="Abschicken" />
                    </td>
                  </tr>
                </tbody>
              </table>
              </form>



            </div>
            <?php
            include 'php-helper/footer.php';
            ?>
        </div>
    </main>
</div>


</body>
</html>
