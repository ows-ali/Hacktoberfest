import java.io.*;
import java.util.*;

public class Prime_Checker{

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner sc = new Scanner(System.in);
         
       int[] arr = new int[5];
        
        for(int i=0; i<5 ;i++){
          arr[i]=sc.nextInt();  
        }
        
        checkPrime(arr[0]);
        System.out.println();
        checkPrime(arr[0], arr[1]);
        System.out.println();
        checkPrime(arr[0], arr[1], arr[2]);
        System.out.println();
        checkPrime(arr[0], arr[1], arr[2], arr[3], arr[4]);
        
    }
    
    static void checkPrime(int ... arr){
         for(int i=0; i<arr.length; i++){
             boolean isPrime=true;
             if(arr[i]==1){
                 continue;
             }
             for(int j=2;j<arr[i];j++){
                  if(arr[i]%j==0){
                     isPrime=false ;
                  }    
             }
             
             if(isPrime){
                 System.out.print(arr[i]+" ");
             }
             
         }    
    }
}
