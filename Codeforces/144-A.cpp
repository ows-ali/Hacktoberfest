#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i,arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    int min=0,max=0;
    for(i=1;i<n;i++)
    {
        if(arr[min]>=arr[i])
            min=i;
        if(arr[max]<arr[i])
            max=i;
    }
    int res=max+(n-1-min);
    if(max>min)
        res--;
    cout<<res<<endl;

    return 0;
}