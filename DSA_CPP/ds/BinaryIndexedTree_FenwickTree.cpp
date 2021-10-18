//this program contains array based implementation of Binary Indexed tree (Fenwick tree). All function names are self explanatory.

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<bits/stdc++.h>
#define lli long long int

using namespace std;

class BIT
{
    int n;
    lli *arr;
    public:
    BIT(vector<lli> v)
    {
        n = v.size();
        arr = new lli[n+1];
        memset(arr,0,sizeof(arr));

        for(int i=0;i<n;i++)
        {
            arr[i+1] = v[i];

        }

        for(int idx=1;idx<=n;idx++)
        {
            int idx2 = idx + (idx & -idx);
            if(idx2 < n+1)
                {arr[idx2] += arr[idx];

                }
        }
    }

    lli prefix_query(int idx)
    {
        ++idx;
        int sum = 0;
        for(;idx>0;idx=idx - (idx & -idx))
        {
            sum += arr[idx];
        }
        return sum;

    }

    lli range_query(int start, int end)
    {
        return prefix_query(end) - prefix_query(start-1);

    }

    void update(int idx, lli val)
    {
        ++idx;
        for(;idx<=n;idx=idx+(idx & -idx))
        {
            arr[idx]+=val;

        }
    }

    void print()
    {
        int i=0;
        for(i=1;i<=n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }

};


int main()
{
    int n;
    cin>>n;
    vector<lli> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    BIT bit(a);
    bit.print();
    cout<<bit.prefix_query(3)<<endl;
    cout<<bit.range_query(1, 4)<<endl;
    bit.update(4,2);
    bit.print();

}
