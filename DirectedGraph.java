import java.util.*;  

class Edge   
{  
//the variables(representing edges)     
int s, d;  
//creating a constructor of the class Edge  
Edge(int s, int d)   
{  
this.s = s;  
this.d = d;  
}  
}  

class Graph  
{  
    
List<List<Integer>> adjlist = new ArrayList<>();  
//creating a constructor  
public Graph(List<Edge> edges)  
{  
int n = 0;  

for (Edge e: edges)   
{  
//determines the maximum numbered vertex      
n = Integer.max(n, Integer.max(e.s, e.d));  
}  
//reserve the space for the adjacency list  
for (int i = 0; i <= n; i++)   
{  
adjlist.add(i, new ArrayList<>());  
}  
//adds the edges 
for (Edge current: edges)  
{  
//allocate new node in adjacency list from source to destination  
adjlist.get(current.s).add(current.d);  
}  
}  
//Function to print adjacency list representation of a graph  
public static void showGraph(Graph graph)  
{  
int s = 0;  
 
int n = graph.adjlist.size();  
while (s < n)  
{  

for (int d: graph.adjlist.get(s))   
{  
System.out.print("Adjacency List for the graph is:");      
     
System.out.print("(" + s + " -- > " + d + ")\t");  
}  
System.out.println();  
 
s++;  
}  
}  
}  
//DriverCode 
class DirectedGraph  {  public static void main (String args[])  
{  
//List of edges  
List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(1, 2), new Edge(2, 4), new Edge(4, 1),new Edge(3, 2), new Edge(2, 5), new Edge(3, 4), new Edge(5, 4), new Edge(1, 1));  

// construct a graph from the given list of edges  
Graph graph = new Graph(edges);   
Graph.showGraph(graph);  
}  
}  