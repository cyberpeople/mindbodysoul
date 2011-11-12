<?php

if ($_GET['command']=="back")
{
system("back");
}
elseif ($_GET['command']=="forward")
{
system("forward");
}
elseif ($_GET['command']=="turnLeft")
{
system("turnLeft");
}
elseif ($_GET['command']=="turnRight")
{
system("turnRight");
}
elseif ($_GET['command']=="verify")
{
echo('im a robot');
}
else
{
echo('invalid command');
}
?>
