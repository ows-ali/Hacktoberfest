#include<iostream.h>
#include<conio.h>
#include<string.h>
int comp(char *q,int i,int j)
{
 int F=0;
 while(j>=i)
 {
  if(q[i]==q[j])
  {
   F=1;
  }
  else
  {
  F=0;
  break;
  }
       i++;
       j--;
 }
 if(F==1)
 {
  return 1;
 }
 else
 {
 return 0;
 }
}
void print(char *q,int i,int j)
{
 while(i<=j)
 {
  cout<<q[i];
  i++;
 }
 cout<<"  ,";
}
void main()
{
clrscr();
char *p;
int m,i,j,F,max=0,c;
cout<<"Enter the string:";
cin>>p;
m=strlen(p);
cout<<"All palindroms possible: " <<"\n";
for(i=0;i<m-1;i++)
{
 for(j=i+1;j<m;j++)
 {  F=0;
  if(p[i]==p[j])
  {
   F=comp(p,i,j);
  }
  if(F==1)
  {
  print(p,i,j);
  c=j-i+1;
   if(c>max)
   {
    max=c;
   }
  }
 }
}
cout<<"\nPalindrom of max size:"<<max;
getch();
}

