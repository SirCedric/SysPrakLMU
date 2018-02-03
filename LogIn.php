<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <meta name="description" content="A front-end template that helps you build fast, modern mobile web apps.">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, minimum-scale=1.0">
    <title>DPSG Windrose Anzing/Poing</title>

    <link rel="shortcut icon" href="images/favicon.png">

    <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
    <link rel="stylesheet" href="https://code.getmdl.io/1.3.0/material.indigo-pink.min.css">
    <script defer src="https://code.getmdl.io/1.3.0/material.min.js"></script>
</head>
<body style="background-color:cornflowerblue;">
<div class="mdl-layout mdl-js-layout">
    <?php
    include "php-helper/header.php";
    ?>
    <main class="mdl-layout__content">
        <div class="page-content"><!-- Your content goes here -->
            <div class="mdl-grid">
                <div class="mdl-layout-spacer"></div>
                <!-- Square card -->
                <style>
                    .demo-card-square.mdl-card {
                        width: 320px;
                        height: 320px;
                    }

                    .demo-card-square > .mdl-card__title {
                        color: #fff;
                        background: url('Bilder/Header_Bild.jpg') center 50% no-repeat #46B6AC;
                    }
                </style>

                <div class="demo-card-square mdl-card mdl-shadow--2dp">
                    <div class="mdl-card__title mdl-card--expand">
                        <h2 class="mdl-card__title-text">LogIn</h2>
                    </div>
                    <!-- Textfield with Floating Label -->

                    <form action="#">
                        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                            <input class="mdl-textfield__input" type="text" id="username">
                            <label class="mdl-textfield__label" for="sample3">Benutzername</label>
                        </div>
                        <!-- Textfield with Floating Label -->

                        <form action="#">
                            <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                                <input class="mdl-textfield__input" type="password" id="password">
                                <label class="mdl-textfield__label" for="sample3">Passwort</label>
                            </div>
                        </form>

                    </form>

                    <div class="mdl-card__actions mdl-card--border">
                        <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect SingIn">
                            Anmelden
                        </a>
                    </div>
                    <script type="text/javascript">
                        $('.SingIn').click(function() {

                            $.ajax({
                                type: "POST",
                                url: "LogInVerification.php",
                            })

                        });
                        if(true){
                            location.href = "index.php"
                        }
                        else {
                            //Todo Fehlermeldung
                        }
                    </script>
                </div>
                </form>
                <div class="mdl-layout-spacer"></div>
            </div>
            <?php
            include 'php-helper/footer.php';
            ?>
        </div>
    </main>
</div>

</body>
</html>
