<?php
	$dir=$_POST['dir'];
	$ext=$_POST['ext'];
	if(is_dir($dir))
	{
		$d=opendir($dir);
		
			echo"<h3> the file with this extension $ext in directory $dir are :</h3>";
				while(($file=readdir($d))!==false)
				{
					if(is_dir($file))
					{
						continue;
					}
					$e=explode('.',$file);
					if($e[1]==$ext)
					{
						echo"<h3>$file</h3>";
					}
				}
			closedir($d);
	}
?>

