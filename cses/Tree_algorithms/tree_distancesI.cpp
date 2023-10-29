#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
vector<int> adj[N];
int a[N], b[N];
int c, f, e;
 
void dfs(int u, int p, int d) {
	if(d > c) c = d, f = u;
	for(auto v : adj[u]) {
		if(v == p) continue ;
		dfs(v, u, d + 1);
	}
}
void dfs2(int u, int p, int d[]) {
	for(auto v : adj[u]) {
		if(v == p) continue ;
		d[v] = d[u] + 1;
		dfs2(v, u, d);
	}
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, s=0, t; cin >> n;
	t = n;
	while(--t) {
		int u, v; cin >> u >> v; 
		adj[u].emplace_back(v), adj[v].emplace_back(u);
		s = u;
	}
 
	dfs(s, 0, 0); 
	dfs2(f, 0, a); c = 0;
	dfs(f, 0, 0); 
	dfs2(f, 0, b); 
	for(int i=1; i<=n; ++i) {
		cout << max(a[i], b[i]) << ' ';
	}
	return 0;
}