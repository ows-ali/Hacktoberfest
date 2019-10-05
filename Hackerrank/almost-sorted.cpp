/** Run in any cpp supported console*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[100000],barr[100000],carr[100000],flag=0,c=0,j=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        barr[i]=arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]!=barr[i]){
            c++;
            carr[j++]=i;
        }
    }
    if(c==0)
        cout<<"yes";
    else if(c==2){
        cout<<"yes"<<endl<<"swap "<<carr[0]+1<<" "<<carr[1]+1;
    }
    else{
        int k=j;
        for(int i=0;i<k/2;i++){
            swap(barr[carr[i]],barr[carr[k-i-1]]);
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=barr[i]){
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"yes"<<endl<<"reverse "<<carr[0]+1<<" "<<carr[j-1]+1;
        else
            cout<<"no";
    }
    return 0;
}