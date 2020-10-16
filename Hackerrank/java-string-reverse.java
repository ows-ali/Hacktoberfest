
import java.io.*;
import java.util.*;

public class Solution {

//Given a String A, print Yes if it is a palindrome and No if not.

static boolean isPalindrome(String str) 
    { int i = 0, j = str.length() - 1;  
        while (i < j) { 
            if (str.charAt(i) != str.charAt(j)) 
                return false;  
            i++; 
            j--; 
        } 
        return true; 
    } 

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        String A = scan.next();
        scan.close();
        
        //Is it a palindrome?
        if (isPalindrome(A)) 
            System.out.print("Yes"); 
        else
            System.out.print("No"); 
    } 
} 
