
     // This is quick sort Algorithm(recursive implementation).
    private static void quicksort(int[] arr,int start,int end){
        //base case.
    	if(start>=end) return;
        // You can choose any element as pivot(like start,end,any random index).
    	int pivot=arr[start];
        // we partition the array into two parts where one is with elements less than or equal to pivot element and other has all elements greater than or equal to pivot element.
    	int left=start+1,right=end;

    	while(left<=right){
            // If left element is smaller than pivot element and right element is larger than pivot then swap them.
    		if(arr[left]>pivot && arr[right]<pivot){
    			swap(arr,left,right);
    		}
            // If left is smaller than pivot left+=1 as it is in correct position.
  		    if(arr[left]<=pivot){
    			left++;
    		}
            // If right is greater than pivot right-=1 as it is in correct position.
    		if(arr[right]>=pivot){
    			right--;
    		}
    	}

    	swap(arr,start,right);
        //quick sort recursively on left part. 
    	quicksort(arr,start,right);
        //quick sort recursively on right part. 
    	quicksort(arr,right+1,end);

    }
    
    private static void swap(int[] arr,int i,int j){
    	int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }