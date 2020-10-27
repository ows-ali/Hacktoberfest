#include<iostream>
#include<cstring>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
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
  int main()
{
    int a[100],i,j,m,s;
    cin>>s;
    for(i=0;i<s;i++)
    {
        cin>>a[i];
    }
     quickSort(a,0,s-1);
     for(i=0;i<s;i++)
        cout<<a[i]<<" ";
}
