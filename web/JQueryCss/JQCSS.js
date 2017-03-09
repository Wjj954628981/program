/**
 * Created by lenovo on 2016/7/17.
 */
$(document).ready(function () {
    //单独控制css
    // $("div").css("width","100px");
    // $("div").css("height","100px");
    // $("div").css("background","#FF0000");

    //集合控制css
    // $("div").css({
    //     width:"100px",height:"100px",backgroundColor:"#00FF00"
    // });

    //css加载类
    $("div").addClass("style1");
    $("div").click(function () {
        // $(this).addClass("style2");
        $(this).toggleClass("style2");
    });

});