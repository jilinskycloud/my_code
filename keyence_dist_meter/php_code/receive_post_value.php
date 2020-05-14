<?php
	try {
		if( $_POST["distance"]) // || $_POST["weight"]
		{
			echo "Received Distance is ". $_POST['distance']. " mm."; 
		}
	}
	catch (Exception $e) 
	{
		echo 'Caught exception: ',  $e->getMessage(), "\n";
	}	
?> 