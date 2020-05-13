<?php
include('connection.php');
$con = getdb();


if(isset($_POST["Import"])){
		$con = getdb();

		echo $filename=$_FILES["file"]["tmp_name"];
		 if($_FILES["file"]["size"] > 0)
		 {
		  	$file = fopen($filename, "r");
		  	$getData = fgetcsv($file, 10000, ",");
	         while (($getData = fgetcsv($file, 10000, ",")) !== FALSE)
	         {
                   $getData = str_replace("'","''",$getData);
	           $sql = "INSERT into 'personal_details_mdb' ('user_id','first_name') 
	            	VALUES('$getData[0]','$getData[1]')";
				
		 $result = $con->query($sql);
		  		var_dump($result);	
		  		 exit();
	         //we are using mysql_query function. it returns a resource on true else False on error
	          
				if(!$result)
				{
					echo "<script type=\"text/javascript\">
							alert(\"Invalid File:Please Upload CSV File.\");
							window.location = \"index.php\"
						</script>";		
				}

	         }
	         fclose($file);
	         //throws a message if data successfully imported to mysql database from excel file
	         echo "<script type=\"text/javascript\">
						alert(\"CSV File has been successfully Imported.\");
						window.location = \"index.php\"
					</script>";	
			var_dump($sql);
		 }
		
		
	}	 
	
	 if(isset($_POST["Export"])){
		 
      header('Content-Type: text/csv; charset=utf-8');  
      header('Content-Disposition: attachment; filename=data.csv');  
      $output = fopen("php://output", "w");  
      fputcsv($output, array('ID', 'First Name'));  
      $query = "SELECT user_id, first_name from personal_details_mdb ORDER BY user_id DESC";  
      $result = mysqli_query($con, $query);  
      while($row = mysqli_fetch_assoc($result))  
      {  
           fputcsv($output, $row);  
      }  
      fclose($output);  
 }  
	
function get_all_records(){
    $con = getdb();

    $Sql = "SELECT * FROM perosnal_details_mdb";
    $result = mysqli_query($con, $Sql);  

    if (mysqli_num_rows($result) > 0) {
     echo "<div class='table-responsive'><table id='myTable' class='table table-striped table-bordered'>
     <thead>
     <tr>
 
				  		<th>User ID</th>
				  		<th>First Name</th>
                        </tr></thead><tbody>";

     while($row = mysqli_fetch_assoc($result)) {


         echo "<tr><td>" . $row['user_id']."</td>
                   <td>" . $row['first_name']."</td></tr>";
         
     }
	//  echo "<tr> <td><a href='' class='btn btn-danger' id='status_btn' data-loading-text='Changing Status..'>Export</a></td></tr>";
     echo "</tbody></table></div>";
	 
} else {
     echo "you have no recent pending orders";
}
}



?>
