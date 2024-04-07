<html>
    <body>
        <form method="POST" action="">
            Enter Directory : <input type="text" name="dir"><br>
            Enter Extension : <input type="text" name="ext"><br>
            <input type="submit">
        </form>
    </body>
</html>

<?php 
    if($_SERVER['REQUEST_METHOD']=="POST"){
        $dirName = "../" . $_POST['dir'];
        $ext = $_POST['ext'];
        if(is_dir($dirName)){
            $dir = opendir($dirName);
            while(($entry = readdir($dir))){
                if(!is_dir($entry)){
                    $element = explode('.',$entry);
                    // print_r($element);
                    if($element[1]==$ext){
                        echo "<br>File Name : " . $entry;
                        echo "<br>Size : ". filesize($dirName.'/'.$entry);
                        echo "<br> Last Access : ". date("d-m-y H:i:s",fileatime($dirName.'/'.$entry)) ;
                    }
                }
            }
        }else{
            echo "Enter Correct Directory !!";
        }
    }
?>

