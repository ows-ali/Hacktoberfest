#include<stdio.h>
typedef long long int ll;
ll min(ll a[]);
ll max(ll b[]);
int main(int argc, char const *argv[])
{
	ll i,arr[6],min_sum,max_sum;
	for (i = 0; i < 5; ++i)
	{
		scanf("%lld",&arr[i]);
	}
	/*
	for(i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	}
	*/
    min_sum=min(arr);
    max_sum=max(arr);
    printf("%lld %lld",min_sum,max_sum);
	return 0;
}
ll min(ll a[])
{
	ll min,sum=0;
	min = a[0]+a[1]+a[2]+a[3]+a[4];
	for(int i = 0; i < 5; i++)
	{
		sum=0;
		for (int j = 0; j < 5; ++j)
		{
			if(j==i)
				continue;
			else
				sum=sum+a[j];
		}
		//printf("%d ",sum);
		if(sum < min )
			min=sum;
	}
	return min;
}
ll max(ll a[])
{
	ll max=0,sum=0;
	for(int i = 0; i < 5; i++)
	{
		sum=0;
		for (int j = 0; j < 5; ++j)
		{
			if(j==i)
				continue;
			else
				sum=sum+a[j];
		}
		//printf("%d ",sum);
		if(sum > max)
			max=sum;
	}
	return max;
}
