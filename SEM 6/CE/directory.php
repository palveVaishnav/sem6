

<?php
	$dir=$_POST['dir'];
	$ext=$_POST['ext'];
	
	if(is_dir($dir)==false)
	{

		echo" <h3> directory does not exist</h3>";
	}
	else
	{
		$d=opendir($dir);
		
			echo"<h3> the contents of the directory are:</h3>";
				while(($file=readdir($d))!==false)
				{
					if(is_dir($file))
					{
						continue;
					}
					
						echo"<h3>$file</h3>";
	
				}
			closedir($d);
	}
?>

