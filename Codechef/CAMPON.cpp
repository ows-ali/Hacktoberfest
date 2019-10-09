#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
	    int d,q;
	    cin>> d;
	    int a1[d],a2[d];
	    for(int j=0;j<d;j++)
	    {
	        cin>>a1[j]>>a2[j];
	    }
	    cin>>q;
	    int b1[q],b2[q];
	    for(int j=0;j<q;j++)
	    {
	        cin>>b1[j]>>b2[j];
	        int noq=0;
	        for(int k=0;k<d;k++) 
	        {
	            if(a1[k]<=b1[j])
	            noq=noq+a2[k];
	            else break;
	        }
	        if(b2[j] > noq)
	        cout<<"Go Sleep"<<endl;
	        else cout<<"Go Camp"<<endl;
	    }
	}
	return 0;
}
