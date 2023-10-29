#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3, LOG = 20;
vector<int> adj[N];
int up[N][LOG], dt[N];
 
void dfs(int u=1, int p=1, int d=0) {
	up[u][0] = p;
	for(int i=1; i<LOG; ++i) up[u][i] = up[up[u][i-1]][i-1];
	for(auto v : adj[u]) {
		if(v == p) continue ;
		dt[v] = dt[u] + 1;
		dfs(v, u, d + 1);
	}
}
 
int lca(int a, int b) {
	if(dt[a] < dt[b]) swap(a, b);
 
	int t = dt[a] - dt[b];
	for(int i=0; i<LOG; ++i) {
		if(t & (1 << i)) a = up[a][i];
	}
	if(a == b) return a;
 
	for(int i=LOG-1; i>=0; --i) {
		if(up[a][i] != up[b][i]) {
			a = up[a][i], b = up[b][i];
		}
	}
	return up[a][0];
}
 
 
int main() {
	int n, q; cin >> n >> q;
	for(int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v), adj[v].emplace_back(u);
	}
 
	dfs();
	while(q--) {
		int a, b; cin >> a >> b;
		int l = lca(a, b);
		cout << dt[a] + dt[b] - 2*dt[l] << '\n';
	}
 
	return 0;
}
