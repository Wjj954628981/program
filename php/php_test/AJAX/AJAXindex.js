/**
 * Created by lenovo on 2016/7/16.
 */
$(document).ready(function () {
    $("#btn").on("click",function () {
        $.get("Server.php",{name:$("#namevalue").val()},function (data) {
            $("#result").text(data);
        });
    })
});