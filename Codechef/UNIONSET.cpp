#include <iostream>
#include <bits/stdc++.h>  
using namespace std;

int main() {
	long long int t,i,l,j,n,k,pair_count,x,y,k_count;
    cin>>t;
	for(l=0;l<t;l++)
	{
	    cin>>n>>k;
	    long long int len[n];
	    long long int set[n][10000];
	    for(i=0;i<n;i++)
	    {
	        cin>>len[i];
	        for(j=0;j<len[i];j++)
	        {
	            cin>>set[i][j];
	        }
	    }
	    for(i=0;i<n;i++)
	    {
	        sort(set[i], set[i]+len[i]);        // SORT ALL THE SETS FIRST
	    }
	    pair_count=0;
	    for(i=0;i<n-1;i++)
	    {
	        for(j=i+1;j<n;j++)
	        {
	            if((len[i]+len[j])<k)           //if total no. of elements in two pairs is <k, continue
	                continue;
	            k_count=0;
	            for(x=0,y=0 ; x<len[i] && y<len[j] ;)
	            {
	                if(set[i][x]==set[j][y])
	                {
	                    k_count++;
	                    x++;
	                    y++;
	                }
	                else if(set[i][x]<set[j][y])
	                {
	                    k_count++;
	                    x++;
	                }
	                else if(set[i][x]>set[j][y])
	                {
	                    k_count++;
	                    y++;
	                }
	            }
	            if(x==len[i] && y<len[j])
	            {
	                k_count=k_count+(len[j]-y);
	            }
	            else if(y==len[j] && x<len[i])
	            {
	                k_count=k_count+(len[i]-x);
	            }
	            if(k_count==k)
	                pair_count++;
	        }
	    }
	    cout<<pair_count<<"\n";
	}
	return 0;
}
