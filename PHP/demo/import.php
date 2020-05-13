<?php
/*
* iTech Empires:  How to Import Data from CSV File to MySQL Using PHP Script
* Version: 1.0.0
* Page: Import.PHP
*/

// Database Connection
require 'db_connection.php';

$message = "";
if (isset($_POST['submit'])) {
    $allowed = array('csv');
    $filename = $_FILES['file']['name'];
    $ext = pathinfo($filename, PATHINFO_EXTENSION);
    if (!in_array($ext, $allowed)) {
        // show error message
        $message = 'Invalid file type, please use .CSV file!';
    } else {

        move_uploaded_file($_FILES["file"]["tmp_name"], "files/" . $_FILES['file']['name']);

        $file = "files/" . $_FILES['file']['name'];

        $query = <<<eof
        LOAD DATA LOCAL INFILE '$file'
         INTO TABLE personal_details_mdb
         FIELDS TERMINATED BY ','
         LINES TERMINATED BY '\n'
         IGNORE 1 LINES
        (user_id,first_name)
eof;
        if (!$result = mysqli_query($con, $query)) {
            exit(mysqli_error($con));
        }
        $message = "CSV file successfully imported!";
    }
}

// View records from the table
$users = '<table class="table table-bordered">
<tr>
    <th>Name</th>
    <th>No</th>
</tr>
';
$query = "SELECT user_id,first_name FROM personal_details_mdb";
if (!$result = mysqli_query($con, $query)) {
    exit(mysqli_error($con));
}
if (mysqli_num_rows($result) > 0) {
    $number = 1;
    while ($row = mysqli_fetch_assoc($result)) {
        $users .= '<tr>
            <td>' . $row['first_name'] . '</td>
            <td>' . $row['user_id'] . '</td>
        </tr>';
        $number++;
    }
} else {
    $users .= '<tr>
        <td colspan="4">Records not found!</td>
        </tr>';
}
$users .= '</table>';
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Import Data from CSV File to MySQL Tutorial</title>
    <!-- Bootstrap CSS File  -->
    <link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap.min.css"/>
</head>
<body>
<div class="container">
    <h2>
        Tutorial: How to Import Data from CSV File to MySQL Using PHP
    </h2>
    <br><br>

    <div class="row">
        <div class="col-md-6 col-md-offset-0">
            <form enctype="multipart/form-data" method="post" action="import.php">
                <div class="form-group">
                    <label for="file">Select .CSV file to Import</label>
                    <input name="file" type="file" class="form-control">
                </div>
                <div class="form-group">
                    <?php echo $message; ?>
                </div>
                <div class="form-group">
                    <input type="submit" name="submit" class="btn btn-primary" value="Submit"/>
                </div>
            </form>
            <div class="form-group">
                <?php echo $users; ?>
            </div>
        </div>
    </div>
</div>
</body>
</html>
