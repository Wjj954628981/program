<DOCTYPR html>
    <html>
    <head>
        <meta charset="UTF-8">
        <title>连接数据库</title>
    </head>
    <body>
<?php
/**
 * Created by PhpStorm.
 * User: lenovo
 * Date: 2016/7/14
 * Time: 13:51
 */

$conn=mysql_connect('localhost:3306','root','1996wangjiajie.');

if($conn){
    mysql_select_db('PHP_test',$conn);

    $result = mysql_query("SELECT * FROM users");
    $result_arr = mysql_fetch_array($result);

    print_r($result_arr);
}else{
    echo'连接失败';
}
?>
    </body>
    </html>