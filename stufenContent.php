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
$article = $_GET["article"];
if($article == 1){
    echo "<body  style=\"background-image: url('images/Backgound/Hintergrund-Woes.jpg'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;\">";
}
if($article == 2){
    echo "<body  style=\"background-image: url('images/Backgound/Hintergrund Jupfis.jpeg'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;\">";
}
if($article == 3){
    echo "<body  style=\"background-image: url('images/Backgound/Promobild Roh 3_FarbabgleichWeich2_Schnitt.png'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;\">";
}
if($article == 4){
    echo "<body  style=\"background-image: url('images/Backgound/RoverBackground.JPG'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;\">";
}
if($article == 5){
    echo "<body  style=\"background-image: url('images/Backgound/LeiterrundeBackground.JPG'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;\">";
}

else{
    echo "<body class=\"mainColor\">";
}
?>
<div class="mdl-layout mdl-js-layout">
    <?php
    include "php-helper/header.php";
    ?>

    <main class="mdl-layout__content">
        <div class="page-content">
            <div class="mdl-grid">
                <?php
                require_once 'config.php';
                $Headline = "";
                $ContentPart = "";

                //$servername = "localhost";
                //$username = "Website";
                //$password = "Rdt-bEX-Z37-ov5";
                //$dbname = "neueSeite";
                //parameter uebergabe aus der URL
                $article = $_GET["article"];

                // Create connection
                //$conn = new mysqli($servername, $username, $password, $dbname);
                // Check connection
                if ($link->connect_error) {
                    die("Connection failed: " . $link->connect_error);
                }

                $sql = "SELECT Headline, Content FROM Stufen WHERE stufenID=$article";
                $result = $link->query($sql);

                while($row = $result->fetch_assoc()) {
                    $Headline = $row["Headline"];
                    $ContentPart = $row["Content"];
                    //echo "id: " . $row["Headline"]. "<br>";

                        echo "<div class='CN_index_Main_Card mdl-card mdl-shadow--4dp mdl-cell mdl-cell--10-col mdl-cell--10-col-tablet mdl-cell--12-col-phone'>";
                        echo "<div class='mdl-card__title'>";
                        echo "<h3>$Headline</h3>";
                        echo "</div>";
                        echo "<div class='mdl-color-text--grey-700 mdl-card__supporting-text CN_index_Main_Card-text'>";
                        echo "<p>$ContentPart</p>";
                        echo "<div class=\"mdl-card__actions mdl-card--border\">";
                        echo "<a class=\"mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect\" href=\"stufen.php\">
                            Zurück zur Übersicht
                            </a>";
                        echo "</div>";
                        echo "</div>";
                        echo "</div>";

                }
                $link->close();


                ?>

            </div>
        </div>
            <?php
            include 'php-helper/footer.php';
            ?>
    </main>
</div>
</body>
</html>
