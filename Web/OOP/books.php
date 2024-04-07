<?php 
    class books{
        var $name;
        var $quantity;
        var $prize;
        var $stock;
        function __construct($n,$q,$p,$s){
            $this->name = $n;
            $this->quantity = $q;
            $this->prize = $p;
            $this->stock = $s;
        }
    }
?>

<html>
    <body>
        <form method="POST" action="">
            Enter Name : <input type="text" name="name"> <br>
            Enter Quantity : <input type="Int" name="quantity"> <br>
            Enter Prize : <input type="Int" name="prize"> <br>
            Enter Stock : <input type="int" name="stock"><br>
            <input type="submit">
        </form>
    </body>
</html>

<?php 

    if($_SERVER['REQUEST_METHOD']=="POST"){
        $name = $_POST['name'];
        $quantity = $_POST['quantity'];
        $prize = $_POST['prize'];
        $stock = $_POST['stock'];

        $book = new books($name,$quantity,$prize,$stock);
        echo "The object is created and data is stored .\n";

        echo "<br>Stored Data :<br>-------------<br>";
        echo "<br>Name : ". $book->name;
        echo "<br>Quantity : ". $book->quantity;
        echo "<br>Prize : ". $book->prize;
        echo "<br>Stock : " . $book->stock;
    }


?>

