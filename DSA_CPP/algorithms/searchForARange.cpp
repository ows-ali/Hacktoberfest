
/*

Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
Example:
Given [5, 7, 7, 8, 8, 10]
and target value 8,
return [3, 4].

*/




int bin_search(const vector<int> &A, int B, bool searchFirst)
{
    int l = 0, r = A.size()-1, res = -1;
    
    while(l <= r)
    {
        int mid = l + (r-l)/2;
        
        if(A[mid] == B)
        {
            res = mid;
            if(searchFirst)
                r = mid-1;
            else 
                l = mid+1;
        }
        else if(A[mid] > B)
            r = mid-1;
        else 
            l = mid+1;
    }
    
    return res;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> v;
    v.push_back(bin_search(A, B, true));
    v.push_back(bin_search(A, B, false));
    
    return v;
}


