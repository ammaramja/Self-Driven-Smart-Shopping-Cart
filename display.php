<h1>
<?php

$f=fopen("room.txt","r");
$a = fread($f,filesize("room.txt"));
echo "Cart is in";
echo $a;
?>
</h1>