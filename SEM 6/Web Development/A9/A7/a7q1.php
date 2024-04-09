<?php

$a_name=$_POST['name'];
$m_name=$_POST['movie'];
$release_year=$_POST['year'];
echo $a_name."<br>";

echo $m_name."<br>";

echo $release_year."<br>";


$db=pg_connect("host=192.168.16.252 user=ty218531 dbname=ty218531 port=5432");
if($db)
	echo "connected <br>";
$query="select movie_name from movie where movie_no in(select movie_no from movie_actor where actor_no=(select actor_no from actor where name='$a_name'))";
$q="update movie set release_year='$release_year' where movie_name='$m_name'";

$res=pg_query($db,$query);
$res2=pg_query($db,$q);
if($res)
	echo " 1st query is executed <br>";
if($res2)
	echo "2nd query is executed <br>";

while($row=pg_fetch_row($res))
{
	echo $row[0]."<br>";
	echo"<br>";
}



?>
