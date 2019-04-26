<?php
session_start();
header('Content-Type: text/html; charset=utf-8');
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
<body class="mainColor">
<div class="mdl-layout mdl-js-layout">
    <?php
    require_once('/home/www/rover/forum/SSI.php');
    include "php-helper/header.php";
    ?>
    <main class="mdl-layout__content">
        <div id="page-container">
            <div class="page-content" id="content-wrap"><!-- Your content goes here -->
                <div class="mdl-grid">
                    <div class='mdl-card news_Card_location mdl-shadow--4dp mdl-cell mdl-cell--8-col mdl-cell--12-col-phone mdl-cell--10-col-tablet'>
                        <?php
                        /* Tristan Radtke, 2017.
                         * Dieses Skript darf frei verwendet werden. Bitte entferne nicht die Urheber- und Anleitungshinweise.
                         * http://www-coding.de/individuelles-kontaktformular-mit-captcha-in-php/ (MEHR INFORMATIONEN UND ANLEITUNG)
                         *
                         * [VERSION MIT CAPTCHA]
                         *
                         * Dieser 1. Teil kann angepasst werden, um die Formularfelder zu beeinflussen ($fields)
                         * Außerdem solltest Du in $adminMail deine E-Mail-Adresse speichern
                         * $formTitle beinhaltet die Überschrift des Formulars
                         * In $msgInfo ist der Hinweistext gespeichert, der angezeigt werden soll
                         * $msgError wird angezeigt, wenn nicht alle Pflichtfelder ausgefüllt wurden
                         * $msgSent hingegen beinhaltet eine Erfolgsmeldung, wenn die Anfrage verschickt wurde
                         * Speichere in $captchaPath den Pfad von der aktuellen Datei aus zur captcha.php
                         */

                        $adminMail = 'cedric.kummer@gmx.de';

                        $formTitle = 'Kontaktformular';
                        $msgInfo = 'Um uns zu kontaktieren füllen Sie bitte das folgende Formular aus. Mit * gekennzeichnete Felder sind Pflichtfelder.';
                        $msgError = 'Es ist ein Fehler aufgetreten: Es wurden nicht alle Felder korrekt ausgefüllt.';
                        $msgSent = 'Ihre Anfrage wurde erfolgreich verschickt.';
                        $captchaPath = 'captcha/captcha.php';

                        $fields = array(
                            // 'Feldname'		=>		 Typ, Pflichtfeld?, Ergänzungen (z.B. bei select-Feld)
                            'Empfänger' => array('select', true, array('Vorstand', 'Platzwart', 'Webmaster', 'Förderkreis', 'Zeltverleih', 'Bootsverleih', 'Wölflingsleiter', 'Jupfileiter', 'Pfadileiter', 'Roverleiter', 'Leiterrunde')),
                            'Anrede' => array('select', true, array('Frau', 'Herr')),
                            'Vorname' => array('text', false),
                            'Nachname' => array('text', true),
                            //'Website'			=> array('text', false),
                            'E-Mail-Adresse' => array('text', true),
                            'Betreff' => array('text', false),
                            'Mitteilung' => array('textarea', true),
                        );

                        /* Funktion um aus den Feldnamen eine URL-Form zu erstellen (AB HIER BITTE NUR NOCH EVENTUELLE TEXTE ANPASSEN) */
                        function field2url($fieldname)
                        {
                            return "f_" . preg_replace('/([^a-z0-9-_]+)/', '', strtolower($fieldname));
                        }

                        /* Ausgabe des Formulars  */
                        if (isset($_POST['send']) && isset($_POST['captcha_code']) && isset($_POST['email'])) {
                            // 2. Eingaben prüfen //
                            $mailSubject = 'Kontaktformular';
                            $mailText = "Das Kontaktformular deiner Website wurde dazu verwendet, Dir diese Nachricht zukommen zulassen.\r\n\r\n";
                            $mailHeader = "From: kontaktformular@" . $_SERVER['HTTP_HOST'] . "\r\n" . "Content-type: text/plain; charset=utf-8" . "\r\n";

                            // Einzelne Felder auslesen //
                            foreach ($fields AS $name => $settings) {
                                //Empfänger der Mail auswählen
                                if ($name == 'Empfänger') {
                                    if ($_POST[field2url($name)] == 'Vorstand') {
                                        $adminMail = 'stavo@dpsg-windrose.de';
                                    }
                                    if ($_POST[field2url($name)] == 'Platzwart') {
                                        $adminMail = 'jwidhopf@web.de';
                                    }
                                    if ($_POST[field2url($name)] == 'Förderkreis') {
                                        $adminMail = 'foerderkreis@dpsg-windrose.de';
                                    }
                                    if ($_POST[field2url($name)] == 'Webmaster') {
                                        $adminMail = 'webmaster@dpsg-windrose.de';
                                    }
                                    if ($_POST[field2url($name)] == 'Wölflingsleiter') {
                                        $adminMail = 'woeleiter@dpsg-windrose.de';
                                    }
                                    if ($_POST[field2url($name)] == 'Jupfileiter') {
                                        $adminMail = 'jupfileiter@dpsg-windrose.de';
                                    }
                                    if ($_POST[field2url($name)] == 'Pfadileiter') {
                                        $adminMail = 'pfadileiter@dpsg-windrose.de';
                                    }
                                    if ($_POST[field2url($name)] == 'Roverleiter') {
                                        $adminMail = 'roverleiter@dpsg-windrose.de';
                                    }
                                    if ($_POST[field2url($name)] == 'Leiterrunde') {
                                        $adminMail = 'leiterrunde@dpsg-windrose.de';
                                    }
                                    if ($_POST[field2url($name)] == 'Zeltverleih') {
                                        $adminMail = 'stavo@dpsg-windrose.de';
                                    }
                                    if ($_POST[field2url($name)] == 'Bootsverleih') {
                                        $adminMail = 'stavo@dpsg-windrose.de';
                                    }
                                }
                                if (!(!$settings[1] || ($settings[1] && isset($_POST[field2url($name)]) && $_POST[field2url($name)] != ''))) {
                                    // Pflichtfeld nicht ausgefüllt => Abbruch //
                                    $sent = false;
                                    break;
                                } else if ($_POST[field2url($name)] != '') {
                                    // Inhalt (wenn nicht leer) in die E-Mail schreiben //
                                    if ($name == 'Mitteilung') {
                                        $mailText .= $name . ": \r\n\n" . $_POST[field2url($name)] . "\r\n";
                                    } else {
                                        $mailText .= $name . ": " . $_POST[field2url($name)] . "\r\n";
                                    }

                                    // E-Mail-Adresse als Absender setzen //
                                    if ($name == "E-Mail-Adresse" && filter_var($_POST[field2url($name)], FILTER_VALIDATE_EMAIL)) {
                                        $mailHeader = "From: " . $_POST[field2url($name)] . "\r\n" . "Content-type: text/plain; charset=utf-8" . "\r\n";
                                    }

                                    // Betreff auch in den Betreff der E-Mail übernehmen //
                                    if ($name == "Betreff") {
                                        $mailSubject .= ": " . $_POST[field2url($name)];
                                    }
                                }
                            }

                            // Kurzer Spam-Check inkl. Captcha-Check //
                            if ($_POST['captcha_code'] != $_SESSION['captcha_spam'] || $_POST['email'] != '') {
                                // Bot => Abbruch //
                                $sent = false;
                            }

                            if (!isset($sent)) {
                                // Nach erfolgreicher Überprüfung E-Mail verschicken //
                                mail($adminMail, $mailSubject, $mailText, $mailHeader);

                                echo "<div class=\"mdl-card__title headline\">
                                <h4 class=\"mdl-card__title-text\">" . $formTitle . "</h4>" .
                                    "<p class=\"description\">" . $msgSent . "</p></div>";

                                $sent = true;
                            }
                        } else
                            $sent = false;

                        if (!$sent) {
                            // 3. Formular ausgeben (Beginn des Formulars) //
                            echo "<div class=\"mdl-card__title headline\">
                                <h4 class=\"mdl-card__title-text\">" . $formTitle . "</h4>" .
                                "<p class=\"description\">" . $msgInfo . "</p></div>" .
                                ((isset($_POST['send'])) ? $msgError : '') .
                                "<div class=\"mdl-card__supporting-text\"><form action=\"?" . $_SERVER['QUERY_STRING'] . "\" method=\"POST\">" .
                                '<table>';

                            // Felder auslesen //
                            foreach ($fields AS $name => $settings) {
                                // Ausgabe je nach Typ //
                                switch ($settings[0]) {
                                    case 'select':
                                        // Select-Feld //
                                        echo "<tr><td class=\"contactSubject\">" . $name . ":" . (($settings[1]) ? ' (*)' : '') . "</td><td><select class=\"contactField\" name=\"" . field2url($name) . "\">";

                                        // Select-Felder auslesen //
                                        foreach ($settings[2] AS $f) {
                                            echo "<option" . ((isset($_POST[field2url($name)]) && $_POST[field2url($name)] == $f) ? ' selected' : '') . ">" . $f . "</option>";
                                        }

                                        // Ende des Select-Feldes //
                                        echo '</select></td></tr>';
                                        break;

                                    case 'text':
                                        // Einfaches Text-Feld //
                                        echo "<tr><td class=\"contactSubject\">" . $name . ":" . (($settings[1]) ? ' (*)' : '') . "</td><td><input type=\"text\" class=\"contactField\" name=\"" . field2url($name) . "\" value=\"" . ((isset($_POST[field2url($name)])) ? htmlspecialchars($_POST[field2url($name)]) : '') . "\" /></td></tr>";
                                        break;

                                    case 'textarea':
                                        // Mehrzeiliges Textfeld //
                                        echo "<tr><td class=\"contactSubject\">" . $name . ":" . (($settings[1]) ? ' (*)' : '') . "</td><td><textarea class=\"contactTextarea\" name=\"" . field2url($name) . "\">" . ((isset($_POST[field2url($name)])) ? htmlspecialchars($_POST[field2url($name)]) : '') . "</textarea></td></tr>";
                                        break;

                                    case 'checkbox':
                                        // Checkbox //
                                        echo "<tr><td class=\"contactSubject\">" . $name . ":" . (($settings[1]) ? ' (*)' : '') . "</td><td><label><input type=\"checkbox\" name=\"" . field2url($name) . "\" value=\"gesetzt\" " . ((isset($_POST[field2url($name)]) || $setttings[1]) ? 'checked ' : '') . "/> " . ((isset($settings[2])) ? $settings[2] : '') . "</td></label></tr>";
                                        break;
                                }
                            }

                            // Formular-Ausgabe abschließen und Captcha einbinden //
                            echo "<tr><td>Spam-Schutz: (*)</td><td><img src=\"" . $captchaPath . "?RELOAD=\" alt=\"Captcha\" title=\"Klicken, um das Captcha neu zu laden\" onclick=\"this.src+=1;document.getElementById('captcha_code').value='';\" width=140 height=40 /><br /><input type=\"text\" name=\"captcha_code\" id=\"captcha_code\" size=9 maxlength=5 /></td></tr></br></br>" .
                                '</table>' .
                                '<input type="text" name="email" style="display:none;" />' .
                                '<input type="hidden" name="send" value=1 />' .
                                '<p class="right"><input class="mdl-button mdl-js-button mdl-button--raised mdl-js-ripple-effect mdl-button--accent" type="submit" value="Formular abschicken" /></p>' .
                                '</form></div>';
                        }
                        ?>
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
