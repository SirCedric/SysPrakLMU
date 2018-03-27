
    <?php //echo $_GET["article"]; ?>
                <?php
                require_once 'config.php';
                $Headline = "";
                $ContentPart = "";

                //$servername = "localhost";
                //$username = "Website";
                //$password = "Rdt-bEX-Z37-ov5";
                //$dbname = "neueSeite";
                //parameter uebergabe aus der URL
                //$article = $_GET["article"];

                // Create connection
                //$conn = new mysqli($servername, $username, $password, $dbname);
                // Check connection
                if ($link->connect_error) {
                    die("Connection failed: " . $link->connect_error);
                }


                $sql = "SELECT Bild1, Headline, Content, contentID, SUBSTRING(Content,1,222) AS Content_snip, LENGTH(Content) AS Content_length FROM Aktuelles ORDER BY created DESC";


                //$sql = "SELECT Headline, Content, contentID FROM Aktuelles ORDER BY created DESC LIMIT 0,10  ";
                $result = $link->query($sql);

                while($row = $result->fetch_assoc()) {
                    if ($row['Content_length'] > 222) {
                        $ContentPart = $row['Content_snip'] . "...";
                    }
                    else {
                        $ContentPart = $row['Content_snip'];
                    }

                    $Image1 = $row["Bild1"];
                    $Headline = $row["Headline"];
                    //$ContentPart = $row["Content"];
                    $id = $row["contentID"];

                    //echo "id: " . $row["Headline"]. "<br>";

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

                }
    $link->close();


                ?>

