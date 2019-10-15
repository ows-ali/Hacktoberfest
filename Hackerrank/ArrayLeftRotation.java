import java.util.Scanner;
import java.util.*;
	class RotateArray{
	void leftRotate(int arr[], int d, int n)
	{
		int i,j,k,temp;
		int g_c_d = gcd(d,n);
		for (i=0; i<g_c_d; i++) 
		{
			temp = arr[i];
			j=i;
			while(true)
			{
				k = j + d;
				if (k>=n)
					k = k-n;
				if (k==i)
					break;
				arr[j] = arr[k];
				j=k;
			}
			arr[j] = temp;
		}
	}
		
		
	int gcd(int a, int b)
	{
		if (b==0)
			return a;
		else
			return gcd(b, a%b);
	}
		
	public static void main(String [] args) {
		
		RotateArray rotate = new RotateArray();
		
		Scanner keyboard=new Scanner (System.in);
		int[] arr = new int[keyboard.nextInt()];
		int rot = keyboard.nextInt();
		//fill array
		for(int c =0; c<arr.length; c++) {
			arr[c]=keyboard.nextInt();
		}
		
		rotate.leftRotate(arr, rot, arr.length);
		
		for(int a : arr) {
			System.out.print(a+"0");
		}
	}

}
