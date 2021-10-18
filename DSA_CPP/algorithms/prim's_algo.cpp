#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int findMinVertex(int* weights, bool* visited, int V)
{
  int minVertex = -1;
  for(int i = 0; i < V; i++)
  {
    if(visited[i] == false)
    {
      if(minVertex == -1 || weights[i] < weights[minVertex])
        minVertex = i;
    }
  }
  return minVertex;
  
}
void prim(int** adjMatrix, int V)
{
  bool* visited = new bool[V]; 
  int*  parents = new int[V];
  int*  weights = new int[V];
  
  for(int i = 0; i < V; i++){
    weights[i] = INT_MAX;
    visited[i] = false;
  }
  
  parents[0] = -1; 
  weights[0] = 0;
  
      for(int i = 0; i < V - 1; i++)
      { //find minVertex
        int minVertex = findMinVertex(weights,visited,V);
        visited[minVertex] = true;
        //explore unvisited neighbours
        for(int j = 0; j < V; j++)
        {
          if(adjMatrix[minVertex][j] != 0 && !visited[j])
          {
            if(adjMatrix[minVertex][j] < weights[j])
            {
              weights[j] = adjMatrix[minVertex][j];
              parents[j] = minVertex;
            }        
          }
        }
      }
  
  
  //printing
  for(int i = 1; i < V; i++)
  {
    if(parents[i] < i)
      cout << parents[i] << " " << i << " " << weights[i] << endl;
    else
      cout << i << " " << parents[i] << " " << weights[i] << endl;
   }
    
 
  
  
 }
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
   /*
   	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
   int ** adjMatrix = new int*[V];
    for(int i = 0; i < V; i++)
    {
      adjMatrix[i] = new int[V];
      for(int j = 0; j < V; j++)
        adjMatrix[i][j] = 0;
    }
   
  for(int i = 0; i<E; i++)
  {int s,d,w;
    cin>>s>>d>>w;
    adjMatrix[s][d] = w;
    adjMatrix[d][s] = w;   
  }
    prim(adjMatrix,V);
  
  for(int i = 0; i < V; i++)
    delete [] adjMatrix[i];
  
  delete [] adjMatrix;
   return 0;
}
