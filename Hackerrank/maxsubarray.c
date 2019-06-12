#include <stdio.h>
int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
void find(int n,int *arr){
    int dp[n+1],maxi = -10000,res1,res2,sum = 0;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        dp[i] = max(arr[i-1],dp[i-1]+arr[i-1]);
        if(dp[i]>maxi)
            maxi = dp[i];
    }
    res1 = maxi;
    /*for(int i=0;i<=n;i++)
        printf("%d ",dp[i]);
    printf("\n%d\n",maxi);*/
    maxi = -10000;
    for(int i=0;i<n;i++){
        if(arr[i]>maxi)
            maxi = arr[i];
        if(arr[i]>0)
            sum+=arr[i];
    }
    res2 = sum;
    if(sum == 0)
        res2 = maxi;
    printf("%d %d\n",res1,res2);
}
int main(){
    int t,n,arr[100000];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        find(n,arr);
        }
    return 0;
}