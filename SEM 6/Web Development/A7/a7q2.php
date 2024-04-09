<?php
	$comp_name1=$_POST['name'];
	$comp_name2=$_POST['name1'];
	//echo $comp_name1."<br>";
	//echo $comp_name2."<br>";

	$conn=pg_connect("host=192.168.16.252 user=ty218531 dbname=ty218531 port=5432");
	if($conn)
		//echo "connected <br>";

	$query1="select name from student, competition, student_comp where student.stud_id=student_comp.stud_id and  competition.c_no=student_comp.c_no and competition.c_name='$comp_name1'";
	$query2="delete from student where stud_id in(select stud_id from student_comp,competition where student_comp.c_no=competition.c_no and c_name='$comp_name2')";

	$e1=pg_query($conn,$query1);
	$e2=pg_query($conn,$query2);
	if($e1)
		echo "Student Records:<br>";
		
	while($row=pg_fetch_row($e1))
	{
		echo $row[0]."<br>";
	}
	 
	if($e2==false)
		echo "Error";
	else
		echo "2nd query has been executed <br>";
	
	 
 
?>
