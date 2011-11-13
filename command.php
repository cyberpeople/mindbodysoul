<?php

$dir = "./roomba/";

switch ($_GET['command']) {
	case "FORWARD":
		echo "FORWARD";
		system($dir."forward");
		break;
	case "BACK":
		echo "BACK";
		system($dir."back");
		break;
	case "LEFT":
		echo "LEFT";
		system($dir."left");
		break;
	case "RIGHT":
		echo "RIGHT";
		system($dir."right");
		break;
	case "VERIFY":
		echo "VERIFIED\r\n<br>I'm a robot!";
		break;
	default:
		echo "Command invalid. Go away.";
		break;
}
