<?php
    Interface Area{
        function area(); 
    }
    class rectangle implements Area{
        public $len;
        public $bdh;
        function __construct($l,$b){
            $this->len = $l;
            $this->bdh = $b;
        }
        function area(){
            return $area = $this->len * $this->bdh;
        }
    }
    class square extends rectangle{
        public $side;
        function __construct($side){
            $this->side = $side;
        }
        function area(){
            return $area = $this->side * $this->side;
        }
    }
    class circle  implements Area{
        public $radius;
        function __construct($r){
            $this->radius = $r;
        }
        function area(){
            return $area = 3.14 * $this->radius * $this->radius;
        }
    }
?>

<html>
    <body>
        <form method = "POST" action="">
            <h1>Square </h1><br>
            Enter Side : <input type="int" name="side"><br>
            <h1>Circle</h1>
            Enter Radius : <input type="int" name="radius"><br>
            <h1>Rectangle</h1>
            Enter Length : <input type="int" name="length"><br><br>
            Enter Breadth : <input type="int" name="breadth"><br>
            <br>
            <input type="submit">
        </form>
    </body>
</html>

<?php 
    if($_SERVER['REQUEST_METHOD']=="POST"){
        $side = $_POST['side'];
        $radius = $_POST['radius'];
        $len = $_POST['length'];
        $bth = $_POST['breadth'];
        
        $r = new rectangle($len,$bth);
        $s = new square($side);
        $c = new circle($radius);

        echo "AREAS :<br>";
        echo "<br>Rectangle : ". $r->area();
        echo "<br>Square : " . $s->area();
        echo "<br>Circle : ". $c->area();

    }

?>



