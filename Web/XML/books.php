<?php 
    $xml = simplexml_load_file("course.xml");
    foreach($xml->computerScience as $student){
        echo htmlspecialchars($student->asXML());
        // echo "<br>Name : " . $student->StudentName;
        // echo "<br>Class : ". $student->Class;
        // echo "<br>Percentage : ". $student->percentage;
        echo "<br><hr>";
    }
?>