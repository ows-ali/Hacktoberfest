import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    public static void main(String args[])
    {
        Scanner obj=new Scanner(System.in);
        String s=obj.nextLine();
        int s1=0,f=0,d=0,g=0;
        int b[]=new int[26];
        int c[]=new int[26];
        char o;
        
    
        for(int i=0;i<s.length();i++)
        {
            o=s.charAt(i);
            b[(int)(o)-97]++;
        }
        for(int i=0;i<26;i++)
        {
    
            if(b[i]!=0)
            {
                d=b[i];
                break;
            }
            
            
        }
        for(int i=0;i<26;i++)
        {
            if(b[i]!=d&&b[i]!=0)
            {
                g++;
            }
            if(g==2)
            break;
    
            
        }
        
        
        if(g<=1)
        
            System.out.println("YES");
            else
            System.out.println("NO");
        
    }
}
