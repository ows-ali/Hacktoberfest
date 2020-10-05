import java.io.*;

public class NextSmallerElement {

	/* prints element and NSE pair for 
	all elements of arr[] of size n */
  // USING STACK : 
	static void printNSE(int arr[], int n) 
	{ 
        Stack<Integer> stk = new Stack<>();
        
        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && arr[i]<arr[stk.peek()])
                arr[stk.pop()]= arr[i];
            stk.push(i);
        }
        
        while(!stk.empty())
            arr[stk.pop()]= -1;
        
        StringBuffer sb = new StringBuffer();
        for(int ele : arr)
            sb.append(ele+" ");
        
        System.out.println(sb);
  }
  
/*        
BRUTE FORCE APPROACH : { TC=O(n^2) }
int next, i, j; 
for(i = 0; i < n; i++) 
{ next = -1; 
  for (j = i + 1; j < n; j++) 
  { if (arr[i] > arr[j]) 
    { 
		  next = arr[j]; 
		  break; 
    } 
  } 
  System.out.println(arr[i] + " --> " + next);
} 
*/
	public static void main(String args[]) 
	{ 
		int arr[] = { 13,14,15,2 }; 
		int n = arr.length; 
		printNSE(arr, n); 
	} 
} 
