<?php
include "config.php";

if(isset($_POST['but_import'])){
   $target_dir = "uploads/";
   $target_file = $target_dir . basename($_FILES["importfile"]["name"]);

   $imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);

   $uploadOk = 1;
   if($imageFileType != "csv" ) {
     $uploadOk = 0;
   }

   if ($uploadOk != 0) {
      if (move_uploaded_file($_FILES["importfile"]["tmp_name"], $target_dir.'importfile.csv')) {

        // Checking file exists or not
        $target_file = $target_dir . 'importfile.csv';
        $fileexists = 0;
        if (file_exists($target_file)) {
           $fileexists = 1;
        }
        if ($fileexists == 1 ) {

           // Reading file
           $file = fopen($target_file,"r");
           $i = 0;

           $importData_arr = array();
                       
           while (($data = fgetcsv($file, 1000, ",")) !== FALSE) {
             $num = count($data);

             for ($c=0; $c < $num; $c++) {
                $importData_arr[$i][] = $data[$c];
             }
             $i++;
           }
           fclose($file);

           $skip = 0;
           // insert import data
           foreach($importData_arr as $data){
              
                 $user_id = $data[0];
                 $fname = $data[1];
                 $mname = $data[2];
                 $lname = $data[3];

                 // Checking duplicate entry
                 $sql = "select count(*) as allcount from personal_details_mdb where user_id='" . $user_id . "' and first_name='" . $fname . "' and  middle_name='" . $mname . "' and last_name='" . $lname . "' ";

                 $retrieve_data = mysqli_query($con,$sql);
                 $row = mysqli_fetch_array($retrieve_data);
                 $count = $row['allcount'];

                 if($count != 0){
                    // Insert record
                    $insert_query = "insert into personal_details_mdb(user_id,first_name,middle_name,last_name) values('".$user_id."','".$fname."','".$mname."','".$lname."')";
                    mysqli_query($con,$insert_query);
                 }
              
              $skip ++;
           }
           $newtargetfile = $target_file;
           if (file_exists($newtargetfile)) {
              unlink($newtargetfile);
           }
         }

      }
   }
}
?>
 
 <html>
 <head> 
 <style>
 .popup_import{
  border: 1px solid black;
  width: 550px;
  height: auto;
  background: white;
  border-radius: 3px;
  margin: 0 auto;
  padding: 5px;
}

.format{
  color: red;
}

#userTable{
  border-collapse: collapse;
  margin: 0 auto;
  margin-top: 15px;
  width: 550px;
}

#but_import{
  margin-left: 10px;
}
</style>
</head>
<body>
<!-- Import form (start) -->
<div class="popup_import">
 <form method="post" action="" enctype="multipart/form-data" id="import_form">
  <table width="100%">

   <tr>
    <td colspan="2">
     <input type='file' name="importfile" id="importfile">
    </td>
   </tr>
   <tr>
    <td colspan="2" ><input type="submit" id="but_import" name="but_import" value="Import"></td>
   </tr>
   <tr>
    <td colspan="2" align="center"><span class="format">UID, First name, Last name,Email</span> </td>
   </tr>
   <tr>
    <td colspan="2" align="center"><a href="import_example.csv" target="_blank">Download Sample</a></td>
   </tr>

   <tr>
    <td colspan="2"><b>Instruction : </b><br/>
     <ul>
      <li>Enclose text field in quotes (' , " ) if text contains comma (,) is used.</li>
      <li>Enclose text field in single quotes (') if text contains double quotes (")</li>
      <li>Enclose text field in double quotes (") if text contains single quotes (')</li>
     </ul>
    </td>
   </tr>
  </table>
 </form>
</div>
<!-- Import form (end) -->

<!-- Displaying imported users -->
<table border="1" id="userTable">
  <tr>
   <td>UID</td>
   <td>First name</td>
   <td>Middle Name</td>
   <td>Last Name</td>
  </tr>
  <?php
    $sql = "select * from personal_details_mdb order by id desc limit 10";
    $sno = 1;
    $retrieve_data = mysqli_query($con,$sql);
    while($row = mysqli_fetch_array($retrieve_data)){
        $id = $row['user_id'];
        $fname = $row['first_name'];
        $mname = $row['middle_name'];
        $lname = $row['last_name'];

        echo "<tr>
            <td>".$id."</td>
            <td>".$fname."</td>
            <td>".$mname."</td>
            <td>".$lname."</td>

        </tr>";
        $sno++;
    }
   ?>
</table>
</body>
</html>

