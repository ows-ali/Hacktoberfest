/*PROBLEM:-
Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers.
Then print the respective minimum and maximum values as a single line of two space-separated long integers.*/
import java.util.*;
public class minmax
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
       long a[]=new long[5];
        int i;
        long s=0,min=9223372036854775807L,max=0;
        for(i=0;i<5;i++)
        {
            a[i]=sc.nextLong();
            if(a[i]>max)
            max=a[i];
            if(a[i]<min)
            min=a[i];
            s=s+a[i];
        }
        System.out.print(s-max+" ");
        System.out.print(s-min);
    }
}
