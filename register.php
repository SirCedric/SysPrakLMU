<?php
// Include config file
require_once 'config.php';

// Define variables and initialize with empty values
$username = $firstname = $lastname = $password = $email = $confirm_password = "";
$username_err = $firstname_err = $lastname_err = $password_err = $email_err = $confirm_password_err = "";
define('users', 'users');

// Processing form data when form is submitted
if($_SERVER["REQUEST_METHOD"] == "POST") {

    // Vorname
    if(empty(trim($_POST['firstname']))){
        $firstname_err = "Bitte gib deinen Vornamen ein";
    }else{
        $firstname = trim($_POST['firstname']);
    }

    // Nachname
    if(empty(trim($_POST['lastname']))){
        $lastname_err = "Bitte gib deinen Nachnamen ein";
    }else{
        $lastname = trim($_POST['lastname']);
    }

    // E-Mail
    /*if(empty(trim($_POST['email']))){
        $email_err = "Bitte gib deine E-Mailadresse ein";
    }else{
        $email = trim($_POST['email']);
    }*/


    // E-Mail
    if(empty(trim($_POST["email"]))){
        $email_err = "Bitte gib deine E-Mailadresse ein";
    }else{
        $sql = "SELECT ID FROM users WHERE Mail = ?";

        if ($stmt = mysqli_prepare($link, $sql)) {
            // Bind variables to the prepared statement as parameters
            mysqli_stmt_bind_param($stmt, "s", $param_email);

            // Set parameters
            $param_email = trim($_POST['email']);

            // Attempt to execute the prepared statement
            if (mysqli_stmt_execute($stmt)) {
                /* store result*/
                mysqli_stmt_store_result($stmt);

                if (mysqli_stmt_num_rows($stmt) == 1) {
                    $email_err = "Diese E-Mailadresse existiert bereits.";
                } else {
                    $email = trim($_POST['email']);
                }
            } else {
                echo "Hoppla! Da ist wohl etwas schief gelaufen. Probiers bitte später nochmal.";
            }
        }

        // Close statement
        mysqli_stmt_close($stmt);
    }

    // Validate username
    if (empty(trim($_POST["username"]))) {
        $username_err = "Bitte gib einen Nutzernamen ein.";
    } else {
        // Prepare a select statement
        $sql = "SELECT ID FROM users WHERE Username = ?";

        if ($stmt = mysqli_prepare($link, $sql)) {
            // Bind variables to the prepared statement as parameters
            mysqli_stmt_bind_param($stmt, "s", $param_username);

            // Set parameters
            $param_username = trim($_POST['username']);

            // Attempt to execute the prepared statement
            if (mysqli_stmt_execute($stmt)) {
                /* store result */
                mysqli_stmt_store_result($stmt);

                if (mysqli_stmt_num_rows($stmt) == 1) {
                    $username_err = "Dieser Nutzername existiert bereits.";
                } else {
                    $username = trim($_POST['username']);
                }
            } else {
                echo "Hoppla! Da ist wohl etwas schief gelaufen. Probiers bitte später nochmal.";
            }
        }

        // Close statement
        mysqli_stmt_close($stmt);
    }

    // Validate password
    if (empty(trim($_POST['password']))) {
        $password_err = "Please enter a password.";
    } elseif (strlen(trim($_POST['password'])) < 6) {
        $password_err = "Password must have atleast 6 characters.";
    } else {
        $password = trim($_POST['password']);
    }

    // Validate confirm password
    if (empty(trim($_POST["confirm_password"]))) {
        $confirm_password_err = 'Please confirm password.';
    } else {
        $confirm_password = trim($_POST['confirm_password']);
        if ($password != $confirm_password) {
            $confirm_password_err = 'Password did not match.';
        }
    }

    // Check input errors before inserting in database
    if (empty($lastname_err) && empty($firstname_err) && empty($email_err) && empty($username_err) && empty($password_err) && empty($confirm_password_err)) {

        $param_password = password_hash($password, PASSWORD_DEFAULT);
        // Prepare an insert statement
        $sql_Username_Password = "INSERT INTO users(Username, Password, Firstname, Lastname, Mail) VALUES ('$username', '$param_password', '$firstname', '$lastname', '$email')";

        $sql_email = "INSERT INTO users(Mail) VALUES ()";

        mysqli_query($link, $sql_Username_Password);
        mysqli_query($link, $sql_email);

        header("location: LogIn.php");
       /* if ($stmt = mysqli_prepare($link, $sql)) {
            // Bind variables to the prepared statement as parameters
            mysqli_stmt_bind_param($stmt, "sssss", $param_firstname, $param_lastname, $param_username, $param_password, $param_email);

            // Set parameters
            $param_username = $username;
            $param_password = password_hash($password, PASSWORD_DEFAULT); // Creates a password hash
            $param_lastname = $lastname;
            $param_firstname = $firstname;
            $param_email = $email;

            // Attempt to execute the prepared statement
            if (mysqli_stmt_execute($stmt)) {
                // Redirect to Homepage
                header("location: index.php");
            } else {
                echo "Es ist etwas schief gelaufen :( Probiers später nochmal ;)";
            }

        // Close statement
        mysqli_stmt_close($stmt);
        }*/


        // Close connection
        mysqli_close($link);
        mysqli_close($link);
    }
    else{
        echo "Es ist etwas schief gelaufen :( Probiers später nochmal ;)";
    }
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
    session_start();
    if(isset($_SESSION['username'])){
        include "php-helper/header_loggedIn.php";
    }else {
        include "php-helper/special_Header_Login.php";
    }
    ?>
    <main class="mdl-layout__content">
        <div class="page-content"><!-- Your content goes here -->
            <div class="mdl-grid">
                <div class="mdl-layout-spacer"></div>
                <!-- Square card -->
                <style>
                    .demo-card-square.mdl-card {
                        width: 320px;
                        height: 750px;
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

    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="POST">
        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label <?php echo (!empty($firstname_err)) ? 'has-error' : ''; ?>">
            <input type="text" name="firstname"class="mdl-textfield__input" value="<?php echo $firstname; ?>">
            <label class="mdl-textfield__label" for="firstname">Vorname</label>
            <span class="help-block"><?php echo $firstname_err; ?></span>
        </div>

        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label <?php echo (!empty($lastname_err)) ? 'has-error' : ''; ?>">
            <input type="text" name="lastname"class="mdl-textfield__input" value="<?php echo $lastname; ?>">
            <label class="mdl-textfield__label" for="lastname">Nachname</label>
            <span class="help-block"><?php echo $lastname_err; ?></span>
        </div>

        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label <?php echo (!empty($username_err)) ? 'has-error' : ''; ?>">
            <input type="text" name="username"class="mdl-textfield__input" value="<?php echo $username; ?>">
            <label class="mdl-textfield__label" for="username">Benutzername</label>
            <span class="help-block"><?php echo $username_err; ?></span>
        </div>

        <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label <?php echo (!empty($email_err)) ? 'has-error' : ''; ?>">
            <input type="text" name="email"class="mdl-textfield__input" value="<?php echo $email; ?>">
            <label class="mdl-textfield__label" for="email">E-Mail</label>
            <span class="help-block"><?php echo $email_err; ?></span>
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
        <p>Bereits registriert? <a href="LogIn.php">Hier gehts zur Anmeldung</a>.</p>
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