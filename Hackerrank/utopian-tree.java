import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args)throws IOException
    {
        int n,t,j,i,h=1;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        //System.out.println("Enter number of test cases");
        t=Integer.parseInt(br.readLine());
        if(t>=1 && t<=10)
            {
        for(i=1;i<=t;i++)
            {
            h=1;
           // System.out.println("Enter number of cycles");
            n=Integer.parseInt(br.readLine());
            for(j=1;j<=n;j++)
          {
            if(j%2==1)
                h=h*2;
            else
                h=h+1;
              }
        System.out.println(h);
        }
           
        }
    }
}

      
