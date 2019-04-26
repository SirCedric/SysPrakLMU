<div class="page-content" id="content-wrap"><!-- Your content goes here -->
    <div class="mdl-cell mdl-cell--10-col mdl-cell--10-col-tablet mdl-cell--8-col-phone">
        <div class="mdl-grid">
            <!-- Square card -->
            <style>
                <!--
                .demo-card-square.mdl-card {
                    width: 465px;
                    height: 400px;
                }

                -->

                .demo-card-square > .mdl-card__title {
                    /*color: #fff*/;
                    background: url('Bilder/stammeslogo.png') center 50% no-repeat white;
                    color: black;
                }
            </style>

            <div class="mdl-layout-spacer"></div>
            <div class="mdl-layout-spacer"></div>


            <?php

            if ($context['user']['is_guest']) {
                echo '<div class="demo-card-square mdl-card mdl-shadow--2dp">';
                echo '<div class="mdl-card__title mdl-card--expand">';
                echo '<div class="mdl-layout-spacer"></div>';
                echo '<h2 class=" center mdl-card__title-text">LogIn</h2>';
                echo '<div class="mdl-layout-spacer"></div>';
                echo '</div>';
                echo '<span class="center_ssi_logout" style="color: black;">', ssi_login(), '</span>';
                echo '<p class="center">Noch nicht registriert? <a href="http://www.dpsg-windrose.de/index.php?action=register">Jetzt Account erstellen</a>.</p>';
                echo '</div>';

            } else {
                echo '<div class="center demo-card-square mdl-card mdl-shadow--2dp">';
                echo '<div class="center mdl-card__title mdl-card--expand">';
                echo '<div class="mdl-layout-spacer"></div>';
                echo '<h2 class="center mdl-card__title-text">Logout</h2>';
                echo '<div class="mdl-layout-spacer"></div>';
                echo '</div>';
                echo '<span class="center center_ssi_logout" style="color: black;">', ssi_logout(), '</span>';
                echo '</div>';
            }
            ?>
            <div class="mdl-layout-spacer"></div>
        </div>
    </div>
</div>