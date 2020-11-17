
 // This is merge sort algorithm (uses Divide and Conquer Algorithm).
    // This is recursive implementation.This algorithm can also used to sort a segment of a array(sub array).
    private static void mergesort(int[] arr,int start,int end){
    	//base case.
        if(start>=end) return;
        // We divide our array into two halves and solve each of them => Divide and Conquer Strategy.
    	int mid=start+(end-start)/2;
        //merge sort recursively on left half
    	mergesort(arr,start,mid);
        // merge sort recursively on right half.
    	mergesort(arr,mid+1,end);
        // we merge the two sorted halves. 
    	merge(arr,start,mid,end);
    }

    private static void merge(int[] arr,int start,int mid,int end){
        // Auxilary Array.
    	int[] temp=new int[end-start+1];
        
    	int left=start,right=mid+1,tempptr=0;

    	while(left<=mid && right<=end){
            // If element of left half is small,we take it else we take right element
    		if(arr[left]<=arr[right]){
    			temp[tempptr++]=arr[left++];
    		}else{
    			temp[tempptr++]=arr[right++];
    		}
    	}
        // If left half is not completely merged.
   	    while(left<=mid){
    		temp[tempptr++]=arr[left++];
    	}
        // If right half is not completely merged.
    	while(right<=end){
    		temp[tempptr++]=arr[right++];
    	}
       
    	tempptr=0;
        // Add merged array to original array.
    	for(int k=start;k<=end;k++){
    		arr[k]=temp[tempptr++];
    	}

    }



