#include <bits/stdc++.h>
using namespace std;
#define N 210
#define Max_N 102

typedef long long ll;

struct matching_struct {
	vector<int> G[N], B[N], aug_path, aug_cycle;
	vector<int> vetrices;
	vector<pair<int,int>> M;
	int n;
	bool search_complete = false;
	bool aug_path_has_rep = false;
	int aug_cycle_rep;
};

int parent[N];
vector<int> irr_walk, aug_cycle;
map<pair<int,int>, bool> is_matching_edge;
bool visited[N];
bool matched_verticies[N];
matching_struct dfs_util;
int NN;


void dbg(matching_struct g) {
	cout << "Matching in this graph is given by:\n";
	for(int i = 0;i < g.M.size();i++)
		cout << g.M[i].first << " " << g.M[i].second << endl;
	cout << "Augmenting cycle: ";
	for(auto i: g.aug_cycle)
		cout << i << ", ";
	cout << endl;
	cout << "Augmenting Path: ";
	for(auto i: g.aug_path)
		cout << i << ", ";
	cout << endl;
	cout << "search_complete: " << g.search_complete << endl;
	cout << "aug_cycle_rep: " << g.aug_cycle_rep << endl;
	cout << "aug_path_has_rep: " << g.aug_path_has_rep << endl;
	cout << "Number of nodes: " << g.n << endl;
	cout << endl;
}


void pre(matching_struct g) {
	is_matching_edge.clear();
	irr_walk.clear();
	aug_cycle.clear();
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	memset(matched_verticies, false, sizeof(matched_verticies));
	for(auto edge: g.M) {
		is_matching_edge[edge] = true;
		matched_verticies[edge.first] = true;
		matched_verticies[edge.second] = true;
	}
}


void dfs(int v, int p) {
	visited[v] = true;
	parent[v] = p;
	for(auto x: dfs_util.B[v]) 
		if(!visited[x]) 
			dfs(x, v);
}


bool irreducible_alt_walk() {
	dfs(2*Max_N + 2, -1);
	if(!visited[Max_N + 1])
		return false;
	else {
		int p = parent[Max_N + 1];
		while(p != -1) {
			if(p < Max_N + 1)
				irr_walk.push_back(p);
			else if(p != 2*Max_N + 2)
				irr_walk.push_back(p - Max_N - 1);
			p = parent[p];
		}
		reverse(irr_walk.begin(), irr_walk.end());
		// cout << "in irreducible func: ";
		// for(auto i: irr_walk)
		// 	cout << i << ", ";
		// cout << endl;
		return true;
	}
}


bool is_augmenting_path() {
	unordered_map<int,int> mp;
	for(int x: irr_walk)
		mp[x]++;
	for(auto x: mp)
		if(x.second > 1) {
			return false;
		}
	return true;
}

matching_struct get_new_matching(matching_struct g) {
	bool aug_path_has_rep = false;
	for(int x: g.aug_path)
		if(x == g.aug_cycle_rep)
			aug_path_has_rep = true;
	if(!aug_path_has_rep) {
		g.aug_path_has_rep = false;
		return g;
	}
	is_matching_edge.clear();
	for(auto x: g.M)
		is_matching_edge[x] = true;
	bool do_reverse = false;
	int rep_idx = -1;
	for(int i = 0;i < g.aug_path.size();i++) {
		if(g.aug_path[i] == g.aug_cycle_rep) {
			rep_idx = i;
			break;
		}
	}
	if(rep_idx == g.aug_path.size() - 1) {
		g.aug_path_has_rep = true;
		return g;
	}
	else if(!is_matching_edge[{g.aug_path[rep_idx], g.aug_path[rep_idx + 1]}] && 
			 !is_matching_edge[{g.aug_path[rep_idx + 1], g.aug_path[rep_idx]}])
		do_reverse = true;
	
	if(do_reverse)
		reverse(g.aug_path.begin(), g.aug_path.end());
	matching_struct g_new = g;
	g_new.aug_path.clear();
	for(int i = 0;i < g.aug_path.size();i++) {
		g_new.aug_path.push_back(g.aug_path[i]);
		if(g.aug_path[i] == g.aug_cycle_rep) {
			rep_idx = i;
			break;
		}
	}
	// get the matching m2
	map<pair<int,int>,bool> do_not_include;
	for(int i = rep_idx;i < g.aug_path.size() - 1;i+=2)
		do_not_include[{g.aug_path[i], g.aug_path[i + 1]}] = true;
	g_new.M.clear();
	for(auto x: g.M)
		if(!do_not_include[x] && !do_not_include[{x.second, x.first}])
			g_new.M.push_back(x);
	for(int i = rep_idx + 1;i < g.aug_path.size();i+=2)
		g_new.M.push_back({g.aug_path[i], g.aug_path[i + 1]});
	g_new.aug_path_has_rep = true;
	return g_new;
}

matching_struct compute_aug_cycle(matching_struct g) {
	// unordered_map<int,int> mp;
	// for(int x: irr_walk) 
	// 	mp[x]++;
	// int cnt = 0;
	// for(auto x: mp)
	// 	if(x.second > 1)
	// 		cnt++;
	// if(cnt == 1) {
	// 	aug_cycle = irr_walk;
	// 	g.aug_cycle = aug_cycle;
	// 	return g;
	// }
	unordered_map<int,int> mp2;
	int st, ed, fst_rep_node;
	for(int i = 0;i < irr_walk.size();i++) {
		mp2[irr_walk[i]]++;
		if(mp2[irr_walk[i]] > 1) {
			ed = i;
			fst_rep_node = irr_walk[i];
			break;
		}
	}
	for(int i = 0;i < irr_walk.size();i++) 
		if(irr_walk[i] == fst_rep_node) {
			st = i;
			break;
		}
	if(st == 0) {
		aug_cycle.clear();
		for(int i = st;i < ed+1;i++)
			aug_cycle.push_back(irr_walk[i]);
		// aug_cycle = irr_walk;
		return g;
	}
	else if(ed == irr_walk.size() - 1) {
		aug_cycle.clear();
		for(int i = st;i < ed+1;i++)
			aug_cycle.push_back(irr_walk[i]);
		return g;
	}
	vector<int> alt_cycle;
	for(int i = st;i <= ed;i++)
		alt_cycle.push_back(irr_walk[i]);

	vector<pair<int,int>> new_match;
	map<pair<int,int>, bool> edge_map;
	for(auto x: g.M)
		edge_map[x] = true;
	for(int i = 1;i <= st;i+=2) {
		edge_map[{irr_walk[i], irr_walk[i + 1]}] = false;
		edge_map[{irr_walk[i + 1], irr_walk[i]}] = false;
	}
	for(int i = 0;i < st;i+=2)
		edge_map[{irr_walk[i], irr_walk[i + 1]}] = true;
	// TODO: nothing is done to new_match, check
	for(auto x: edge_map)
		if(x.second)
			new_match.push_back(x.first);
	g.M = new_match;
	aug_cycle = alt_cycle;
	return g;
}

matching_struct compute_reduced_graph(matching_struct g) {
	matching_struct g_new;
	/*
	In reduced graph v_s is the last node;
	*/
	g_new.aug_cycle = aug_cycle;
	// cout << "Aug cycle: ";
	// for(auto x: aug_cycle)
	// 	cout << x << ", ";
	// cout << endl;
	// if(aug_cycle.size() == 0)
	// 	return g;
	g_new.n = g.n - aug_cycle.size() + 2;
	unordered_map<int, bool> in_aug_cycle;
	map<pair<int,int>, bool> made_edge;
	for(int x: aug_cycle)
		in_aug_cycle[x] = true;
	int cycle_rep = -1;
	for(int i = 1;i <= Max_N;i++)
		for(int j: g.G[i]) {
			if(!in_aug_cycle[i] && !in_aug_cycle[j])
				g_new.G[i].push_back(j);
			else if(!in_aug_cycle[i] && in_aug_cycle[j]) {
				if(cycle_rep == -1)
					cycle_rep = j;
				if((!made_edge[{i,cycle_rep}]) && (!made_edge[{cycle_rep,i}])) {
					made_edge[{i,cycle_rep}] = true;
					g_new.G[i].push_back(cycle_rep);
					g_new.G[cycle_rep].push_back(i);
				}
			}
			else if(in_aug_cycle[i] && !in_aug_cycle[j]) {
				if(cycle_rep == -1)
					cycle_rep = i;
				if((!made_edge[{j,cycle_rep}]) && (!made_edge[{cycle_rep,j}])) {
					made_edge[{j,cycle_rep}] = true;
					g_new.G[j].push_back(cycle_rep);
					g_new.G[cycle_rep].push_back(j);
				}
			}
		}
	if(cycle_rep == -1)
		return g_new;
	for(auto x: g.M) {
		if((!in_aug_cycle[x.first]) && (!in_aug_cycle[x.second]))
			g_new.M.push_back(x);
		else if(in_aug_cycle[x.first] && !in_aug_cycle[x.second]) {
			if((!made_edge[{x.second, cycle_rep}]) && (!made_edge[{cycle_rep, x.second}])) {
				made_edge[{x.second, cycle_rep}] = true;
				g_new.M.push_back({cycle_rep, x.second});
			}
		}
		else if(!in_aug_cycle[x.first] && in_aug_cycle[x.second]) {
			if((!made_edge[{x.first, cycle_rep}]) && (!made_edge[{cycle_rep, x.first}])) {
				made_edge[{cycle_rep, x.first}] = true;
				g_new.M.push_back({x.first, cycle_rep});
			}
		}
	}
	// for(int i = 1;i <= 6;i++) {
	// 	cout << i << ": ";
	// 	for(auto j: g_new.G[i])
	// 		cout << j << ", ";
	// 	cout << endl;
	// }
	g_new.vetrices.clear();
	for(auto i: g.vetrices)
		if(!in_aug_cycle[i])
			g_new.vetrices.push_back(i); 
	g_new.vetrices.push_back(cycle_rep);
	g_new.aug_cycle_rep = cycle_rep;
	return g_new;
}


matching_struct ComputeAugmentingPath(matching_struct g) {
	pre(g);
	// Compute an irreducible M -alternating walk W
	/* Vertex encoding for B is:
		V vertex are from 1 to Max_N
		t  := Max_N + 1
		V' vetrices are from Max_N+2 to 2*Max_N + 1
		s' := 2*Max_N + 2
	*/
	for(int i = 1;i <= Max_N;i++)
		for(auto j: g.G[i]) {
			if(is_matching_edge[{i,j}] || is_matching_edge[{j,i}])
				g.B[Max_N + 1 + i].push_back(j);
			else
				g.B[i].push_back(Max_N + 1 + j);
		}
	// for(int x: g.vetrices)
	// 	cout << x << ", ";
	// cout << endl;
	// cout << "aug cycle: ";
	// for(int x: g.aug_cycle)
	// 	cout << x << ", ";
	// cout << endl;
	for(auto i: g.vetrices)
		if(!matched_verticies[i]) {
			g.B[Max_N + 1 + i].push_back(Max_N + 1);
			g.B[2*Max_N + 2].push_back(i);
		}
	dfs_util = g;
	if(!irreducible_alt_walk()) {
		g.search_complete = true;
		return g;
	}
	if(is_augmenting_path()) {
		g.aug_path = irr_walk;
		return g;
	}
	g = compute_aug_cycle(g);
 	matching_struct g_new = ComputeAugmentingPath(compute_reduced_graph(g));
 	
 	if(g_new.search_complete) {
 		g.search_complete = true;
 		return g;
 	}
	matching_struct g_new_modified = get_new_matching(g_new);
	// dbg(g_new_modified);
	set<int> s;
	for(auto x: g_new_modified.aug_cycle)
		s.insert(x);
	int w = g_new_modified.aug_path[g_new.aug_path.size() - 2], z;
	for(auto q: g.G[w])
		if(s.find(q) != s.end()) {
			z = q;
			break;
		}
	int idx = -1;
	for(int i = 0;i < g_new_modified.aug_cycle.size();i++)
		if(g_new_modified.aug_cycle[i] == z) {
			idx = i;
			break;
		}
	if(idx != -1) {
		vector<int> new_aug_cycle;
		for(int i = idx;i < g_new_modified.aug_cycle.size() - 1;i++)
			new_aug_cycle.push_back(g_new_modified.aug_cycle[i]);
		for(int i = 0;i <= idx;i++)
			new_aug_cycle.push_back(g_new_modified.aug_cycle[i]);
		// g_new_modified.aug_cycle = new_aug_cycle;

		// cout << "g_new_modified in ComputeAugmentingPath\n";
		// dbg(g_new_modified);
		for(int i = 1;i < g_new_modified.aug_cycle.size() - 1;i+=2)
			g_new.M.push_back({g_new_modified.aug_cycle[i], g_new_modified.aug_cycle[i + 1]});
	}
	
	g.M = g_new_modified.M;
	g.aug_path.clear();
	if(!g_new_modified.aug_path_has_rep) {
		for(auto i: g_new_modified.aug_path)
			g.aug_path.push_back(i);
	}
	else {
		for(int i = 0;i < g_new_modified.aug_path.size() - 1;i++)
			g.aug_path.push_back(g_new_modified.aug_path[i]);
		g.aug_path.push_back(z);
	}
	g.search_complete = false;
	return g;
}

matching_struct max_matching(matching_struct g) {
	g = ComputeAugmentingPath(g);
	int cnt = 1;
	while(!g.search_complete) {
		// cout << "iteration " << cnt << endl;
		vector<pair<int,int>> new_matching;
		map<pair<int,int>, bool> mp;
		for(int i = 0;i < g.aug_path.size();i+=2) 
			new_matching.push_back({g.aug_path[i], g.aug_path[i + 1]});
		for(int i = 1;i < g.aug_path.size() - 1;i+=2)
			mp[{g.aug_path[i], g.aug_path[i + 1]}] = true;
		for(auto edg: g.M)
			if((!mp[edg]) && (!mp[{edg.second, edg.first}]))
				new_matching.push_back(edg);
		g.M = new_matching;
		g.aug_path.clear();
		g.aug_cycle.clear();
		g.aug_path_has_rep = false;
		for(int i = 0;i < N;i++)
			g.B[i].clear();
		g.n = NN;
		g = ComputeAugmentingPath(g);
		cnt++;
	}
	return g;
}

int main() {
	matching_struct g, g_new;
	int n, m, x, y;
	cin >> n >> m;
	NN = n;
	g.n = n;
	for(int i = 0;i < m;i++) {
		cin >> x >> y;
		g.G[x].push_back(y);
		g.G[y].push_back(x);
	}
	for(int i = 1;i <= n;i++)
		g.vetrices.push_back(i);
	g_new = max_matching(g);
	cout << g_new.M.size() << endl;
	for(auto edg: g_new.M)
		cout << edg.first << " " << edg.second << endl;
	return 0;
}
