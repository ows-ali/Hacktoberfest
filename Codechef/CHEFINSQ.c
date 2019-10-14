
#include<stdio.h> 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] < pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 
long long int gcd(long long int n,long long int r)
{
	long long int g = 1;
	for(long long int i = 1;i<=r;i++)
		if(n%i == 0 && r%i == 0)
			g = i;
	return g;
}
int main() 
{ 
	int u;
	scanf("%d",&u);
	while(u--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int arr[n];
		for(int i=0;i<n;i++)
			scanf("%d",arr+i);
		quickSort(arr,0,n-1);
		int l=1,r=0;
		for (int i = k-2;; i--)
		{
			if(arr[i]!=arr[k-1])
				break;
			l++;
		}
		for (int i = k;; i++)
		{
			if(arr[i]!=arr[k-1])
				break;
			r++;
		}
		if(r<l)
		{
			int temp = r;
			r = l;
			l = temp;
		}
		long long int p=1,q=1;
		for (int i = 0; i < l; ++i)
		{
			p*=(i+1);
			q*=(r+i+1);
			long long int m = gcd(q, p);
			p /= m;
			q /= m; 
		}
		printf("%lld\n", q/p);
	}
	return 0; 
} 
