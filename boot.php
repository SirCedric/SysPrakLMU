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
<!-- <body  style="background-image: url('https://lkdfrg.ch.files.1drv.com/y4mrViCcEx3m5wmLvaEBYnF1hWZoy6QuPTXEKEfFgM4BmejcJO43Mynpzsf_c3iQWaNKZa-c_NBbx3ILWE9x6MauH8Y4mMzuOMewjvIUCdL-ckktXnSSeFmqkVjhZwE3aAMJ8wRx0Z9ueRbbvj8aw15U4M7Zi6G8R631Z-bvVfEuPWkE48rsNOidDP6hwQvnY9f35Uf3HgtvlRkOHziFjFw6Q?width=400&height=239&cropmode=none'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;"> -->
<body class="mainColor">
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

                $sql = "SELECT Headline, Content FROM ZeltBoot WHERE id=2";
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
                    echo "<div class=\"mdl-card__actions mdl-card--border\">";
                    echo "<a class=\"mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect\" href=\"zeltUndBootsverleih.php\">
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
