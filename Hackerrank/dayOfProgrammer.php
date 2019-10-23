<?php

// Complete the dayOfProgrammer function below.
function dayOfProgrammer($year) {
    $tday;
    $mn = "09";
    if($year>=1919){
        if($year%4 != 0) {
            $mday = 243;
        }
        else {
            if($year%400 != 0 && $year%100 == 0) {
                $mday = 243;
            } else {
                $mday = 244;
            }
        }
    }
    elseif ($year == 1918) {

        $mday = 243-13;
    }
     else {
        if($year%4 == 0) {
            $mday = 244;
        }
        else {
            $mday = 243;
        }
    }

    $dp = 256-$mday;

    $str = $dp.".".$mn.".".$year;

    return $str;

}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$year = intval(trim(fgets(STDIN)));

$result = dayOfProgrammer($year);

fwrite($fptr, $result . "\n");

fclose($fptr);
