<?php
require_once ('/home/www/rover/forum/SSI.php');

$array = ssi_boardNews(42.0, 100, null, null, 'array');

//42.0,
//$array = ssi_recentTopics($num_recent = 8, $exclude_boards = null, $include_boards = null, $output_method = 'echo');

foreach ($array as $news)
{
    echo "<div class='mdl-card news_Card_location mdl-shadow--4dp mdl-cell mdl-cell--10-col mdl-cell--10-col-tablet mdl-cell--12-col-phone'>";
    echo "<div class='mdl-card__title headline'>";
    echo "<h4>",$news['subject'], "</h4>";
    echo "</div>";
    echo "<div class='mdl-color-text--grey-700 mdl-card__supporting-text'>";
    echo "<p>", $news['body'], "</p>";
    echo "</div>";
    echo "</div>";
}
?>