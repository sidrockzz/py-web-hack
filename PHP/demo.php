<?php
$connect = mysqli_connect("localhost","root","NikiSiddu3014!","gb_dotp");
if(isset($_POST["submit"]))
{
	if($_FILES['file']['name'])
	{
		$filename=explode(".", $_FILES['file']['name']);
		if($filename[1] =='csv')
		{
			$handle = fopen($_FILES['file']['tmp_name'],"r");
			while($data = fgets($handle)!=FALSE)
			{
				$item1= mysqli_real_escape_string($connect,$data[0]);
				$item2= mysqli_real_escape_string($connect,$data[1]);
				$sql="INSERT into personal_details_mdb(user_id,first_name) values('$item1','$item2')";
				mysqli_query($connect, $sql);
			}
			fclose($handle);
			print "Import Done!!";
		}
	}
	
}

?>




<!DOCTYPE html>
<html>
	<head>
		
	</head>
	<body>
		<form method='POST' enctype ='multipart/form-data'>
			<div align="center">
				<p>Upload CSV:<input type ='file' name='file'/></p>
				<p><input type='submit' name='submit' value='Import'/></p>
			</div>
		</form>
	</body>
</html>
