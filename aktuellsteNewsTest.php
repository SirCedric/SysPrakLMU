<?php
require_once ('/home/www/rover/forum/SSI.php');

$array = ssi_boardNews(42.0, 5, null, null, 'array');

/*$parameters = array(
    'limit' => 5,
    'board' => array(42.0),
    'board_disp' => false,
    'category_disp' => false,
    'icon' => 'none',
    'output_type' => 'array',
);

$array = ssi_multiBoardNews($parameters);
*/
//$array = ssi_recentTopics(5, null, 42.0, 'echo');

	foreach ($array as $news)
	{
        echo "<div class='mdl-card news_Card_location mdl-shadow--4dp mdl-cell mdl-cell--10-col mdl-cell--10-col-tablet mdl-cell--12-col-phone'>";
        echo "<div class='mdl-card__title headline'>";
        echo "<h4>",$news['subject'], "</h4>";
        echo "</div>";
        echo "<div class='mdl-color-text--grey-700 mdl-card__supporting-text'>";
        echo "<p>", $news['body'], "</p>";
        /*echo "<div class=\"mdl-card__actions mdl-card--border\">";
        echo "<a class=\"mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect\" href=\"aktuellesContent.php?article=$id\">
                Mehr</a>";
        echo "</div>";*/
        echo "</div>";
        echo "</div>";
	}
	?>