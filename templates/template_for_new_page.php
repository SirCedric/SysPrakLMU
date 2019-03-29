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
          include "php-helper/headerOld.php";
      }
      ?>
      <main class="mdl-layout__content">
          <div class="page-content">
              <div class="mdl-grid">
                  <!-- Your content goes here -->
              </div>
              <?php
              include 'php-helper/footer.php';
              ?>
          </div>
      </main>
    </div>
</body>
</html>
