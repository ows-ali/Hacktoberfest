#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    int i;
    int a[num],b[num];
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
    }
    char result[num];
    int j=0;
    do{
    if (a[j]>0 && b[j]>0){
        j++;
        printf("Solution\n");
           
        }
    else if (b[j]==0){
        printf("Solid\n");
        j++;
         
        }
    else if (a[j]==0){
        printf("Liquid\n");
        j++;
        }
        
    }while(j<num);
}
