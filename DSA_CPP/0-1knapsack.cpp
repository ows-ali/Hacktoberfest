#include<iostream>
using namespace std;

struct item
{
	int w;
	int price;
};
int unbounded_knapsack(int n,int w,item a[])
{
	int profit1,profit2;
	profit1=profit2=0;
	if(n==0||w==0)
	{
			return 0;
	}
	if(w-a[n-1].w>=0)
	{
		profit1=a[n-1].price+unbounded_knapsack(n,w-a[n-1].w,a);
	}
	profit2=unbounded_knapsack(n-1,w,a);
	return max(profit1,profit2);
}

//top down DP hw


//bottom UP DP
int bounded_knapsackBottomUpDP(int n,int w,item a[])
{
	int dp[100][100];
	for(int i=0;i<=n;i++)//i here denotes the item i==0 means 0 items
	{
		for(int j=0;j<=w;j++)//j here denotes the current capacity of the bag
		{
			if(i==0||j==0)
			{
				dp[i][j]=0;
			}
			else
			{
				int inc=0,exc=0;
				if(a[i-1].w<=j)
				{
					inc=a[i-1].price+dp[i-1][j-a[i-1].w];
				}
				exc=dp[i-1][j];
				dp[i][j]=max(inc,exc);
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n][w];
}


//bottom UP DP unbounded
int unbounded_knapsackBottomUpDP(int n,int w,item a[])
{
	int dp[100][100];
	for(int i=0;i<=n;i++)//i here denotes the item i==0 means 0 items
	{
		for(int j=0;j<=w;j++)//j here denotes the current capacity of the bag
		{
			if(i==0||j==0)
			{
				dp[i][j]=0;
			}
			else
			{
				int inc=0,exc=0;
				if(a[i-1].w<=j)
				{
					inc=a[i-1].price+dp[i][j-a[i-1].w];
				}
				exc=dp[i-1][j];
				dp[i][j]=max(inc,exc);
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n][w];
}

int main()
{
	//item a[]={{7,15},{4,8},{4,8}};
	item a[]={{2,5},{2,20},{3,100},{1,30}};
	cout<<bounded_knapsackBottomUpDP(4,5,a)<<endl;
	cout<<unbounded_knapsackBottomUpDP(4,5,a)<<endl;
	cout<<unbounded_knapsack(4,5,a);

	return 0;
}