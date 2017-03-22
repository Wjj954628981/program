<?php
require_once 'functions.php';
?>
<DOCTYPE html>
    <html>
    <head>
        <meta charset="UTF-8">
        <title>所有用户</title>
    </head>
    <body>
    <a href="adduser.html">添加用户</a>
    <?php
    $conn = connectDb();
    $result = mysql_query("SELECT * FROM users ORDER BY id ASC");
    $dataCount = mysql_num_rows($result);

    echo "<table style='text-align: left;' border='1'>
<tr><th>id</th><th>名字</th><th>年纪</th></tr>";
    for($i=0;$i<$dataCount;$i++){
        $result_arr = mysql_fetch_assoc($result);

        $id = $result_arr['id'];
        $name = $result_arr['name'];
        $age = $result_arr['age'];

        echo "<tr><th>$id</th><th>$name</th><th>$age</th></tr>";
    }

    echo "</table>";
    ?>
    </body>
    </html>