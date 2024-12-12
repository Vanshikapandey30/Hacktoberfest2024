<?php 

function selectionSort($arr) { 
	$n = count($arr); 
	for($i = 0; $i < $n ; $i++) { 
		$low = $i; 
		for($j = $i + 1; $j < $n ; $j++) { 
			if ($arr[$j] < $arr[$low]) { 
				$low = $j; 
			} 
		} 
		
		// Swap the minimum value to $ith node 
		if ($arr[$i] > $arr[$low]) { 
			$tmp = $arr[$i]; 
			$arr[$i] = $arr[$low]; 
			$arr[$low] = $tmp; 
		} 
	} 
	
	return $arr; 
} 

// Driver Code 
$arr = array(67, 24, 18, 26, 15); 

$sortedArr = selectionSort($arr); 

echo "Sorted Array: " . implode(" ", $sortedArr); 

?>