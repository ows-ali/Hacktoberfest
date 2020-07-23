package FirstProgram;

public class MergeSort {
	private static void Sort(int arr[], int low, int high)
	{
		if(low<high)
		{
			int mid = low + (high-low)/2;
			Sort(arr, low, mid);
			Sort(arr, mid+1, high);
		
			Merge(arr, low, mid, high);
		}
		else
		{return;}
	}
	private static void Merge(int arr[], int low, int mid, int high)
	{
		int leftarray[]=new int[mid-low+1];
		int rightarray[]=new int[high-mid];
		
		for(int i=0; i<leftarray.length; i++) {
			leftarray[i]=arr[low+i];
		}
		for(int i=0; i<rightarray.length; i++) {
			rightarray[i]=arr[mid+1+i];
		}
		int leftindex=0,rightindex=0;
		for(int i=low; i<high+1; i++)
		{
			if(leftindex<leftarray.length && rightindex<rightarray.length)
			{
				if(leftarray[leftindex]<rightarray[rightindex])
				{
					arr[i] = leftarray[leftindex];
					leftindex++;
				}
				else
				{
					arr[i] = rightarray[rightindex];
					rightindex++;
				}
			}
			else if(leftindex<leftarray.length)
			{
				arr[i]=leftarray[leftindex];
				leftindex++;
			}
			else if(rightindex<rightarray.length)
			{
				arr[i]=rightarray[rightindex];
				rightindex++;
			}
		}
	}

	public static void main(String[] args) 
	{
		int arr[] = {4,6,0,8,32,36,4,67,0,12,4};
		Sort(arr, 0, 10);
		for(int a:arr)
		{
			System.out.print(a + " ");
		}

	}

}
