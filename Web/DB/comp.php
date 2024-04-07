<?php 
    $host = "localhost";
    $username = "postgres";
    $password = "123456789";
    $database = "college";
    $conn = pg_connect("host=$host dbname=$database user=$username password=$password");
    if(!$conn){
        echo "Not Connected !!";
    }else{
        if($_SERVER['REQUEST_METHOD']=="POST"){
            $compName = $_POST['compName'];
            $display = isset($_POST['display']) ? true : false;
            $delete = isset($_POST['delete']) ? true : false ;

            // display 
            if($display){
                $query = "SELECT s_name FROM STUDENT WHERE s_id IN(
                            SELECT s_id FROM rel WHERE c_no IN (
                                SELECT c_no FROM COMP WHERE c_name='$compName'
                            )
                        )";
                $result = pg_query($conn,$query);
                if($result){
                    echo "<br>Names of Student for ". $compName;
                    while($row = pg_fetch_assoc($result)){
                        echo "<br>".$row['s_name'];
                    }
                }
            }
            // delete
            if($delete){
                $query2 = "DELETE from STUDENT WHERE s_id IN (
                               SELECT s_id FROM rel WHERE c_no IN(
                                SELECT c_no FROM COMP WHERE c_name = '$compName'
                               ) 
                            )";
                $result2 = pg_query($conn,$query2);
                if(!$result2){
                    echo "<br>ERROR DELETING !!";
                }else{
                    echo "<br>STUDENTS DELETED ";
                }
            }

        }
    }

?>