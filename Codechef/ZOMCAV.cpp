#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void add(int arr[], int N, int lo, int hi, int val) 
{ 
    arr[lo] += val; 
    if (hi != N - 1) 
       arr[hi + 1] -= val; 
} 
  
//  Utility method to get actual array from operation array 
void updateArray(int arr[], int N) 
{ 
    //  convert array into prefix sum array 
    for (int i = 1; i < N; i++) 
        arr[i] += arr[i - 1]; 
} 
  
//  method to print final updated array 
void printArr(int arr[], int N) 
{ 
    updateArray(arr, N); 
    for (int i = 0; i < N; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 



int main() {
    //cout<<"Hello World!";
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,i,j,l,p,x;
        cin>>n;
        int c[n],h[n],y[n]={0};
        for(i=0;i<n;i++)
        cin>>c[i];
        //for(i=1;i<n+1;i++)
        //cin>>h[i];
        for(i=0;i<n;i++){
            cin>>h[i];
            if(1+i-c[i]>0) l=i-c[i];
            else l=0;
            if(1+i+c[i]<n) p=i+c[i];
            else p=n-1;
            //for(j=l;j<=p;j++)
             //y[j]++;
             add(y, n, l, p, 1); 
            
        }
        
        updateArray(y,n);
        int q=sizeof(y)/sizeof(y[0]);
        int w=sizeof(h)/sizeof(h[0]);
        sort(y,y+q);
        sort(h,h+w);
        for(i=0;i<n;i++){
            if(y[i]-h[i]==0) x=1;
            else{ x=0; break;}
        }
        if(x==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
