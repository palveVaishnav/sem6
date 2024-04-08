<?php
$host = "localhost";
$database = "college";
$password = "123456789";
$username = "postgres";
$conn = pg_connect("host=$host dbname=$database user=$username password=$password");
if (!$conn) {
    echo "not Connected";
} else {
    if ($_SERVER['REQUEST_METHOD'] == "POST") {
        $selected = $_POST['selected'];
        if ($selected == "movie") {
            $actor = $_POST['actorName'];
            $query = "  SELECT movie_name FROM movie WHERE movie_no IN (
                                SELECT m_id FROM movieActor WHERE a_id IN (
                                    SELECT actor_no FROM Actor WHERE actor_name = '$actor'
                                )
                            )";
            $result = pg_query($conn, $query);
            if ($result) {
                echo 'Name of Movies of '. $actor .': <br>';
                while($row = pg_fetch_assoc($result)){
                    echo $row['movie_name']."<br>";
                
                }
            } else {
                echo "Try again !!";
            }
        }
        if($selected == "year"){
            $movieName = $_POST['movieName'];
            $year = $_POST['newYear'];
            $query = "UPDATE movie SET r_year='$year' WHERE movie_name='$movieName'";
            $result = pg_query($conn,$query);
            if($result){
                echo " Year Set Successfully <br>";
                $query = "SELECT * FROM movie where movie_name='$movieName'";
                $result = pg_query($conn,$query);
                echo "Updates <br>";
                while($row = pg_fetch_assoc($result)){
                    echo "<br>Movie Name : ". $row['movie_name'];
                    echo "<br>New Year : ".$row['r_year'];
                }
            }else{
                echo "Error !!";
            }





        }

    }

}
?>