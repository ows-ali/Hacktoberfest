#include<bits/stdc++.h>
using namespace std;
int sum(int freq[], int i, int j);
int optimalSearchTree(int keys[], int freq[], int n) //OBST function
{
int cost[n][n];
for (int i = 0; i &lt; n; i++) //Making diagonal as frequency
cost[i][i] = freq[i];
for (int L=2; L&lt;=n; L++)
{
for (int i=0; i&lt;=n-L+1; i++)
{
int j = i+L-1;
cost[i][j] = INT_MAX;
for (int r=i; r&lt;=j; r++)
{
int c = ((r &gt; i)? cost[i][r-1]:0) +
((r &lt; j)? cost[r+1][j]:0) +
sum(freq, i, j);
if (c &lt; cost[i][j])
cost[i][j] = c; //Filling matrix Dynamic
}
}
}

for(int i=0;i&lt;n;i++){
for(int j=i;j&lt;n;j++)
cout&lt;&lt;cost[i][j]&lt;&lt;&quot; &quot;;//Output Cost Matrix
cout&lt;&lt;&quot;\n&quot;;
}
return cost[0][n-1];
}
int sum(int freq[], int i, int j)
{
int s = 0;
for (int k = i; k &lt;=j; k++)
s += freq[k];
return s;
}
int main() //Driver function
{
int keys[] = {10, 12, 20 ,25,35};
int freq[] = {34, 8, 50 ,10,2};
int n = sizeof(keys)/sizeof(keys[0]);
clock_t t;//Clock function
t=clock();
printf(&quot;Cost of Optimal BST is %d &quot;,
optimalSearchTree(keys, freq, n));
t=clock()-t;//Cycles used
printf(&quot;\nNo.of cycle %dTime Taken%f&quot;,t,float(t)/CLOCKS_PER_SEC);

return 0;
}
