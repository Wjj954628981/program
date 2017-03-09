/**
 * Created by lenovo on 2016/7/17.
 */
$(document).ready(function () {
    $("#tabfirst li").each(function (index) {
        var liNode = $(this);
        $(this).mouseover(function () {
            timeouttid=setTimeout(function () {
                $("div.content").removeClass("content");
                $("#tabfirst li.tabin").removeClass("tabin");
                $("div").eq(index).addClass("content");
                liNode.addClass("tabin");
            },300);
        }).mouseout(function () {
            clearTimeout(timeouttid);
        });
    });
});