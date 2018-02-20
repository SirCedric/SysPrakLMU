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
        <div class="page-content">
            <div class="mdl-grid">
                <!-- Your content goes here -->
                <div class="mdl-grid">
                    <div class="mdl-layout-spacer"></div>
                    <div class="mdl-cell mdl-cell--8-col mdl-cell--8-col-tablet mdl-cell--12-col-phone">
                        <div class="demo-card-wide mdl-shadow--2dp CN_index_Main_Card">
                            <div class="mdl-card__title">
                                <h2 class="mdl-card__title-text">Forum</h2>
                            </div>
                            <div>
                                <div class="CN_index_Main_Card-text mdl-cell mdl-cell--10-col mdl-cell--10-col-tablet mdl-cell--12-col-phone">
                                    Hier entsteht das neue Forum der <b>DPSG Windrose Anzing/Poing</b>
                                </div>
                                <div class="CN_index_Main_Card-logo mdl-cell mdl-cell--2-col mdl-cell--2-col-tablet mdl-cell--0-col-phone">
                                    <img src="images/logo/stammeslogo_home.png" alt="stammeslogo_home">
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="mdl-layout-spacer"></div>
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
