
<!-- Uses a header that contracts as the page scrolls down. -->
<style>
    .demo-layout-waterfall .mdl-layout__header-row .mdl-navigation__link:last-of-type {
        padding-right: 0;
    }
</style>

<header class="mdl-layout__header mdl-layout__header--waterfall">
    <!-- Top row, always visible -->
    <div class="mdl-layout__header-row">
        <!-- Title -->
        <span class="mdl-layout-title "><a class="header_button" href="index.php">DPSG Windrose</a></span>
        <div class="mdl-layout-spacer"></div>
        <nav class="mdl-navigation">
            <a class="mdl-navigation__link" href="">Chat</a>
            <a class="mdl-navigation__link" href="">Forum</a>
        </nav>
        <div class="mdl-textfield mdl-js-textfield mdl-textfield--expandable
                  mdl-textfield--floating-label mdl-textfield--align-right">
            <label class="mdl-button mdl-js-button mdl-button--icon"
                   for="waterfall-exp">
                <i class="material-icons">search</i>
            </label>
            <div class="mdl-textfield__expandable-holder">
                <input class="mdl-textfield__input" type="text" name="sample"
                       id="waterfall-exp">
            </div>
        </div>
    </div>

</header>
<div class="mdl-layout__drawer">
    <span class="mdl-layout-title"><a class="header_button" href="index.php">DPSG Windrose</a></span>

    <nav class="mdl-navigation">
        <div class="demo-card-square mdl-card header_login">
          <div class="mdl-card__title mdl-card--expand">
            <h2 class="mdl-card__title-text">Login</h2>
          </div>
          <div class="mdl-card__supporting-text">
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
                <p>Noch nicht registriert? </p>
                <p><a href="register.php">Jetzt Account erstellen</a>.</p>
                <div class="mdl-card__actions mdl-card--border">
                    <input type="submit"
                           class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect SingIn"
                           value="Login">
                </div>
            </form>
          </div>
        </div>

        <a class="mdl-navigation__link" href="LogIn.php">LogIn</a>
        <a class="mdl-navigation__link" href="">Stufen</a>
        <a class="mdl-navigation__link" href="">Stamm</a>
        <a class="mdl-navigation__link" href="">Ausrüstung</a>
        <a class="mdl-navigation__link" href="">Zelt- & Bootsverleih</a>
        <a class="mdl-navigation__link" href="">Förderkreis</a>
        <a class="mdl-navigation__link" href="https://onedrive.live.com/?authkey=%21AGIouanNsyXzU0Q&id=1722EAB2D67ECA0E%211758&cid=1722EAB2D67ECA0E">Galerie</a>
    </nav>
</div>
<main class="mdl-layout__content">
    <div class="page-content"><!-- Your content goes here --></div>
</main>
