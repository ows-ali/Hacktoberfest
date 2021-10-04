import java.io.*;
import java.util.*;

public class solution
{
    public static void main(String[] args){
    int n;
    Sccanner sc=new Scanner(System.in);
    n=sc.nextInt();
    
    if(n%2==0){
        if(n>=2 && n<=5)
          System.oout.println("Not Weird");
        else if(n>=6 && n<=20)
          System.oout.println("Weird");
        else
          System.oout.println("Not Weird");
          }
     else
        System.oout.println("Weird");
        
      }
  }
