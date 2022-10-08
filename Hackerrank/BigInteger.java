import java.math.BigInteger;  
import java.util.*;
import java.io.*;

public class BigIntegerExample1 {  
    public static void main(String args[]) {  
        Scanner sc=new Scanner (System.in);
        BigInteger bigInteger = new BigInteger("1");   
        int a=sc.nextInt();
        
        for (int i = 2; i<=a ; i++)
        {  
            bigInteger = bigInteger.multiply(BigInteger.valueOf(i));  
        }  
        System.out.println("Factorial of the number is : "+bigInteger); 
    }  
} 
