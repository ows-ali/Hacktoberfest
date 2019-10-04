#include<iostream>
using namespace std;
int main()
{
    int n,r,c;
    cin>>n;
    int arr[n][n],sum1=0,sum2=0; //sum1 for diag lt-rb sum2 for diag rt-lb
    //for diag1 i==j //for diag2 i+j == n-1
    for(r=0;r<n;r++)
    {
        for(c=0;c<n;c++)
        {
            cin>>arr[r][c];
            if(r==c)
            {
                sum1 = sum1 + arr[r][c];
            }
            if((r+c)==(n-1))
            {
                sum2 = sum2 + arr[r][c];
            }
        }
    }
    if((sum1-sum2)<0)
    {
        cout<<sum2-sum1;
    }
    else
    {
        cout<<sum1-sum2;
    }
}
