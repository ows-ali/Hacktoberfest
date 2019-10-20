import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();int k = sc.nextInt();
        int [] arr = new int[k];
        
        for(int i=0;i<n;i++){
            arr[sc.nextInt()%k]++;
        }
        int result=0;
        if(k%2==0)result++;  // it will not have any conjugate pair
        result=result+Math.min(arr[0],1);//If no number wholly divisible dont add it to pair else add once
        for(int j=1;j<=k/2;j++) if(j!=k-j)result+=Math.max(arr[j],arr[k-j]);
        System.out.println(result);
     }
}
