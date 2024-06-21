#include <stdio.h>
#include <stdlib.h>
char seats[] ="LBMBUBLBMBUBSLSU";
static int seat_number[] = {1,4,2,5,3,6,7,8};

int ispresent(int n)
{
  int i=0;
  for(;i<8;i++)
  {
    if(seat_number[i]==n)	return i;
  }
  return -1;
}

int main()
{
  int t,n,m,q,se;
  hello:
  scanf("%d",&t);
  if(t<1||t>100)	goto hello;
  int *neighbour = (int *)malloc(t*2*sizeof(int));
  int *entry = (int *)malloc(t*sizeof(int)*2);
  int *factor = (int *)malloc(t*sizeof(int)*2);
  int i=0,j=0;
  for(;i<t;i++)
  {
    enter:
    scanf("%d", &(*(entry+i*2)));
    if(*(entry+i*2)<1||*(entry+i*2)>500)	goto enter;
    *(factor+i) = (*(entry+i*2))/8;
    if((*(entry+i*2))%8==0)
    {
      *(factor+i) -=1;
      q = ispresent(8);
    }
    else
    {
      q = ispresent((*(entry+i*2))%8);
    }
    if(q>=0&&(q%2)==0)		*(neighbour+i*2)=seat_number[q+1];
    else if(q>=0&&(q%2)==1)		*(neighbour+i*2)=seat_number[q-1];
  }
  for(i=0;i<t;i++)
  {
    m=(*(neighbour+i*2));
    n=(m+((*(factor+i))*8));
    printf("%d%c%c\n",n,seats[(m-1)*2],seats[(m-1)*2+1]);
  }
  return 0;
}
  
