<?php
	$fp=fopen('student.txt','r');
	if(fp==null)
	{
		echo "file does not exist";
	}

	else
	{
		echo"<table border type=3 align=center>";
		echo"<tr><td align=center>Roll no</td>";
		echo"<td align=center>Name</td>";
		echo"<td align=center>Maths</td>";
		echo"<td align=center>Electronics</td>";
		echo"<td align=center>computer science</td>";
		echo"<td align=center>Total</td>";
		echo"<td align=center>Percentage</td></tr>";


		while(!feof(fp))
		{
			$d=fgets($fp);
			$s=explode(' ',$d);
			if(!empty($s[0] && $s[1]) && !empty($s[2]) && !empty($s[3]) && !empty($s[4]) )
			{
				$m1=$s[2];
				$m2=$s[3];
				$m3=$s[4];

				$total=$m1+$m2+$m3;
				$per=$total/3;
				 echo"<tr><td align=center>$s[0]</td>";
		               	 echo"<td align=center>$s[1]</td>";
               			 echo"<td align=center>$m1</td>";
               			 echo"<td align=center>$m2</td>";
               			 echo"<td align=center>$m3</td>";
               			 echo"<td align=center>$total</td>";
				 echo"<td align=center>$per</td></tr>";
			}

		}
		echo"</table";

	}





?>
