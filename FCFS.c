#include<stdio.h>
#include<string.h>
int main()
{
        char p[10][10],t[10];
        int a[10], b[10], start[10],finish[10], tat[10], wt[10], i,j,n,temp;
        int tt_wt=0,tt_at=0;
        printf("enter the number of processes:");
        scanf("%d",&n);
        for(int i=0, i<n;i++)
        {
                printf("Enter the Process_name, Arrival_time, Burst_time:");
                scanf("%s  %d  %d", &p[i],&a[i],$b[i]);
        }
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        if(a[i]<a[j])
                        {
                                temp=a[i];
                                a[i]=a[j];
                                a[j]=temp;
                                temp=b[i];
                                b[i]=b[j];
                                b[j]=temp;
                                t[i]=p[i];
                                p[i]=p[j];
                                p[j]=t;
                           }
                }
        }
        for(i=0;i<n;i++)
        {
                if(i==0)
                        start[i]=a[i];
                else
                        start[i]=finish[i-1];
                wt[i]=start[i]-a[i];
                finish[i]=start[i]+b[i];
                tat[i]=finish[i]-a[i];
        }
        printf("\n Process    AT     Burst    WT    Start   TAT   Finish");
        for(i=0;i<n;i++)
        {
                printf("\n %s \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d",p[i],a[i],b[i],wt[i],start[i],tat[i],finish[i]);
                tt_wt+=wt[i];
                tt_at+=tat[i];
        }
        printf("\naverage Waiting Time: %f",(float)tt_wt/n);
        printf("\n Average Turn Around Time:%f",(float)tt_at/n);
}
