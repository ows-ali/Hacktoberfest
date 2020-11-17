#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
int N;
vector<int> v;
cin>>N;
int a;
for(int i=0;i<N;i++)
{cin>>a;
    v.push_back(a);

}
vector<int> :: iterator itr;

int Q;
cin>> Q;
int q1;
for(int i=0;i<Q;i++)
{
cin>>q1;
itr=lower_bound(v.begin(), v.end(),q1 );
if (*itr==q1)

cout<< "Yes "<<itr-v.begin()+1<<endl;
else
cout<<"No "<<itr-v.begin()+1<<endl;


}



}
