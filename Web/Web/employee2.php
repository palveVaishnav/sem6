<?php 
    if($_SERVER['REQUEST_METHOD']=="POST"){
        session_start();
        $_SESSION['no'] = $_POST['no'];
        $_SESSION['name'] = $_POST['name'];
        $_SESSION['add'] = $_POST['add'];
    }
?>

<html>
    <body>
        <form method="POST" action="employee3.php">
            <h1>Enter Employee Details : </h1>
                Basic Earning : <input type="text" name="basic"><br>
                DA : <input type="text" name="da"><br>
                HRA : <input type="text" name="hra"><br>
            <input type="submit">
        </form>
    </body>
</html>



