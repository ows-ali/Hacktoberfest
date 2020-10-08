#include<iostream>
using namespace std;
int main(){
	short int T,t;
	int N,K,L,i,j;
	cin>>T;
	for(t=0;t<T;t++){
		cin>>N>>K>>L;
		i=0,j=1;
		if(N<=K){
			for(i=1;i<=N;i++){
				cout<<i<<" ";
			}
			
		}
		else if(K==1 && N>1){
			cout<<"-1";
		
		}
		else{
			if(K*L>=N){
				while(i<N){
					cout<<j<<" ";
					if(j==K){
						j=0;
					}
					j++;
					i++;
				}
			}
			else{
				cout<<"-1";
			}
		}
		cout<<"\n";
	}
	
}
