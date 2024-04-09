<?php
 $colors=array('black'=>'#000000','white'=>'#ffffff','red'=>'#ff0000','blue'=>'#0000ff');
$bg_color=$_POST['bg'];
$ft_color=$_POST['fc'];
setcookie('bg',$colors[$bg_color]);
setcookie('fc',$colors[$ft_color]);
?>
<html>
<body>
CHANGES MADE ARE <BR>
BACKGROUND: <?=$bg_color?><br>
FONT COLOR : <?=$ft_color?><br>
<br>
Click<a href="ass41_demo.php">HERE</a>
<br>

to see the result
</body>
</html>

