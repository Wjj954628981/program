<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>网页计算器</title>
    <style type="text/css">
        #calculators {
        margin: 10% auto;
        width:430px;
        border:1px solid #000;
    }
</style>
</head>
<body>
    <div id="calculators">
        <?php
        if (is_numeric($num1) && is_numeric($num2) && $op && $result && $result != FALSE) {
                echo $num1." ".$op." ".$num2." = ".$result."<br />";
        }else {
                echo "计算错误<br />";
        }
        ?>
        <a href="/CodeIgniter">返回首页</a>
    </div>
</body>
</html>