#include<iostream>

using namespace std;



void heapify(int a[],int i,int heapSize)
{
  int large=i;
  int l= (2*i)+1;
  int r=(2*i)+2
  ;

  if(l<heapSize && a[l]>a[i]) large=l;
  else large=i;

  if(r<heapSize && a[r]>a[large]) large=r;
  if(large!=i)
  {
    int temp=a[i];
    a[i]=a[large];
    a[large]=temp;

    heapify(a,large,heapSize);
  }



}



void heapSort(int a[],int n)
{
  for(int i=(n/2)-1;i>=0;i--) heapify(a,i,n);
  for(int i=n-1;i>=0;i--)
  {
    int temp=a[0];
    a[0]=a[i];
    a[i]=temp;

    heapify(a,0,i);
  }

}


int main()
{
  int n;
 cin>>n;
  int a[n];
for(int i=0;i<n;i++)
{
  cin>>a[i];
}

heapSort(a,n);

for(int i=0;i<n;i++)
{
  cout<<a[i]<<" ";
}





}
