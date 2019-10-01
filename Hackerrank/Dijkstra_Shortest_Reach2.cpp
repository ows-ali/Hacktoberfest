# include <iostream>
# include <cstdio>
# include <queue>
# include <vector>

# define INT_MAX 999990

using namespace std;

long long int Graph[3000][3000];

struct Vertex
{
	int vertex_val;
	long long int distance;
	bool visited;
};

struct compare
{
	bool operator()(const Vertex& l, const Vertex& r)
	{
		return l.distance > r.distance;
	}
};

int degree(int u, int vertices)
{
	int count = 0;
	for(int i = 0; i < vertices; i++)
	{
		if(Graph[i][u] != 0)
			count++;
	}
	return count;
}

int* neighbours(int u, int vertices)
{
	int *set = new int[degree(u,vertices)];
	int count = 0;
	for(int i = 0; i < vertices; i++)
	{
		if(Graph[i][u] != 0)
		{
			set[count] = i;
			count++;
		}
	}
	return set;
}

int main()
{
	int T;
	scanf("%d ",&T);
	while(T--)
	{
		int ver,edge,source;
		scanf("%d %d",&ver,&edge);

		for(int i = 0; i < ver; i++)
		{
			for(int j = 0; j < ver; j++)
				Graph[i][j] = 0;
		}

		int u, v, dist;
		for(int i = 0; i < edge; i++)
		{
			scanf("%d %d %d",&u, &v, &dist);
			if(Graph[u-1][v-1] == 0)
			{
				Graph[u-1][v-1] = dist;
				Graph[v-1][u-1] = dist;
			}
			if(Graph[u-1][v-1] != 0 && Graph[u-1][v-1] > dist)
			{
                Graph[u-1][v-1] = dist;
                Graph[v-1][u-1] = dist;
        	}
		}

		scanf("%d",&source);
		source = source -1;

		Vertex V[ver];
		priority_queue<Vertex, vector<Vertex>, compare> PQ;
		for(int i = 0; i < ver; i++)
		{
			if(i != source)
			{
				V[i].vertex_val = i;
				V[i].distance = INT_MAX;
				V[i].visited = false;
			}
			else
			{
				V[i].vertex_val = i;
				V[i].distance = 0;
				V[i].visited = true;
				PQ.push(V[i]);
			}
		}

		while(!PQ.empty())
		{
			Vertex U = PQ.top();
			int u = U.vertex_val;
			V[u].visited = true;
			PQ.pop();
			int *set = neighbours(u,ver);
			int deg = degree(u,ver);
			for(int i = 0; i < deg; i++)
			{
				long long int alt = U.distance + Graph[u][set[i]];
				if((alt < V[set[i]].distance) && (Graph[u][set[i]] != 0) && (V[set[i]].visited != true))
				{
					V[set[i]].distance = alt;
					PQ.push(V[set[i]]);
				}
			}
		}

		for(int i = 0; i < ver; i++)
		{
			if(V[i].distance == INT_MAX)
				printf("-1 ");

			else if(V[i].distance != 0)
				printf("%lld ", V[i].distance);
		}
		cout << endl;
	}
	return 0;
}
