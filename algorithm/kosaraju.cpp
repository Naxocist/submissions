#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
vector<int> adj[N], rev[N];
stack<int> st;
bitset<N> vis;

void dfs(int u) {
	for(int v : adj[u]) {
		if(vis[v]) continue ;
		vis[v] = 1;
		dfs(v);
	}
	st.push(u);
}
void dfs2(int u) {
	for(int v : rev[u]) {
		if(vis[v]) continue ;
		vis[v] = 1;
		dfs2(v);
	}
}
int main() {
	int n, m; cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v); rev[v].emplace_back(u);
	}
	for(int i=0; i<n; ++i) {
		if(!vis[i]) dfs(i);
	}
	vis.reset();
	int scc = 0;
	while(st.size()) {
		int u = st.top(); st.pop();
		if(vis[u]) continue ;
		dfs2(u);
		scc++;
	}
	cout << scc;
	return 0;
}

/*
8 10
6 1
1 2
2 6
2 3
3 4
4 5
5 0
0 4
0 7
4 7
*/