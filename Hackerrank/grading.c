#include<stdio.h>
int main(){

	int n,i;
	scanf("%d",&n);
	int mark[n];
	for(i=0;i<n;i++){
		scanf("%d",&mark[i]);
	}
	int x;
	for(i=0;i<n;i++){
		if(mark[i]>=38){
			if(mark[i]%5>=3){
				x=mark[i]/5;
				mark[i]=(x+1)*5;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",mark[i]);
	}
}

