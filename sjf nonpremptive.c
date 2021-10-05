#include<stdio.h>
void main()
{
    int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,g=1,burstime=0,bur[10],temp,j,arrt[10],waitt[10],turnt[10],ta=0,sum=0;
    float avgw=0,avgt=0,tsum=0,wsum=0;

    printf("\nEnter the number of processes :");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of process %d:",i+1);
        scanf(" %d",&bur[i]);
        printf("Enter the arrival time of process %d:",i+1);
        scanf(" %d",&arrt[i]);
    }

    //sorting

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arrt[i]<arrt[j])
            {
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
                temp=arrt[j];
                arrt[j]=arrt[i];
                arrt[i]=temp;
                temp=bur[j];
                bur[j]=bur[i];
                bur[i]=temp;
            }
        }
    }


    for(j=0;j<n;j++)
    {
        burstime=burstime+bur[j];
        min=bur[g];
        for(i=g;i<n;i++)
        {
            if (burstime>=arrt[i] && bur[i]<min)
            {
                temp=p[g];
                p[g]=p[i];
                p[i]=temp;
                temp=arrt[g];
                arrt[g]=arrt[i];
                arrt[i]=temp;
                temp=bur[g];
                bur[g]=bur[i];
                bur[i]=temp;
            }
        }
        g++;
    }
    waitt[0]=0;
    for(i=1;i<n;i++)
    {
        sum=sum+bur[i-1];
        waitt[i]=sum-arrt[i];
        wsum=wsum+waitt[i];
    }

    avgw=(wsum/n);
    for(i=0;i<n;i++)
    {
        ta=ta+bur[i];
        turnt[i]=ta-arrt[i];
        tsum=tsum+turnt[i];
    }

    avgt=(tsum/n);

    printf("\nANSWER :-");
    printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
    for(i=0;i<n;i++)
    {
        printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bur[i],arrt[i],waitt[i],turnt[i]);
    }

    printf("\n\nAverage waiting time : %.3f",avgw);
    printf("\nAverage turnaround time : %.3f",avgt);

}
