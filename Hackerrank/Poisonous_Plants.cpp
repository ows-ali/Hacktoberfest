#include <bits/stdc++.h>

using namespace std;
int main()
{
int n;
cin>>n;

int* p = new int[n];
for(int i=0;i<n;i++)
    cin>>p[i];

int* days = new int[n]();
int min = p[0];
int max = 0;
stack<int> s;

s.push(0);

for(int i=1;i<n;i++)
    {

    if(p[i] > p[i-1])
        days[i] = 1;

    min = min < p[i]?min:p[i];

    while(!s.empty() && p[s.top()] >= p[i])
     {
       if(p[i] > min)
       days[i] = days[i] > days[s.top()] + 1?days[i]:days[s.top()] + 1;

        s.pop();
   }  

    max = max>days[i]?max:days[i];
    s.push(i);
}

cout<<max<<endl;
return 0;
}
