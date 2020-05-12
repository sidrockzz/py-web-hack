<?php
function getdb(){
$servername = "localhost";
$username = "root";
$password = "NikiSiddu3014!";
$db = "gb_dotp";

try {
   
    $conn = mysqli_connect($servername, $username, $password, $db,);
     //echo "Connected successfully"; 
    }
catch(exception $e)
    {
    echo "Connection failed: " . $e->getMessage();
    }
    return $conn;
}
//getdb();
?>
