<?php

	$n=$_POST['name'];
	$q=$_POST['quantity'];
	$p=$_POST['price'];
	$s=$_POST['stock'];

	class book
	{
		var $name;
		var $quantity;
		var $price;
		var $stock;

		function __construct($n,$q,$p,$s)
		{
			$this->name=$n;
			$this->quantity=(int)$q;
			$this->price=(float)$p;
			$this->stock=(int)$s;
		}

		function display()
		{
			echo "Book name:$this->name</br>";
			echo "Book quantity:$this->quantity<br>";
			echo "Book Price:$this->price</br>";
			echo "Book Stock:$this->stock</br>";
		}
	}

	$ob= new book($n,$q,$p,$s);
	$ob->display();

?>

