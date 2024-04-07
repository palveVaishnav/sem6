<?php
    // $host="localhost";
    // $db = "college";
    // $pass = "123456789";
    // $user = "postgres";
    // $host = "localhost";
    // $username = "postgres";
    // $password = "123456789";
    // $database = "roomer";
    $host = "dpg-cn09bf6v3ddc73c0dvv0-a.oregon-postgres.render.com";
    $username = "vaishnav";
    $password = "9KBmAiO263pC9ytCzIBE7ayPP4osHYYy";
    $database = "roomer";
    $conn = pg_connect("host=$host dbname=$database user=$username password=$password");
    if($conn){
        echo "connected";
    }else{
        echo "not Connected";
    }
?>