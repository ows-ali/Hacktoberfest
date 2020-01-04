import java.util.*;

public class Solution {

public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int[] a= new int[3]; //creating array
    for (int i=0;i<3;i++)
        //Assigning values to array from stdin
        a[i] = scan.nextInt();
    scan.close();
    for(int j=0;j<3;j++)
        //Printing array values to stdout
        System.out.println(a[j]);
    }
}
