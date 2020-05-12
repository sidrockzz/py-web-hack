<?php

$host = "localhost"; /* Host name */
$user = "root"; /* User */
$password = "NikiSiddu3014!"; /* Password */
$dbname = "gb_dotp"; /* Database name */

$con = mysqli_connect($host, $user, $password,$dbname);
// Check connection
if (!$con) {
  die("Connection failed: " . mysqli_connect_error());
}
else{
echo "Connection Success";
}
