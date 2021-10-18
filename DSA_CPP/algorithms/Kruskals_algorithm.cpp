#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class edge{
  public : 
  int source;
  int destination;
  int weight;
};
 bool compare(edge e1, edge e2)
{
  return e1.weight < e2.weight;
}
 int findParent(int v, int* parent)
{
  if(parent[v] == v)
    return v;
  
  return findParent(parent[v],parent);
}
 void kruskals(edge* input, int V, int E)
{  
   sort(input,input+E,compare);
  
   edge* output = new edge[V-1];
   int *parent = new int[V];
  
 for(int i = 0; i < V; i++)
   parent[i] = i;
  
  int count = 0;  
  int i = 0;
  
  while(count < V-1)
  {
    int srcParent = findParent(input[i].source,parent);
    int destParent = findParent(input[i].destination,parent);
    if(srcParent != destParent)
    {
      output[count++] = input[i];
      parent[srcParent] = destParent; 
    }
    i++;
  }
 
 for(int i = 0; i < V-1; i++)
 {
   if(output[i].source < output[i].destination)
     cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
   else
     cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
  }
}
 int main()
{
  int V, E,s,d,w;
  cin >> V >> E;
  /*   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself 
  */
  edge* input = new edge[E];
  for(int i = 0; i<E; i++)
  {
    cin>>s>>d>>w;
    input[i].source = s;
    input[i].destination = d;
    input[i].weight = w;
  }
  
 
  
  kruskals(input,V,E);
   return 0;
}
