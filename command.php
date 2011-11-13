<?php

$dir = "./roomba/";
$command = $_GET['command'];

switch ($command) {
	case "FORWARD":
		system("/home/hell/mindbodysoul/ardrone/interface forward");
		system($dir."forward");
		break;
	case "BACK":
		system("/home/hell/mindbodysoul/ardrone/interface back");			
		system($dir."back");
		break;
	case "LEFT":
		system("/home/hell/mindbodysoul/ardrone/interface left");

		system($dir."left");
		break;
	case "LEFT45":
		system($dir."left45");
		break;
	case "RIGHT":
		system("/home/hell/mindbodysoul/ardrone/interface right");
		system($dir."right");
		break;
	case "RIGHT45":
		system($dir."right45");
		break;
	case "VERIFY":
		echo "VERIFIED\r\n<br>I'm a robot!";
		break;
	case "STOP":
		system("/home/hell/mindbodysoul/ardrone/interface stop");
		break;
	default:
		system("/home/hell/mindbodysoul/ardrone/interface stop");
		echo "Command invalid. Go away.";
		break;
}
