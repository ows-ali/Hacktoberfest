/**
* https://www.hackerrank.com/challenges/java-md5/copy-from/82751305
**/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.security.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        String str = new Scanner(System.in).next();
        try{
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] bt = md.digest(str.getBytes("UTF-8"));
            String str1 = "";
            
            for(byte b : bt)
                System.out.printf("%02x", b);
        
        }catch(NoSuchAlgorithmException e){
            
        }catch(UnsupportedEncodingException e){
            
        }
         
    }
}
