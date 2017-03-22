<?php
/**
 * Created by PhpStorm.
 * User: lenovo
 * Date: 2016/7/14
 * Time: 14:01
 */

require_once 'congig.php';

function connectDb(){
    $conn = mysql_connect(MYSQL_HOST,MYSQL_USER,MYSQL_PW);
    if(!$conn){
        die('Can not connect db');
    }
    mysql_select_db('PHP_test');
    return $conn;
}