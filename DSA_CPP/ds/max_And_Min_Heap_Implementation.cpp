//This program shows the implementation of heaps right from building a max heap and then doing a heap sort. Also functions to build min heap has been added to use.

#include<bits/stdc++.h>
#define lli long long int //define macros
#define loop(a, b) for(lli i=a; i<b; i++)
#define loop2(a, b) for(lli j=a; j<b; j++)
#define loop3(a, b) for(lli h=a; h<b; h++)
#define revloop(a, b) for(lli k=a; k>=b; k--)
#define init(array, val) memset(array, val, sizeof(array))

using namespace std;

void max_heapify(int a[], int i, int n) //function to max heapify
{
    int left = i*2;
    int right = left + 1, largest;
    if(left <= n && a[left] > a[i])
        largest = left;
    else
        largest = i;
    if(right <= n && a[right] > a[largest])
        largest = right;

    if(largest != i)
    {
        swap(a[largest], a[i]);
        max_heapify(a, largest, n);
    }
}

void min_heapify(int a[], int i, int n) //function to min heapify
{
    int left = 2*i;
    int right = left + 1, smallest = i;

    if(left <= n && a[left] < a[smallest])
        smallest = left;
    if(left <=n && a[right] < a[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(a[smallest], a[i]);
        min_heapify(a, smallest, n);
    }
}

void build_max_heap(int a[], int n)
{
    for(int i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
    cout<<"Max Heap Build Successful\n";
}

void build_min_heap(int a[], int n)
{
    for(int i = n/2; i >= 1; i--)
    {
        min_heapify(a, i, n);
    }
    cout<<"Min Heap Build Successful\n";
}

void heap_sort(int a[], int n) //function for heap sort
{
    build_max_heap(a, n);
    int heap_size = n;
    for(int i = n; i>=2; i--)
    {
        swap(a[1], a[heap_size]);
        heap_size--;
        max_heapify(a, 1, heap_size);
    }

    cout<<"Heap sort: ";
    loop(1, n+1)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    cout<<"Enter Number of nodes: ";
    int n;
    cin>>n;
    int a[n+1], b[n+1];
    cout<<"Enter Space Separated Values of nodes: ";
    loop(1, n+1)
    {
        cin>>a[i];
    }
    loop(1, n+1)
        b[i] = a[i];
    heap_sort(a, n);
}
