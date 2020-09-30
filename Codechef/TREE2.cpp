#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        set<int> s;
        int n;
        cin>>n;
        int temp;
        while(n--)
        {   
            cin>>temp;
            if(temp!=0)
            s.insert(temp);
        }
        cout<<s.size()<<endl;
        
    }
    
}
