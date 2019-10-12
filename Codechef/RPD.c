#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,num,n;
		int sum=0;
		int sum1=0;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n && j!=i;j++)
			{
				num=a[i]*a[j];
				while(num>0)
				{
					sum1=sum1+num%10;
					num/=10;
				}
				if(sum1>sum)
					{
						sum =sum1;
						sum1=0;
					}
					sum1=0;

			}
		}
		printf("%d\n",sum);
	}
}
