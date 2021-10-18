
# Depth-First-Search in a graph


A graph is a combination of vertices and edges between them. Any vertex can be linked with any other, even with itself. A graph is just an arbitrary combination of vertices and edges betwen them.      
A traversal in a graph is a way of visiting every vertex in a graph. Here, we are going to talk about depth first search(traversal) in a graph.     
The DFS algorithm is a recursive algorithm that involves exhaustive searching of all the vertices that are deeper than the given vertex, and then doing the same for the vertices that are adjacent to it.     
For example, if the graph was :- 

![dfs](http://www.algolist.net/img/graphs/DFS/DFS-example-1.png)


Then the output of the BFS starting from 2 would be: 
2  4  1  5  3

Explanation:- Adjacency list of 2:- {4,5}.     
* 4 is visited first.     
When 4 is visited, its adjacency list is exhausted and only then the adjacency list of 5 is visited.     
Adjacency list of 4:- {1,5}.     
* 1 is visited.    
Adjacency list of 1:- {4}, but 4 is already visited. Hence, the next adjacent vertex of 4 is taken. i.e, 5.    
* 5 is visited.     
Now,  Adjacency lis of 5 will be visited. 
Adjacency list of 5:- {3,4}.    
* 3 is visited.     
4 is already visited, so it wont be visited.    
    
    Hence the output is 2  4  1  5  3.     
        
 A stack data structure is used. When a vertex is encountered, it is pushed into the stack and also printed. Now, the function dfs is recursively called for all of its adjacent vertices. This recursive call makes sure that all the deeper vertices of the first adjacent vertex is visited and only then the next vertex is chosen.    
 A visited array is maintained to make sure that the same vertex isnt visited twice.     
 
 Following is the cpp implementation:- 
 Code from: [geeksforrgeeks](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)    
 Note that in the code, the same graph in above picture is represented using 0-based indexing.     
 Hence the output would be 1 3 0 4 2, instead of 2 4 1 5 3. 
 
 
 ```cpp
 
// C++ program to print DFS traversal from 
// a given vertex in a  given graph 
#include<iostream> 
#include<list> 
using namespace std; 
  
// Graph class represents a directed graph 
// using adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing 
    // adjacency lists 
    list<int> *adj; 
  
    // A recursive function used by DFS 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // DFS traversal of the vertices 
    // reachable from v 
    void DFS(int v); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
    adj[w].push_back(v);
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited); 
} 
  
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(5); 
    g.addEdge(0, 3); 
    g.addEdge(1, 3); 
    g.addEdge(1, 4); 
    g.addEdge(3, 4); 
    g.addEdge(2, 4); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 
  
    return 0; 
} 

 ```
 
 ```cpp
 Output:- 
 Following is Depth First Traversal (starting from vertex 2) 
1 3 0 4 2
```
 
    
  


