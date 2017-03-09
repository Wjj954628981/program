/**
 * Created by lenovo on 2016/7/22.
 */
var valueSpan,slider;
$(document).ready(function () {
    // $("#slider").slider();
    slider = $("#slider");
    valueSpan = $("#span");

    //数值在进度条变化后变化
    // slider.slider({
    //     change:function (event,ui) {
    //         valueSpan.text(slider.slider("option","value"))
    //     }
    // });

    //数值随进度条实时变化
    slider.slider({
        slide:function (event,ui) {
            valueSpan.text(slider.slider("option","value"))
        }
    });
});