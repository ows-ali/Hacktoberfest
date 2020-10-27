#include <bits/stdc++.h>
using namespace std;

// #define deb(x) cout << #x << " " << x << endl
int main()
{  
    // auto start = high_resolution_clock::now(); 
    int num,temp,count,i,length;
    vector<long long int> v,v2;
	// your code goes here
    cin >> num; 
    while(num--)
    {
        long long int n,k;
        cin >> n >> k;
        while (n--)
        {   cin >> temp;
            v.push_back(temp);
        }
   
        i = count = length = 0;
        int check = 1;
        while(count < k && i < n) 
        {   
            temp = v.at(i++);
            if (std::find(v2.begin(), v2.end(), temp) != v2.end())
                length++;
        	else 
            {
                v2.push_back(temp);		        
		        count++;
                if(count == k)
                {
                    length--;
                }
                length++;
            }
		        
		      //  cout << temp <<  count << length << endl;
       }
       cout << length << "\n" << endl;
    }
    // auto stop = high_resolution_clock::now(); 
    // auto duration = duration_cast<microseconds>(stop - start); 
    // cout << duration.count() << endl; 
    return 0;

}
