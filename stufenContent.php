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

                    echo "<div class='mdl-card mdl-shadow--4dp mdl-cell mdl-cell--12-col'>";
                    echo "<div class='mdl-card__title'>";
                    echo "<h3>$Headline</h3>";
                    echo "</div>";
                    echo "<div class='mdl-color-text--grey-700 mdl-card__supporting-text'>";
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
            <?php
            include 'php-helper/footer.php';
            ?>
        </div>
    </main>
</div>
</body>
</html>
