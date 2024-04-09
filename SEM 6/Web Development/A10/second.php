<?php
   setcookie('eno',$_POST['eno']);
   setcookie('enm',$_POST['enm']);
   setcookie('eadd',$_POST['eadd']);
?>
<html>
<body>
 
<form action="third.php" method="POST">
<center>
<h2> Enter earnings of employee:</h2>
<table>
<tr><td>Basic: </td>
<td><input type="text" name="e1"></td></tr>
<tr><td>DA: </td>
<td><input type="text" name="e2"></td></tr>
<tr><td>HRA: </td>
<td><input type="text" name="e3"></td></tr>
<tr><td></td><td><input type="submit" value=next></td></tr>
</table>
</center>
</form>
</body>
</html>



