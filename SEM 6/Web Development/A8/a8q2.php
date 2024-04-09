<?php
	$r=$_POST['radius'];
	$s=$_POST['side'];
	$l=$_POST['length'];
	$b=$_POST['breadth'];


	interface ar
	{
		function area();
	}
	
	class rectangle implements ar
	{
		var $len;
		var $br;
		function rectangle($l,$b)
		{
			$this->len=$l;
			$this->br=$b;
		}

		function area()
		{
			$area=$this->len*$this->br;
			echo "Area of rectangle of is ".$area."<br>";
		}
	}

	class square extends rectangle
	{
		var $side;
		function square($s)
		{
			$this->side=$s;
		}

		function area()
		{
			$area=$this->side*$this->side;

			echo "Area of square is ".$area."<br>";
		}
	}

	class circle implements ar
	{
		var $rs;
		function circle($s)
		{
			$this->rs=$s;
		}

		function area()
		{
			$area= 3.14 * $this->rs * $this->rs;

			echo "Area of circle is ".$area;
		}
	}

	$r1= new rectangle($l,$b);
	$s1= new square($s);
	$c1= new circle($r);

	$r1->area();
	$s1->area();
	$c1->area();


?>
