#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ve vector<int>
#define vl vector<long long int>
#define pb push_back
#define fo(i,a,n) for(i=a;i<n;i++)

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }
        
        int cnt=0;
        for(int i=n-1;i>0;i--)
        {
            if(arr[0][i]!=(i+1))
            {
                
                cnt++;
                
                
                
                int trans[n][n];
                
                for(int l=0;l<=i;l++)
                {
                    for(int p=0;p<=i;p++)
                    {
                        trans[p][l]=arr[l][p];
                    }
                }
                
                for(int l=0;l<=i;l++)
                {
                    for(int p=0;p<=i;p++)
                    {
                        arr[l][p]=trans[l][p];
                    }
                }
                //cout<<"heelo"<<arr[0][2]<<endl;
                
                
            }
        }
        cout<<cnt<<endl;
    }
}
