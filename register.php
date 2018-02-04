<?php
// Include config file
require_once 'config.php';

// Define variables and initialize with empty values
$username = $password = $confirm_password = "";
$username_err = $password_err = $confirm_password_err = "";

// Processing form data when form is submitted
if($_SERVER["REQUEST_METHOD"] == "POST"){

    // Validate username
    if(empty(trim($_POST["username"]))){
        $username_err = "Please enter a username.";
    } else{
        // Prepare a select statement
        $sql = "SELECT id FROM users WHERE username = ?";

        if($stmt = mysqli_prepare($link, $sql)){
            // Bind variables to the prepared statement as parameters
            mysqli_stmt_bind_param($stmt, "s", $param_username);

            // Set parameters
            $param_username = trim($_POST["username"]);

            // Attempt to execute the prepared statement
            if(mysqli_stmt_execute($stmt)){
                /* store result */
                mysqli_stmt_store_result($stmt);

                if(mysqli_stmt_num_rows($stmt) == 1){
                    $username_err = "This username is already taken.";
                } else{
                    $username = trim($_POST["username"]);
                }
            } else{
                echo "Oops! Something went wrong. Please try again later.";
            }
        }

        // Close statement
        mysqli_stmt_close($stmt);
    }

    // Validate password
    if(empty(trim($_POST['password']))){
        $password_err = "Please enter a password.";
    } elseif(strlen(trim($_POST['password'])) < 6){
        $password_err = "Password must have atleast 6 characters.";
    } else{
        $password = trim($_POST['password']);
    }

    // Validate confirm password
    if(empty(trim($_POST["confirm_password"]))){
        $confirm_password_err = 'Please confirm password.';
    } else{
        $confirm_password = trim($_POST['confirm_password']);
        if($password != $confirm_password){
            $confirm_password_err = 'Password did not match.';
        }
    }

    // Check input errors before inserting in database
    if(empty($username_err) && empty($password_err) && empty($confirm_password_err)){

        // Prepare an insert statement
        $sql = "INSERT INTO users (Username, Password) VALUES (?, ?)";

        if($stmt = mysqli_prepare($link, $sql)){
            // Bind variables to the prepared statement as parameters
            mysqli_stmt_bind_param($stmt, "ss", $param_username, $param_password);

            // Set parameters
            $param_username = $username;
            $param_password = password_hash($password, PASSWORD_DEFAULT); // Creates a password hash

            // Attempt to execute the prepared statement
            if(mysqli_stmt_execute($stmt)){
                // Redirect to login page
                header("location: logIn.php");
            } else{
                echo "Something went wrong. Please try again later.";
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
                        height: 600px;
                    }

                    .demo-card-square > .mdl-card__title {
                        /*color: #fff*/;
                        background: url('Bilder/stammeslogo.png') center 50% no-repeat white;
                        color: black;
                    }
                </style>

                <div class="demo-card-square mdl-card mdl-shadow--2dp">
                    <div class="mdl-card__title mdl-card--expand">
                        <h2 class="mdl-card__title-text">Registrieren</h2>
                    </div>

    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label <?php echo (!empty($username_err)) ? 'has-error' : ''; ?>">
            <input type="text" name="username"class="mdl-textfield__input" value="<?php echo $username; ?>">
            <label class="mdl-textfield__label" for="username">Benutzername</label>
            <span class="help-block"><?php echo $username_err; ?></span>
        </div>
        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label <?php echo (!empty($password_err)) ? 'has-error' : ''; ?>">
            <input type="password" name="password" class="mdl-textfield__input" value="<?php echo $password; ?>">
            <label class="mdl-textfield__label" for="password">Passwort</label>
            <span class="help-block"><?php echo $password_err; ?></span>
        </div>
        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label <?php echo (!empty($confirm_password_err)) ? 'has-error' : ''; ?>">
            <input type="password" name="confirm_password" class="mdl-textfield__input" value="<?php echo $confirm_password; ?>">
            <label class="mdl-textfield__label" for="password">Passwort bestätigen</label>
            <span class="help-block"><?php echo $confirm_password_err; ?></span>
        </div>
        <div class="mdl-card__actions mdl-card--border">
            <input type="submit" class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect Register" value="Submit">
            <input type="reset" class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect Register" value="Reset">
        </div>
        <p>Bereits registriert? <a href="logInVerification.php">Hier gehts zur Anmeldung</a>.</p>
    </form>
</div>
                <div class="mdl-layout-spacer"></div>
            </div>
            <?php
            include 'php-helper/footer.php';
            ?>
        </div>
    </main>
</body>
</html>