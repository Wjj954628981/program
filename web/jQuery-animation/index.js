/**
 * Created by lenovo on 2016/7/16.
 */
$(document).ready(function () {
    //隐藏显示
    $("#hide").click(function () {
        $("p").hide(1000);
    });
    $("#show").click(function () {
        $("p").show(1000);
    });
    $("#toggle1").click(function () {
        $("p").toggle(1000);
    });
    $( "#hider" ).click(function() {
        $( "span:last-child" ).hide( "fast", function() {
            // Use arguments.callee so we don't need a named function
            $( this ).prev().hide( "fast", arguments.callee );
        });
    });
    $( "#shower" ).click(function() {
        $( "span" ).show( 2000 );
    });

    //淡入淡出透明度
    $("#in").on("click", function () {
        $(".div1").fadeIn(1000);
        //多个动画同时进行
        // $(".div1").fadeIn(1000).fadeOut(1000).slideDown(1000).slideUp(1000);
    });
    $("#out").on("click", function () {
        $(".div1").fadeOut(1000);
    });
    $("#toggle2").on("click", function () {
        $(".div1").fadeToggle(1000);
    });
    $("#to").on("click",function () {
        $(".div1").fadeTo(1000,0.5);
    });

    //滑动
    $("#flipshow").click(function () {
        $("#content").slideDown(1000);
    });
    $("#fliphide").click(function () {
        $("#content").slideUp(1000);
    });
    $("#fliptoggle").click(function () {
        $("#content").slideToggle(1000);
    });
});