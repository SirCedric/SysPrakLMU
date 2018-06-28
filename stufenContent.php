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
    echo "<body  style=\"background-image: url('https://kqcbag.ch.files.1drv.com/y4m0tzQHJ-FfuQUkzc0uOGou-TlM_4KcSsfL2mRYXUtjGbJYKYTlrC2W7FsejoLIFFDnebEFANXxK8_roxlsyqhDvzTXACPic_Is63Pzlb70eJAtxQmks11EmLs2N8D4AWoDXAOIVaBsInA1nce1JpgAwuQK0GjBkvXtcAaIdmkk4ivbpNtwvjN6z-c6XhEyh3aWtqmX_X1pONoWjozAVpRgQ?width=1024&height=768&cropmode=none'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;\">";
}
if($article == 2){
    echo "<body  style=\"background-image: url('https://kkcbag.ch.files.1drv.com/y4mEJu-kDjzelGLzHO2zGvSBCw0NKH6OETHOsLEjxEi5eZA2DealgHT3K97kZOt0n_LHUuwxWOC5SOU4fissmXrnIPJoIRql27qU4Nu3RnoGBG7uG3ztAmna-87mmg4yLLcN8-2o5TEEzQGGfeLRi-7BC8dxG0GQ7bc08Ay5X1wkryL84Odk9G9jYGPBICxX0wplJga4tZc7eTkeP0ZezdLJw?width=1024&height=576&cropmode=none'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;\">";
}
if($article == 3){
    echo "<body  style=\"background-image: url('https://k6dfrg.ch.files.1drv.com/y4mSNn7v0_r0D29hd47eF-dwEYUYGNzPanJ0HfInLJkHuQagLoTiQMIyCsX_P6G8rfJFQuC-MnQai9azvOioSy_aqlPhOWvKb8fJ6C0urbTCrcBgA9XDAxkvrqt-Cc9BuMg0KaQJ2Yv2edL_VzLtokX1MRMnds3zmzUWPhFXaZGeUUVw-f7r8o_RBY8Z10BLyGxQGwT9cRjwJKPfc0Y1hHCzQ?width=1024&height=619&cropmode=none'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;\">";
}
if($article == 4){
    echo "<body  style=\"background-image: url('https://lacpxq.ch.files.1drv.com/y4mdgDiwj3QDxcrbA3l7Dz3W8qwb5IX1WuskMmcL3lNqLJOIcaeBbweKW3ars1L1tuTNiB07mLmxcDXRWz0WqYdfOxJFnl6MYf-8CJNs599jbG8CMu7yoz644cWO2qUspyf8KtgoxozDQvJh-kRxfAm3ndLqTRhq81JjzGl2qWkYb4z_3IpykpUzQH32OHRXU6qjLj1T2cesSH-VamAfmc4CQ?width=1024&height=683&cropmode=none'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;\">";
}
if($article == 5){
    echo "<body  style=\"background-image: url('https://jqao6q.ch.files.1drv.com/y4mn_jmESbgppSJLwhwSVtWaxkW1AuUfJuAo81mkrLhCi_gLyawiokaSLXDAVQOh_btN440pNOEA_m58lr9CpHyKZIGFaP6ezvbNTFDaZYrfQXknrUSj0KvWNor5NdjBZY19cHqCthrKGMyyLSXldrKp3gnz2ztqUihh8TwR8WrIxxArW4b5CDSE80OVIsKwuhre8dflzohUtsMffcel2h7hw?width=1024&height=683&cropmode=none'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;\">";
}

else{
    echo "<body class=\"mainColor\">";
}
?>
<div class="mdl-layout mdl-js-layout">
    <?php
    include "php-helper/headerTest.php";
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
