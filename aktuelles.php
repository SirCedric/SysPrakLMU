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

    <?php //echo $_GET["article"]; ?>

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
                //$article = $_GET["article"];

                // Create connection
                //$conn = new mysqli($servername, $username, $password, $dbname);
                // Check connection
                if ($link->connect_error) {
                    die("Connection failed: " . $link->connect_error);
                }

                $sql = "SELECT Bild1, Bild2, Bild3, Bild4, Headline, Content FROM Aktuelles ORDER BY created DESC";
                $result = $link->query($sql);

                while($row = $result->fetch_assoc()) {
                    $Image1 = $row["Bild1"];
                    $Image2 = $row["Bild2"];
                    $Image3 = $row["Bild3"];
                    $Image4 = $row["Bild4"];
                    $Headline = $row["Headline"];
                    $ContentPart = $row["Content"];
                    //echo "id: " . $row["Headline"]. "<br>";

                    echo "<div class='mdl-card news_Card_location mdl-shadow--4dp mdl-cell mdl-cell--10-col mdl-cell--10-col-tablet mdl-cell--12-col-phone'>";
                    echo "<div class='mdl-card__title headline'>";
                    echo "<h3>$Headline</h3>";
                    echo "</div>";
                    if(!empty($Image1))echo "<img class='image_settings' src='$Image1'/>";
                    echo "<div class='mdl-color-text--grey-700 mdl-card__supporting-text'>";
                    if(!empty($ContentPart)){echo "<p>$ContentPart</p>";}
                    echo "</div>";
                    if(!empty($Image2)){echo "<img class='image_settings' src='$Image2'/>";}
                    if(!empty($Image3)){echo "<img class='image_settings' src='$Image3'/>";}
                    if(!empty($Image4)){echo "<img class='image_settings' src='$Image4'/>";}
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
