<?php
require_once ('/home/www/rover/forum/SSI.php');

$array = ssi_boardNews(42.0, 5, null, null, 'array');

	foreach ($array as $news)
	{
		/*echo '
			<table border="0" width="100%" align="center" class="ssi_table">
				<tr>
					<td><b>', $news['subject'], '</b></td>
				</tr>
				<tr>
					<td>', $news['body'], '<br /><br /></td>
				</tr>
			</table>
			<br />';

		if (!$news['is_last'])
			echo '
			<hr width="100%" />
			<br />';*/
        echo "<div class='mdl-card news_Card_location mdl-shadow--4dp mdl-cell mdl-cell--10-col mdl-cell--10-col-tablet mdl-cell--12-col-phone'>";
        echo "<div class='mdl-card__title headline'>";
        echo "<h3>",$news['subject'], "</h3>";
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

	/**
    echo "<div class='mdl-card news_Card_location mdl-shadow--4dp mdl-cell mdl-cell--10-col mdl-cell--10-col-tablet mdl-cell--12-col-phone'>";
    echo "<div class='mdl-card__title headline'>";
    echo "<h3>$Headline</h3>";
    echo "</div>";
    if(!empty($Image1))echo "<img class='image_settings' src='$Image1'/>";
    echo "<div class='mdl-color-text--grey-700 mdl-card__supporting-text'>";
    if(!empty($ContentPart)){echo "<p>$ContentPart</p>";}
    echo "<div class=\"mdl-card__actions mdl-card--border\">";
    echo "<a class=\"mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect\" href=\"aktuellesContent.php?article=$id\">
    Mehr
    </a>";
    echo "</div>";
    echo "</div>";
    echo "</div>";
     */
	?>