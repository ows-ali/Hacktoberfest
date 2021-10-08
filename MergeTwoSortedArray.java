import java.io.*;
import java.util.*;

public class Main {

  public static int[] mergeTwoSortedArrays(int[] a, int[] b){
    //write your code here
    int [] rt=new int [a.length+b.length];
    int i=0;
    int j=0;
    int k=0;
    while(i<a.length && j<b.length){
      if(a[i]<b[j]){
          rt[k]=a[i];
          i++;
          k++;
      }
      else{
          rt[k]=b[j];
          j++;
          k++;
      }
      
        
    }
    while(i<a.length){
       rt[k]=a[i];
          i++;
          k++; 
    }
    while(j<b.length){
         rt[k]=b[j];
          j++;
          k++;
    }
    
    
    return rt;
  }

  public static void print(int[] arr){
    for(int i = 0 ; i < arr.length; i++){
      System.out.println(arr[i]);
    }
  }
  public static void main(String[] args){
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int[] a = new int[n];
    for(int i = 0 ; i < n; i++){
      a[i] = scn.nextInt();
    }
    int m = scn.nextInt();
    int[] b = new int[m];
    for(int i = 0 ; i < m; i++){
      b[i] = scn.nextInt();
    }
    int[] mergedArray = mergeTwoSortedArrays(a,b);
    print(mergedArray);
  }

}
