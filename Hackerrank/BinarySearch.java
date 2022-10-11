import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class BinarySearch
{
  private static final Scanner scanner = new Scanner(System.in);
  public static void main(String[] args) {
    int[] arr = {-3,-2,0,1,7,5,9,10,34,67,89,90};
    int target = 89;
    int res = Search(arr,target);
  }
   
  static int Search(int[] arr , int target){
    int start = 0;
    int end = arr.length-1;
    while(start <= end){
    int mid = start+(end-start)/2;
      if(target == arr[mid]){
        return mid;             // return index of target element
      }
      else if(target > arr[mid]){
        start = mid+1;
      }
      else{
        end = mid-1;
      }
    }
    return -1;
  }
}
