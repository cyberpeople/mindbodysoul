<?php
echo $_GET['command'];
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
else
{
echo('invalid command');
}
?>
