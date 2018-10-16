#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
  int n;
  cout<<"Enter the number of rows =";
  cin>>n;
  char ch=1;
  for(int i=0,i<n,++i)
  { for(int j=0,j<=i,++j) 
     { cout<<ch; }
    cout<<endl;
  }
  getch();
}