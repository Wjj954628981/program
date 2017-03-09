/**
 * Created by lenovo on 2016/7/16.
 */
$(document).ready(function(){
    $("body").bind("click",bodyHandler);
    $("div").bind("click",divHandler)
});

function bodyHandler(event) {
    console.log(event);
}

function divHandler(event) {
    console.log("hello");
    // event.stopPropagation();
}