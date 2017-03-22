<?php
/**
 * Created by PhpStorm.
 * User: lenovo
 * Date: 2016/7/14
 * Time: 14:59
 */

if(!isset($_POST['id'])){
    die('user id not define');
}
if(!isset($_POST['name'])){
    die('user name not define');
}

if(!isset($_POST['age'])){
    die('user age not define');
}

$id=$_POST['id'];
if(empty($id)){
    die('user id is empty');
}

$name = $_POST['name'];
if(empty($name)){
    die('user name is empty');
}

$age = $_POST['age'];
if(empty($age)){
    die('user age is empty');
}

require_once 'functions.php';

connectDb();

mysql_query("INSERT INTO users VALUE ('$id','$name','$age')");

if(mysql_errno()){
    echo mysql_error();
}else {
    header("location:allusers.php");
}