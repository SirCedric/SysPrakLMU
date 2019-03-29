<?php
require_once('/home/www/rover/forum/SSI.php');
?>
<!-- test -->
<style>
    .demo-layout-transparent .demo-layout-waterfall .mdl-layout__header-row .mdl-navigation__link:last-of-type {
        padding-right: 0;
    }
</style>
<!-- mdl-layout__header  -->
<div class="mdl-layout--fixed-header">
<header class="mdl-layout__header mdl-layout__header--transparent mdl-layout__header--waterfall">
    <!-- Top row, always visible -->
    <div class="mdl-layout__header-row header_color">
        <!-- Title -->
        <span class="mdl-layout-title mdl-layout--large-screen-only"><a class ="header_button" href="index.php">DPSG Windrose Anzing/Poing</a></span>
        <div class="mdl-layout-spacer"></div>
        <nav class="mdl-navigation">
            <?php

            if($context['user']['is_guest']){
                echo "<a class=\"mdl-navigation__link\" href=\"loginTest.php\">Login</a>";
            }else{
                echo "<a class=\"mdl-navigation__link\" href=\"http://widget01.mibbit.com/?settings=0f58fe8998fc0c0e5339b563adebce6f&server=chat.scoutlink.net&channel=%23deutsch&nick=guest_%3F%3F\" onclick='window.open(this.href); return false;'>Chat</a>";
                echo "<a class=\"mdl-navigation__link\" href=\"http://www.dpsg-windrose.de/index.php?action=community\">Forum</a>";
                echo "<a class=\"mdl-navigation__link\" href=\"loginTest.php\">Logout</a>";
            }
            // style="color: black"
            ?>

        </nav>

<!--        <div class="mdl-textfield mdl-js-textfield mdl-textfield--expandable
                  mdl-textfield--floating-label mdl-textfield--align-right">
            <label class="mdl-button mdl-js-button mdl-button--icon"
                   for="waterfall-exp">
                <i class="material-icons">search</i>
            </label>
            <div class="mdl-textfield__expandable-holder">
                <input class="mdl-textfield__input" type="text" name="sample"
                       id="waterfall-exp">
            </div>
        </div> -->
    </div>

</header>
</div>
<div class="mdl-layout__drawer">



    <span class="mdl-layout-title"><a class="header_button_list" href="index.php">DPSG Windrose</a></span>

    <nav class="mdl-navigation">

        <?php
        if($context['user']['is_guest']){

        }else{
            echo '<span class="mdl-layout-text center_ssi_welcome">', ssi_welcome() ,'</span>';
        }
        ?>

        <a class="mdl-navigation__link" href="aktuelles.php">News</a>
        <a class="mdl-navigation__link" href="DPSG.php">Die DPSG</a>
        <a class="mdl-navigation__link" href="stammesInfo.php">Über Uns</a>
        <a class="mdl-navigation__link" href="ausrüstung.php">Ausrüstung</a>
        <a class="mdl-navigation__link" href="zeltUndBootsverleih.php">Zelt- & Bootsverleih</a>
        <a class="mdl-navigation__link" href="förderkreis.php">Förderkreis</a>
        <a class="mdl-navigation__link" href="https://onedrive.live.com/?authkey=%21AGIouanNsyXzU0Q&id=1722EAB2D67ECA0E%211758&cid=1722EAB2D67ECA0E" onclick='window.open(this.href); return false;'>Galerie</a>

        <?php
        if($context['user']['is_guest']){

        }else{
            echo '<span class="mdl-layout-text center_ssi"><b><u>Online:</u></b></br>', ssi_whosOnline() ,'</span>';
        }
        ?>

    </nav>
</div>
