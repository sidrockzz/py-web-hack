<?php
/*
* iTech Empires:  How to Import Data from CSV File to MySQL Using PHP Script
* Version: 1.0.0
* Page: DB Connection
*/

// Connection variables
$host = "localhost"; // MySQL host name eg. localhost
$user = "root"; // MySQL user. eg. root ( if your on local server)
$password = "NikiSiddu3014!"; // MySQL user password  (if password is not set for your root user then keep it empty )
$database = "gb_dotp"; // MySQL Database name

// Connect to MySQL Database
$con = new mysqli($host, $user, $password, $database);

// Check connection
if ($con->connect_error) {
    die("Connection failed: " . $con->connect_error);
}
?>
