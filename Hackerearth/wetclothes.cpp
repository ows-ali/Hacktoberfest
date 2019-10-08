#include<bits/stdc++.h>
 
using namespace std;
 
int main(int argc, const char *argv[])
{
int n, m, g;
cin >> n >> m >> g;
 
int times[n];
int timec[n];
int cloth[m];
 
for(int i = 0; i < n; i++)
{
cin >> times[i];
}
 
timec[0] = times[0];
for(int i = 1; i < n; i++)
{
timec[i] = times[i] - times[i-1];
}
 
for(int j = 0; j < m; j++)
{
cin >> cloth[j];
}
 
sort(cloth, cloth + m);
int cloth_pointer = -1;
 
for(int i = 1; i < n; i++)
{
int cr_time = timec[i];
for(; cloth[cloth_pointer+1] <= cr_time && cloth_pointer < m-1; ++cloth_pointer);
}
 
cout << cloth_pointer + 1 << endl;
}
 
