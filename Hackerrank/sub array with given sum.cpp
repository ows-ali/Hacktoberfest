#include<iostream>
using namespace std;
int main()
{
    int size ,k,i,start=0,sum=0;
    cout<<"enter the size";
    cin>>size;
    cout<<"enter the limit";
    cin>>k;
    int arr[size];
    cout<<"enter the array";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    for (i = 0; i <= size; i++) {
        while (sum > k && start < i - 1) {
            sum = sum - arr[start];
            start++;
        }
        if (sum == k) {
            cout << "Sum found between indexes "
                 << start+1 << " and " << i;
        }

        if (i<size)
            sum = sum + arr[i];
    }
    return 0;
}
