#include <stdio.h>
#include <stdlib.h>
int d,v=0,u=0,count2=0,n,i,choice,count1=0,flag=0,ans;
struct node
{
    int data;
    struct node *next;
}*start1=NULL,*start2=NULL,*temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8;
void create1(int d)
{
    temp1=(struct node *)malloc(sizeof(struct node));
    temp1->data=d;
    temp1->next=NULL;
    if (v==0)
    {
    start1=temp1;
    v=1;
    count1++;
    }
    else
    {
        temp2->next=temp1;
        count1++;
    }
    temp2=temp1;
}
void create2(int d)
{
    temp5=(struct node *)malloc(sizeof(struct node));
    temp5->data=d;
    temp5->next=NULL;
    if (u==0)
    {
    start2=temp5;
    u=1;
    count2++;//
    }
    else
    {
        temp6->next=temp5;//
        count2++;
    }
    temp6=temp5;//
}

void display1()
{
    if (count1==1)
    {
        temp4=start1;
           printf("\n");
        printf("%d\n",temp4->data);
    }

    else if (count1==0)
    {
        printf("\nLINKED LIST 1 IS EMPTY\n");
    }
    else
    {
        temp4=start1;
    printf("\n");
    do
    {
         printf("%d\n",temp4->data);
         temp4=temp4->next;
    }
    while(temp4->next!=NULL);
    printf("%d\n",temp4->data);

    }


}
void display2()
{
    if (count2==1)
    {
        temp7=start2;
           printf("\n");
        printf("%d\n",temp7->data);
    }

    else if (count2==0)
    {
        printf("\nLINKED LIST 2 IS EMPTY\n");
    }
    else
    {
        temp7=start2;
    printf("\n");
    do
    {
         printf("%d\n",temp7->data);
         temp7=temp7->next;
    }
    while(temp7->next!=NULL);
    printf("%d\n",temp7->data);

    }


}
int compare(struct node* start1,struct node* start2)
{
    temp3=start1;
    temp8=start2;

    /*while (flag=0 && temp8!=NULL)
    {*/
       while (flag==0 && temp3!=NULL)
    {

        if (temp3->data==temp8->data)
        {
            flag=1;
        }
        else
        temp3=temp3->next;//seaching ll2 in ll1...
    }
    //printf("%d",flag);
   // temp8=temp8->next;
    //}
      if (flag==0)
        return 0;
      else
      {
          while (temp8!=NULL && flag==1)
          {
              if (temp3->data==temp8->data)
              {
                  temp3=temp3->next;
                  temp8=temp8->next;
                //printf("%d",flag);
              }
              else
              {
                 flag=0;
                  //printf("%d",flag);
                  return 0;
              }
          }
          return flag;
      }
}

int main()
{
    do
    {printf("MAKE YOUR CHOICE:\n\t1.CREATE LINKED LIST 1\n\t2.DISPLAY LINKED LIST 1\n\t3.CREATE LINKED LIST 2\n\t4.DISPLAY LINKED LIST 2\n\t5.COMPARE\n\t6.EXIT\n");
     scanf("%d",&choice);
     switch (choice)
     {
     case 3:
          printf("enter the data for creation of a new node: ");
          scanf("%d",&d);
          create1(d);
          printf("\n");
          break;

     case 4:
          display1();
           printf("\n");
          break;

     case 6:
         exit(0);
          printf("\n");
         break;

     case 1:
        printf("enter the data for creation of a new node: ");
          scanf("%d",&d);
          create2(d);
          printf("\n");
          break;
    case 2:
        display2();
           printf("\n");
        break;

    case 5:
        ans=compare(start1,start2);
        if (ans==0)
        {
            printf("\n\tlinked list 1 is not present in linked list 2!\n");
        }
        else
             printf("\n\tlinked list 1 is present in linked list 2!\n");
        break;
     }
    }
    while(1);
    return 0;
}
