#include <bits/stdc++.h>
using namespace std;
int main(){
    int a=0,b=0,c=0,n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        a+=1;
        else if(arr[i]<0)
        b+=1;
        else
        c+=1;
    }
    cout<<(float)a/n<<endl<<(float)b/n<<endl<<(float)c/n;
}
