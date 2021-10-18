#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

//CB IDE - 15896

class Graph{
	unordered_map<char,list<char> > m;
public:
	void addEdge(char u,char v,bool bidir=true){
		m[u].push_back(v);
		
		if(bidir){
			m[v].push_back(u);
		}
	}
	bool isCyclicHelper(char s,unordered_map<char,bool> &visited,unordered_map<char,bool> &ancestor){
		visited[s] = true;
		ancestor[s] = true;
        cout<<s<<endl;

		for(auto child:m[s]){
			if(!visited[child]){
				bool aageCycleMila = isCyclicHelper(child,visited,ancestor);
				if(aageCycleMila){
					return true;
				} 
			}
			else if(visited[child] and ancestor[child]){
				return true;
			}

		}	
		//Backtracking
		ancestor[s] = false;
		return false;

	}

	bool isCyclicDirected(char s){
		unordered_map<char,bool> visited;
		unordered_map<char,bool> ancestor;

        return isCyclicHelper(s,visited,ancestor);

	}
	
};

int main(){

	Graph g;
	g.addEdge('A','B',false);
	g.addEdge('B','C',false);
	g.addEdge('A','F',false);
	g.addEdge('A','G',false);
	g.addEdge('B','D',false);
	g.addEdge('D','F',false);
	g.addEdge('F','G',false);
	//g.addEdge('F','B',false);

	if(g.isCyclicDirected('A')){
		cout<<"Cyclic ";
	}	
	else{
		cout<<"Not Cyclic";
	}


	return 0;
}
