<?php

$productCountArray = array(2,1,2,1,2);

$sendArray1 = array('0' => array(7000, "0080"), '1' => array(1000, "0008"));

$sendArray2 = array('0' => array(6000, "0008"));

$sendArray3 = array('0' => array(2000, "-064"), '1' => array(2000, "-064"));

$sendArray4 = array('0' => array(8000, "-170"));

$sendArray5 = array('0' => array(2000, "0080"), '1' => array(1000, "0008"));


$prod_no = (int)$_REQUEST["PRO"];
$ack_no =(int)$_REQUEST["ACK"];
//$prev_yaw = 0;

if($ack_no < $productCountArray[$prod_no])	{

	switch($prod_no)
	{
	case 0:
		echo $sendArray1[$ack_no][0];
		echo $sendArray1[$ack_no][1];
		break;
	case 1:
		echo $sendArray2[$ack_no][0];
		echo $sendArray2[$ack_no][1];
		break;
	case 2:
		echo $sendArray3[$ack_no][0];
		echo $sendArray3[$ack_no][1];
		break;
	case 3:
		echo $sendArray4[$ack_no][0];
		echo $sendArray4[$ack_no][1];
		break;
	case 4:
		echo $sendArray5[$ack_no][0];
		echo $sendArray5[$ack_no][1];
		break;
	default:
		echo "NA";
	}
	
}	

if($ack_no == $productCountArray[$prod_no])
{
	echo "0000";
	switch($prod_no)
	{
	case 0:
		echo $sendArray1[$ack_no-1][1];
		break;
	case 1:
		echo $sendArray2[$ack_no-1][1];
		break;
	case 2:
		echo $sendArray3[$ack_no-1][1];
		break;
	case 3:
		echo $sendArray4[$ack_no-1][1];
		break;
	case 4:
		echo $sendArray5[$ack_no-1][1];
		break;
	
	}

	
}

echo "Data Received\n";

if($ack_no == 0 || $ack_no == $productCountArray[$prod_no] )
{
$myfile = fopen("data.json", "w") or die("Unable to open file!");

$txt = $_REQUEST["SSID0"];
$txt2 = (int)$_REQUEST["RSSI0"];

$x = array($txt => $txt2);

$txt = $_REQUEST["SSID1"];
$txt2 = (int)$_REQUEST["RSSI1"];


$x[$txt] = $txt2;
fwrite($myfile, json_encode($x));

fclose($myfile);
}


if($ack_no == $productCountArray[$prod_no] || $ack_no == 0) {

	$command = escapeshellcmd('C:\\Python27\\newProject.py');
	$room = shell_exec($command);
	//echo "1111";
	$myfile = fopen("room.txt", "w") or die("Unable to open file!");
	fwrite($myfile, $room);
	fclose($myfile);
}

//<!--meta http-equiv="refresh" //content="0;URL='http://localhost/project/display.php'"-->

?>
