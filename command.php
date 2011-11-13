<?php

$dir = "./roomba/";
$command = $_GET['command'];

switch ($command) {
	case "FORWARD":
		system($dir."forward");
		break;
	case "BACK":
		system($dir."back");
		break;
	case "LEFT":
		system($dir."left");
		break;
	case "LEFT45":
		system($dir."left45");
		break;
	case "RIGHT":
		system($dir."right");
		break;
	case "RIGHT45":
		system($dir."right45");
		break;
	case "VERIFY":
		echo "VERIFIED\r\n<br>I'm a robot!";
		break;
	default:
		echo "Command invalid. Go away.";
		break;
}
