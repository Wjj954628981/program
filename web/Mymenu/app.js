/**
 * Created by lenovo on 2016/7/17.
 */
$(document).ready(function () {
    $(".main>a").click(function () {
        var ulNode=$(this).next("ul");
        // if(ulNode.css("display")=="none"){
        //     ulNode.css("display","block");
        // }else{
        //     ulNode.css("display","none");
        // }

        //JQuery实现菜单点击

        //隐藏显示方法
        //ulNode.show();
        // ulNode.hide();
        //ulNode.toggle(500);//数字、slow、normal、fast

        //滑动方法
        ulNode.slideToggle(500);//数字、slow、normal、fast
    });
    $(".hmain>a").hover(function () {
        var ulNode=$(this).next("ul");
        ulNode.slideToggle(500);
    });
});