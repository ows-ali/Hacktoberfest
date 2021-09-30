
import java.util.*;

public class DigitSumInArray{

public static void main(String[] args) throws Exception {
    // write your code here
    Scanner sc = new Scanner(System.in);
   
    int size1 = sc.nextInt();    
    int [] arr1 = new int[size1];    
    for(int i=0;i<arr1.length;i++){
        arr1[i] = sc.nextInt();
    }
    
    int size2 = sc.nextInt();
    int [] arr2 = new int[size2];
    for(int i=0;i<arr2.length;i++){
        arr2[i] = sc.nextInt();
    }
    sc.close();	
    
    int max_length = (size1>size2)? size1:size2;    
    int [] arr3 = new int[max_length];
    
    int i= arr1.length-1;
    int j= arr2.length-1;
    int k= arr3.length-1;
    int carry = 0;
    
    while(i>=0 && j>=0){
    
    	int temp = arr1[i]+arr2[j];
        
        if(((temp+carry)/10)>0){
            arr3[k] = ((temp+carry)%10);
            carry = (temp+carry)/10;
            k--;
            i--;
            j--;            
        }else{
            arr3[k] = temp;
            k--;
            i--;
            j--;            
        }
    }
    while(i>=0){
        if((arr1[i]+carry)/10>0){
            arr3[k] = (arr1[i]+carry)%10;
            carry = (arr1[i]+carry)/10;
            i--;k--;
        }else {
        	arr3[k] = arr1[i];
        	i--;k--;
        }
    }
     while(j>=0){
        if((arr2[j]+carry)/10>0){
            arr3[k] = (arr2[j]+carry)%10;
            carry = (arr2[j]+carry)/10;
            j--;k--;
        }else {
        	arr3[k]= arr2[j];
        	j--;k--;
        }
    }
    for(int val : arr3){
        System.out.print(val);
    }
  }
}
