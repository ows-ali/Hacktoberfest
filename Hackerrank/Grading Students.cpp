#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

   
    int n;
    vector <int> v(100);
    cin>>n;
    for(int i=0;i<n;i++)cin>>v[i];

    for(int i=0;i<n;i++)
    {
        if(v[i]<38){
            cout<<v[i]<<endl;
            
        }
       

       else 
       {
        int inr=0;
        while((v[i]%5!=0)&&(inr<3)){
            v[i]++;
            inr++;
            //cout<<v[i]<<inr<<endl;
        }
        if(inr>=3){
        cout<<v[i]-inr<<endl;
        }
        else{
            cout<<v[i]<<endl;
        }
       }


       
    }
    return 0;
}
