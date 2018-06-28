    <?php
    require_once('/home/www/rover/forum/SSI.php');
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
<body id="body" style="background-image: url('https://mqcpxq.ch.files.1drv.com/y4mblKTqV6zMdykEhlm-WffJsz4qO1NUgJEl0wYpLBzrxr1rXC9lYObu9XcLajgRmCvvh1b59wRghoW-G4qQ3M-xqG3go4OJINC0MtN3lT8JZfpbw6W1PwADtLgTc1ZTFyeoz86mPxvTK0PL3ilQkKJ9Bm1wPePSqxb9CM7UJNttx3O6jRV3wpdFSg181cU_QWpg9HLmfXc607gJIggCfiMNA?width=1024&height=683&cropmode=none'); background-repeat: no-repeat; width: 100%; height: 100%; background-position: center;background-repeat: no-repeat;background-size: cover;">
<div class="mdl-layout mdl-js-layout">
    <?php
    include "php-helper/headerTest.php";
    ?>

    <main class="mdl-layout__content">
        <div class="page-content"><!-- Your content goes here -->
            <div class="mdl-grid">
<?php
include 'aktuellesTest.php';
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
