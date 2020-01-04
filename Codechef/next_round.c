    #include <stdio.h>
     
    int main() 
    {
      int n,k,a[50],i,count=0;
      scanf("%d%d",&n,&k);
      for(i=1;i<=n;i++)
      {
        scanf("%d",&a[i]);
      }
      for(i=1;i<=n;i++)
      {
        if((a[i]>=a[k])&&(a[i]>0))
        {
          count=count+1;
        }
      }
      printf("%d\n",count);
      return 0;
    }
