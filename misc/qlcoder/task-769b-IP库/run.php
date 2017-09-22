<?php
include("./taobaoip/src/city.php");
$fname="./taobaoip/ip.data";
$fileh=fopen($fname,"r");
$fsize=filesize($fname);
$bytes=fread($fileh,$fsize);
$hangzhou=0;
$beijing=0;
$shanghai=0;
$shenzhen=0;
for ($p24=0; $p24<(1<<24); $p24++) {
	$loc = $p24 * 5;
	if ($loc >= $fsize) {
		break;
	}
	if ($p24 % 100000 == 0) {
		echo $p24."\n";
	}
	$city_id1=ord($bytes[$loc+2]);
	$city_id2=ord($bytes[$loc+3]);
	$city_id=$city_id1*256+$city_id2;
	$cityname=$city[$city_id];
	if ($cityname=="杭州市") {
		$hangzhou++;
	} else
	if ($cityname=="北京市") {
		$beijing++;
	} else
	if ($cityname=="上海市") {
		$shanghai++;
	} else
	if ($cityname=="深圳市") {
		$shenzhen++;
	}
}
echo 256*$hangzhou.",";
echo 256*$beijing.",";
echo 256*$shanghai.",";
echo 256*$shenzhen."\n";
?>
