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
        <form action="index.php/calculate/count" method="post">
                <input type="text" name="num1" id="num1" />
                <select name="operate" id="operate">
                        <option value="+">+</option>
                        <option value="-">-</option>
                        <option value="x">x</option>
                        <option value="÷">÷</option>
                </select>
                <input type="text" name="num2" id="num2" />
                <input type="submit" value="计算" />
        </form>
</div>
</body>
</html>