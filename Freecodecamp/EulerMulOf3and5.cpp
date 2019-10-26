#include<iostream>

using namespace std;

int main()
{
  int i,mul=0;
  for(i=1;i<=1000;i++)
  {
    if(i%15 == 0)
    {
      mul++;
    }
  }
  cout<<"Number of multiples of both 3 and 5 are "<<mul<<endl;
  return 0;
}
