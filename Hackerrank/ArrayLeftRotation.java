import java.util.Scanner;
import java.util.*;
public class ArrayLeftRotation {
	public static void main(String [] args) {
		Scanner keyboard=new Scanner (System.in);
		int[] arr = new int[keyboard.nextInt()];
		int rot = keyboard.nextInt();
		//fill array
		for(int c =0; c<arr.length; c++) {
			arr[c]=keyboard.nextInt();
		}
		
		int temp=0;
		//left rotate array
		for(int c=0; c<rot; c++) {
			temp=arr[0];
			//for each rotation shift
			for(int i=0; i<arr.length-1;i++) {
			arr[i]=arr[i+1];	
			}
			arr[arr.length-1]=temp;
			
		}
		for(int a : arr) {
			System.out.print(a+"0");
		}
	}

}
