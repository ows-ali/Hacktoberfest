#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int i;
    for(i=0;i<n;i++)
        cin>>arr[i];
    int c=0;
    while(true){
        if(c==n)break;
        for(i=0;i<n;i++){
            if(arr[i]==c+1){
                cout<<(i+1)<<" ";
                c++;
                break;
            }
        }
    }
    return 0;
}