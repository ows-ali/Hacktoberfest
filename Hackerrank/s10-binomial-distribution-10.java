import java.io.*;
import java.util.*;

public class Solution {
    
    public static int factorial(int n) {
        
        int fact = 1;
        
        for (int i = 1; i <= n; i++) {            
            fact = fact * i;
        }
        
        return fact;
    }

    public static int combination(int n, int r)
    {
        return factorial(n)/(factorial(n-r)*factorial(r));
    }

    public static double binomial(int n, int r, double p)
    {
        return combination(n,r)* Math.pow(p,r) * Math.pow(1-p,n-r);
    }

    private static double round (double value, int precision) {
        int scale = (int) Math.pow(10, precision);
        return (double) Math.round(value * scale) / scale;
    }

    public static void main(String[] args) {        
    
        Scanner in = new Scanner(System.in);
        double per = in.nextDouble();
        int total = in.nextInt();
        double bin = per/100;
        double sum = 0;
        
        for (int i = 0 ; i<=2;i++)
        {
            sum+=binomial(total, i, bin);
        }
        System.out.println(round(sum,3));
        
        sum=0;
        for (int i = 2 ; i<=total;i++)
        {
            sum+=binomial(total, i, bin);
        }
        System.out.println(round(sum,3));
    }
}
