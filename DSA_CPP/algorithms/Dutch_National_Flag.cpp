// this algo is also called three way quick sort
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// a func to print all elements in the array
void printarray(int a[], int n)
{
    for (int j = 0; j < n; ++j){
      cout<<a[j]<<endl;
    }
}

/* This function partitions a[] in three parts
a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
c) a[j..r] contains all elements greater than pivot */

void partition(int a[], int low, int high, int &i, int &j)
{
    // for 2 elements
    if (high - low <= 1)
    {
        if (a[high] < a[low])
            swap(&a[high], &a[low]);
        i = low;
        j = high;
        return;
    }

    int mid = low;
    int pivot = a[high];
    while (mid <= high)
    {
        if (a[mid]<pivot)
            swap(&a[low++], &a[mid++]);
        else if (a[mid]==pivot)
            mid++;
        else if (a[mid]>pivot)
            swap(&a[mid], &a[high--]);
    }

    // i and j updated below
    i = low-1;
    j = mid; //or high-1
}

// 3 way qsort
void quicksort(int a[], int low, int high)
{
    if (low>=high) //1 or 0 elements
        return;

    int i, j;

    // i and j are passed as reference
    partition(a, low, high, i, j);

    // Recur two halves
    quicksort(a, low, i);
    quicksort(a, j, high);
}

int main()
{
    int a[50];
    int size;
    cout<<"Enter size of array"<<endl;
    cin>>size;
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<size;i++){
      cin>>a[i];
    }
    cout<<"Array before sorting"<<endl;
    printarray(a, size);
    quicksort(a, 0, size - 1);
    cout<<"Array after sorting"<<endl;
    printarray(a, size);
    return 0;
}
