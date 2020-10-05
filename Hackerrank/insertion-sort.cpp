//By J Ananthakrishnan
//Hackerrank username : codewithak

#include <bits/stdc++.h>
using namespace std;
long long merge(int arr[], int start, int mid, int end)
{
    long long count = 0;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int L[n1], R[n2];
    int i, j, k;
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + j + 1];
    }
    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            count += n1 - i;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        k++;
        j++;
    }
    return count;
}
long long mergesort(int arr[], int start, int end)
{
    long long count = 0;
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        count += mergesort(arr, start, mid);
        count += mergesort(arr, mid + 1, end);
        count += merge(arr, start, mid, end);
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << mergesort(arr, 0, n - 1);
        cout << "\n";
        t--;
    }
}