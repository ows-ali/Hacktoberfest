// Write a class called MyRegex which will contain a string pattern. You need to write a regular expression and assign it to the pattern such that it can be used to validate an IP address. Use the following definition of an IP address:

// IP address is a string in the form "A.B.C.D", where the value of A, B, C, and D may range from 0 to 255. Leading zeros are allowed. The length of A, B, C, or D can't be greater than 3.
// Some valid IP address:

// 000.12.12.034
// 121.234.12.12
// 23.45.12.56
// Some invalid IP address:

// 000.12.234.23.23
// 666.666.23.23
// .213.123.23.32
// 23.45.22.32.
// I.Am.not.an.ip
// In this problem you will be provided strings containing any combination of ASCII characters. You have to write a regular expression to find the valid IPs.

// Just write the MyRegex class which contains a String . The string should contain the correct regular expression.

// (MyRegex class MUST NOT be public)

// Sample Input

// 000.12.12.034
// 121.234.12.12
// 23.45.12.56
// 00.12.123.123123.123
// 122.23
// Hello.IP
// Sample Output

// true
// true
// true
// false
// false
// false


// Code in Java

import java.io.*;
import java.sql.SQLOutput;
import java.util.*;

public class Solution {

    public static boolean Checker(String str){
        boolean check = true;
        int len = str.length(), Count = 0;
        if (len > 15){
            return false;
        }
        for(int i = 0 ; i < len; i++){
            if(!Character.isDigit(str.charAt(i))){
                if(str.charAt(i) != '.') {
                    return false;
                }
            }
            if(str.charAt(i) == '.'){
                Count++;
            }
        }

        if(Count != 3) {
            return false;
        }
        int num;
        Count = 0;
        for(int i = 0; i < len ;i++){
            for(int j = i; j < len ; j++){
                if(str.charAt(j) == '.'){
                    num = Integer.parseInt(str.substring(i, j));
                    Count++;
                    i = j;
                    if(num < 0 || num > 255) {
                        return false;
                    }

                    if(Count == 3){
                        num = Integer.parseInt(str.substring(j+1, str.length()));
                        if(num < 0 || num > 255) {
                            return false;
                        }
                    }
                    i++;

                }
            }
        }
        return check;
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scan = new Scanner(System.in);

        while(scan.hasNext()){
            String ipAddress = scan.next();
            if(Checker(ipAddress)){
                System.out.println("true");
            }else{
                System.out.println("false");
            }
        }

    }
}
