<?php
if( $_POST["gw_id"]) { // || $_POST["weight"] 
   #file_put_contents('test.txt', file_get_contents('php://input'));
   
      ///echo "You are ". $_POST['weight']. "kgs in weight."; 
        
   


$uploaddir = '/var/www/html/';
$uploadfile = "/var/www/html/". basename($_FILES['file']['name']);
//echo "Welcome ". $_POST['gw_id']. "  FileName". $uploadfile;


try {
   move_uploaded_file($_FILES['file']['tmp_name'], $uploadfile);
   echo $uploadfile;
  }
catch (Exception $e) {
    echo 'Caught exception: ',  $e->getMessage(), "\n";
}





   exit(); 
}
?> 
<!DOCTYPE html>
<html>
<head>
   <title>test</title>
</head>
<body>
abc
</body>
</html>
