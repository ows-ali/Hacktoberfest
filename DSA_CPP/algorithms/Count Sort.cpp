#include<iostream>
using namespace std;

void Count_Sort(int a[],int n,int k){
    int freq[k+1]={0};

    for(int i=0;i<n;i++){
        ++freq[a[i]];
    }

    int j=0;

    for(int i=0;i<=k;i++){
        int temp=freq[i];

        while(temp--){
            a[j++]=i;
        }
    }
}

int main(){
    int n;
    cout<<"Enter Size of Array you want to sort: ";
    cin>>n;
    int a[n],maxi=-1;
    cout<<"Enter space separated +ev integers here: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(maxi<a[i]){
            maxi=a[i];
        }
    }
    cout<<"Befor Sorting: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';

    Count_Sort(a,n,maxi);

    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
return 0;
}
