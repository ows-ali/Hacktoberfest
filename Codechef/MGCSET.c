#include <stdio.h>
#include<math.h>

int main() {
	int t,i=0,j=0;
	scanf("%d",&t);
	for( j=0;j<t;j++){
	    int n,m;
	    scanf("%d %d",&n,&m);
	    int count=0;

	    int arr[n];
	    for(i=0;i<n;i++){
	        scanf("%d",&arr[i]);
	        if(arr[i]%m==0){
	            count++;
	        }
	    }
	    unsigned int size=pow(2,count);	    
	    printf("%d\n",size-1);
	}
	return 0;
}


