// https://www.hackerrank.com/challenges/journey-to-the-moon/problem
// https://www.hackerrank.com/Blazer_007

#include <iostream>
#include <list>
#define int long long
using namespace std;


class Graph{
    
    int V;
    list<int> *l;
    
    public:
        Graph(int v){
            V = v;
            l = new list<int>[V];
            
        }
        
        void addEdge(int u,int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }
        void dfsHelper(int i,bool visited[],int &country_size){
            visited[i] = true;
            country_size++;
            
            for(auto neighbour:l[i]){
                if(!visited[neighbour]){
                    dfsHelper(neighbour,visited,country_size);
                }
            }
            
        }
        
        int dfsMoon(){
            bool *visited = new bool[V];
            for(int i=0;i<V;i++){
                visited[i] = false;
            }
            
            int n = V;
            int total_ways = (n)*(n-1)/2;
            
            for(int i=0;i<V;i++){
                if(visited[i]==false){
                    int country_size = 0;
                    dfsHelper(i,visited,country_size);
                    total_ways -= (country_size)*(country_size-1)/2;
                }
            }
            
            return total_ways;   
        }
    
    
};



signed main() {
    int n,p;
    cin>>n>>p;
    Graph g(n);
    int u,v;
    for(int i=0;i<p;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }
    
    cout<<g.dfsMoon();
}

