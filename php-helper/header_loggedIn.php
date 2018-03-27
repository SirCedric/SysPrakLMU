
<!-- Uses a header that contracts as the page scrolls down. -->
<style>
    .demo-layout-waterfall .mdl-layout__header-row .mdl-navigation__link:last-of-type {
        padding-right: 0;
    }
</style>

<header class="mdl-layout__header mdl-layout__header--transparent mdl-layout__header--waterfall">
    <!-- Top row, always visible -->
    <div class="mdl-layout__header-row header_color">
        <!-- Title -->
        <span class="mdl-layout-title "><a class="header_button" href="index.php">DPSG Windrose Anzing/Poing</a></span>
        <div class="mdl-layout-spacer"></div>
        <nav class="mdl-navigation">
            <a class="mdl-navigation__link" href="">Chat</a>
            <a class="mdl-navigation__link" href="forum.php">Forum</a>
            <a class="mdl-navigation__link" href="logout.php">Logout</a>
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
        <a class="mdl-navigation__link" href="aktuelles.php">News</a>
        <a class="mdl-navigation__link" href="stufen.php">Stufen</a>
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
