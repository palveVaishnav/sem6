<?php 
    $fp = fopen("student.dat","r");
    if(!$fp){
        echo "File not Found !!";
    }else{
        echo "<h1>The Student Details </h1>";
        echo "<table border='4'>
                <tr>
                    <th>Roll no </th>
                    <th>Name </th>
                    <th> Maths </th>
                    <th> Electronics </th>
                    <th> Computer </th>
                    <th> Total </th>
                    <th> Per </th>
                </tr>
        ";
        while(!feof($fp)){
            $arr = fgetcsv($fp);
            echo "<br>";
            if($arr){
                echo "<tr>";
                echo "<td>".$arr[0]."</td>";
                echo "<td>".$arr[1]."</td>";
                echo "<td>".$arr[2]."</td>";
                echo "<td>".$arr[3]."</td>";
                echo "<td>".$arr[4]."</td>";
                $total = $arr[2] + $arr[3] + $arr[4];
                $per = ($total/150)*100;
                echo "<td>". $total ."</td>";
                echo "<td>". $per ."</td>";
                echo "</tr>";
            }
        }
        echo "</table>";
    }
    fclose($fp);
?>
