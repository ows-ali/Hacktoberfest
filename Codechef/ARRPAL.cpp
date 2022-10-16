//https://www.codechef.com/START60C/problems/ARRPAL
#include <iostream>
using namespace std;

bool checkpalindrome(int a[], int n){
    for(int i=0;i<n;i++){
        if(a[i]!=a[n-i-1])
        return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t!=0){
        int n;
        cin >> n;
        int a[n];
        for (int i=0; i<n; i++)
            cin >> a[i];
        int i=0,j=n-1,k=0;
        int arr[n];
        bool flag=false;
        while(j>i){
            if(a[j]-a[i]>=0){
                arr[k]=a[j]-a[i];
            }
            else{
                flag=true;
                break;
            }
            i++;
            j--;
            k++;
        }
        for(int i=0;i<k-1;i++){
            if(arr[i]<arr[i+1]){
                flag=true;
                break;
            }
        }
        if(checkpalindrome(a,n))
        cout<< 0 << endl;
        else if(flag){
            cout << -1 << endl;
        }
        else{
            cout << arr[0] << endl;
        }
    t--;
    }
}
