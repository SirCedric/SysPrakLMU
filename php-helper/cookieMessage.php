<script language="javascript">
    function checkok() {
        var jetzt = new Date();
        var lebensdauer = jetzt.getTime();
        var verfall = lebensdauer + 86400;
        jetzt.setTime(verfall);
        var enddate = jetzt.toUTCString();
        document.cookie = "fuckeu = set;expires=" + enddate;
        document.getElementById("eu_cookiebox").style.display = "none";
    }
</script>