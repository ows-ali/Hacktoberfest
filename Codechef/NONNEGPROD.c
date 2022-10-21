#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[n],i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int x=0,y=0,z=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                y++;
            }
            else if(arr[i]==0){
                x++;
            }
            else{
                z++;
            }
        }
        if(y==n)
        {
            printf("0\n");
        }
        else if(x>=1)
        {
            printf("0\n");
        }
        else{
            if(z%2==0)
            printf("0\n");
            else
            printf("1\n");
        }
        
    }
	return 0;
}
