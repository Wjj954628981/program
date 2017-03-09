/**
 * Created by lenovo on 2016/7/22.
 */
$(document).ready(function () {
    $("#div").draggable();

    $("#rect1").draggable();
    $("#rect2").droppable();
    $("#rect2").on("drop",function (event,ui) {
        $("#rect2").text("drop事件");
    });

    $("#div2").resizable();

    $("#btn").button();
    $("#select").selectable();
    $("#btn").on("click",function () {
        if($("#right").hasClass("ui-selected")){
            alert("恭喜你答对了!");
        }
    });

    $("#sortable").sortable();
});