<?php 
    if($_SERVER['REQUEST_METHOD']=="POST"){
        setcookie("fontSize",$_POST['font_size']);
        setcookie("fontStyle",$_POST['font_style']);
        setcookie("fontColor",$_POST['font_color']);
        setcookie("background",$_POST['background']);
        header("Location: showprefrence.php");
    }
?>