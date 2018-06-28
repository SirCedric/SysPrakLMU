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
<body  style="background-image: url('https://kkao6q.ch.files.1drv.com/y4mfWT-8Zk6jKX6ichUFqvR2NWcEn4iy5cyQQb6rqyGoqNhqQeGj5JoucEEyGPCC0jiw_WEzHH3RtJ_61WxOuNF_mmkBOQm5wT5UKGo2Q5NB6TwbgRDSpLO2Ebr-fu8B4BiesEovwE3JMsWKiPBlNKjw5ffF18dLX1ty-q9uz1icBtkaYHS56c_xmDY6wxra61-nNHx4iMCVd2jakQWh2gujA?width=1024&height=683&cropmode=none'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;">
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

                if ($link->connect_error) {
                    die("Connection failed: " . $link->connect_error);
                }

                $sql = "SELECT Headline, Content FROM Förderkreis WHERE id=1";
                $result = $link->query($sql);

                while($row = $result->fetch_assoc()) {
                    $Headline = $row["Headline"];
                    $ContentPart = $row["Content"];
                    //echo "id: " . $row["Headline"]. "<br>";

                    echo "<div class='mdl-card news_Card_location mdl-shadow--4dp mdl-cell mdl-cell--10-col mdl-cell--12-col-phone mdl-cell--10-col-tablet'>";
                    echo "<div class='mdl-card__title headline'>";
                    echo "<h3>$Headline</h3>";
                    echo "</div>";
                    echo "<div class='mdl-color-text--grey-700 mdl-card__supporting-text'>";
                    echo "<p>$ContentPart</p>";
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
