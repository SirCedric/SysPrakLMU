<?php
// Include config file
require_once 'config.php';

// Define variables and initialize with empty values
$username = $password = "";
$username_err = $password_err = "";

// Processing form data when form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // Check if username is empty
    if (empty(trim($_POST["username"]))) {
        $username_err = 'Please enter username.';
    } else {
        $username = trim($_POST["username"]);
    }

    // Check if password is empty
    if (empty(trim($_POST['password']))) {
        $password_err = 'Please enter your password.';
    } else {
        $password = trim($_POST['password']);
    }

    // Validate credentials
    if (empty($username_err) && empty($password_err)) {
        // Prepare a select statement
        $sql = "SELECT Username, Password FROM users WHERE Username = ?";

        if ($stmt = mysqli_prepare($link, $sql)) {
            // Bind variables to the prepared statement as parameters
            mysqli_stmt_bind_param($stmt, "s", $param_username);

            // Set parameters
            $param_username = $username;

            // Attempt to execute the prepared statement
            if (mysqli_stmt_execute($stmt)) {
                // Store result
                mysqli_stmt_store_result($stmt);

                // Check if username exists, if yes then verify password
                if (mysqli_stmt_num_rows($stmt) == 1) {
                    // Bind result variables
                    mysqli_stmt_bind_result($stmt, $username, $hashed_password);
                    if (mysqli_stmt_fetch($stmt)) {
                        if (password_verify($password, $hashed_password)) {
                            /* Password is correct, so start a new session and
                            save the username to the session */
                            session_start();
                            $_SESSION['username'] = $username;
                            header("location: index.php");
                        } else {
                            // Display an error message if password is not valid
                            $password_err = 'Das Passwort war nicht korrekt!';
                        }
                    }
                } else {
                    // Display an error message if username doesn't exist
                    $username_err = 'Dieser Nutzername existiert nicht!';
                }
            } else {
                echo "Oops! Something went wrong. Please try again later.";
            }
        }

        // Close statement
        mysqli_stmt_close($stmt);
    }

    // Close connection
    mysqli_close($link);
}
?>


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
    <link rel="stylesheet" href="css/main.css">
    <script defer src="https://code.getmdl.io/1.3.0/material.min.js"></script>
</head>
<body class="mainColor">
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
                        height: 420px;
                    }

                    .demo-card-square > .mdl-card__title {
                        /*color: #fff*/;
                        background: url('Bilder/stammeslogo.png') center 50% no-repeat white;
                        color: black;
                    }
                </style>

                <div class="demo-card-square mdl-card mdl-shadow--2dp">
                    <div class="mdl-card__title mdl-card--expand">
                        <h2 class="mdl-card__title-text">LogIn</h2>
                    </div>
                    <!-- Textfield with Floating Label -->

                    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
                        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label  <?php echo (!empty($username_err)) ? 'has-error' : ''; ?>">
                            <input type="text" name="username" class="mdl-textfield__input" value="<?php echo $username; ?>">
                            <label class="mdl-textfield__label" for="username">Benutzername</label>
                            <span class="help-block"><?php echo $username_err; ?></span>
                        </div>
                        <!-- Textfield with Floating Label -->


                        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label <?php echo (!empty($password_err)) ? 'has-error' : ''; ?>">
                            <input class="mdl-textfield__input" name="password" type="password">
                            <label class="mdl-textfield__label" for="sample3">Passwort</label>
                            <span class="help-block"><?php echo $password_err; ?></span>
                        </div>
                        <p>Noch nicht registriert? <a href="register.php">Jetzt Account erstellen</a>.</p>
                        <div class="mdl-card__actions mdl-card--border">
                            <input type="submit"
                                   class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect SingIn"
                                   value="Login">
                        </div>
                    </form>
                </div>
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