<?php 
    if($_SERVER['REQUEST_METHOD']=="POST"){
        session_start();
        $_SESSION['basic'] = $_POST['basic'];
        $_SESSION['da'] = $_POST['da'];
        $_SESSION['hra'] = $_POST['hra'];

        echo "<h1>Entered Details : </h1>";
        echo "<br>Employee No : ". $_SESSION['no'];
        echo "<br>Employee name : ". $_SESSION['name'];
        echo "<br>Employee Address : ". $_SESSION['add'];
        echo "<br>Employee Basic : ". $_SESSION['basic'];
        echo "<br>Employee DA : ". $_SESSION['da'];
        echo "<br>Employee HRA : ". $_SESSION['hra'];

    }
?>
