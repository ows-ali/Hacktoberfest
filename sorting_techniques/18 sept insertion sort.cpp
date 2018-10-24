#include<iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
   int i, k, j;
   for (i = 1; i < n; i++)
   {
       k = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > k)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = k;
   }
   for (i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int a[100],i,j,m,s;
    cin>>s;
    for(i=0;i<s;i++)
    {
        cin>>a[i];
    }
     insertionSort(a,s);

}
