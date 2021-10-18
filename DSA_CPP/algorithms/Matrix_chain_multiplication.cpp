#include<iostream>
#include<climits>
using namespace std;
 
int mcm(int n, int order[])
{
    int i,j,k;
    int temp;
 
    int dp[n+1][n+1];
 
    //dp[i][j] denotes the minimum number of multiplication operations requires
 
    
    //No multiplication operations will be done if the chain consists of a single matrix
    //base case
    for(i=1;i<=n;i++)
    {
        dp[i][i]=0;
    }
 
    
    for(int size=2;size<=n;size++)
    {
        //i is the first matrix of the chain
        for(i=1;i<=(n-size+1);i++)
        {
            //j is the first matrix of the chain
            j=i+size-1;
            
            //intializing
            dp[i][j]=INT_MAX;
 
            
            for(k=i;k<j;k++)
            {
                //dp formula for mcm
                temp=dp[i][k]+dp[k+1][j]+order[i-1]*order[k]*order[j];
 
                
                if(temp<dp[i][j])
                {
                    dp[i][j]=temp;
                }
            }
 
        }
 
    }
 
    //return the min. operations required
    return dp[1][n];
 
}
int main()
{
    int i,j;
    int n;
 
    cout<<"Enter the number of matrices in the chain(< 1)  ";
    cin>>n;
 
    int order[n+1];
 
    //order of matrix i will be given by order[i-1]*order[i]
    cout<<"Enter the order array of the matrix chain ("<<n+1<<" elements)"<<endl;
    for(i=0;i<=n;i++)
    {
        cin>>order[i];
    }
 
    cout<<"The minimum number of multiplication operations required to multiply the matrix chain is "<<mcm(n,order);
 
    cout<<endl;
    return 0;
}