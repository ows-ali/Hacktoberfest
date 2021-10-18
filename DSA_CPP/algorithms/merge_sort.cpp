#include<iostream>
using namespace std;

/*
The following function merges two sub-arrays
In a way that they combine to form one sorted array
*/
int merge(int arr[], int f, int m, int l)
{
    int n1 = m-f+1;	//Sub-array1
    int n2 = l-m;	//Sub-array2

    int a1[n1],a2[n2];
    for(int i=0;i<=n1;i++)
    {
        a1[i]=arr[f+i];	//Feeds first n1 elements in a1
    }
    for(int i=0;i<=n2;i++)
    {
        a2[i]=arr[m+1+i];	//feeds next n2 elements in a2
    }

	/*
	In the following while block, the elements are copied
	In ascending order, from a1 and a2, and put in arr
	*/
    int i=0,j=0,k=f;
    while(i<n1 || j<n2)
    {
        if(i>=n1)
        {
            arr[k]=a2[j];
            j++;
        }
        else if(j>=n2)
        {
            arr[k]=a1[i];
            i++;
        }
        else if(a1[i]<a2[j])
        {
            arr[k]=a1[i];
            i++;
        }
        else if(a1[i]>=a2[j])
        {
            arr[k]=a2[j];
            j++;
        }
        k++;
    }
}

/*
The following function is recursively called 
Till the smallest sub-array of size 1 is achieved
*/
void merge_sort(int arr[], int f, int l)
{
    int m;
    if(f<l)
    {
        m = (f+l)/2;
        merge_sort(arr, f, m);	//Recursively calls sub-array 1
        merge_sort(arr, m+1, l);	//Recursively calls sub-array 2
        merge(arr,f,m,l);	//Merges the sub-arrays
    }
}

int main()
{
    int n;
    cout<<"Enter n: "; cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element: "; cin>>a[i];
    }

    merge_sort(a, 0, n-1);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}