#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	
    // t here stands for number of test cases
    int t;
    cin >> t;
    for(int j = 0; j < t; j++)
    {
        string s;
        cin >> s;
        
        // arr is a storage array to keep the count of occurence of characters ,it is initialized to 0 initially
        int arr[26] = {};
        
        for(int i = 0; i < s.size(); i++)
        {
            arr[s[i]-65] += 1;
        }
        
        sort(arr,arr+26);
        // arr is sorted to find the characters in the string which occur maximum number of times
        
        // initially ans is intialized to INT_MAX so that minimum number of operations can be found out
        int ans = INT_MAX, count = 0;
        if(s.size()>=26)
        {
        	for(int i = 1; i <= 26; i++)
		{
        		// if size of s is a multiple of i then we can divide the string into s.size()/i different groups of characters such that all characters that occur in this string occur in it the same number of times.
            		if(s.size()%i == 0)
            		{
            	
            			// x is taken from the index i such that all the characters that have index i to 25 in the arr are taken into account
                		int x = i;
				count = 0;
                	
                		// group size of each character that can occur in the string = s.size()/i 
                		while(x)
                		{
                    			if(arr[26-x]>(s.size()/i))
                      				count = count + (arr[26-x]-(s.size()/i));
                       			x--;
                		}
                		int y = 26-i-1;
                		// all the remaining characters need to be changed
                		while(arr[y] != 0 && y >= 0)
                		{
                    			count += arr[y];
                    			y--;
                		}
                		
                		// if count is less than the current ans ,ans is replaced
                 		if(ans >= count)
            				ans = count;

            		}
        	}
        }
        else
        {
        	//all cases where group size of characters lies from 1 to s.size() is taken into account
        	for(int i = 1; i <= s.size(); i++)
        	{
            		if(s.size()%i == 0)
            		{
                		int x = i;
                		count = 0;
                		while(x)
                		{
                    			if(arr[26-x]>(s.size()/i))
                       				count = count+(arr[26-x]-(s.size()/i));
                       			x--;
                		}
                		int y = 26-i-1;
                		while(y > =0)
                		{
                   	 		count +=a rr[y];
                    			y--;
                		}
               			if(ans >= count)
            				ans=count;
            		}
        	}
        }
        cout << ans << endl;
    }
}

