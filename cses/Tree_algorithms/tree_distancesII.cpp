#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
using ll = long long;
vector<int> adj[N];
ll sub[N], res[N], n, t;
 
void dfs(int u=1, int p=0, int d=0) {
	res[1] += d;
	sub[u] = 1;
	for(auto v : adj[u]) {
		if(v == p) continue ;
		dfs(v, u, d+1);
		sub[u] += sub[v];
	}
}
 
void dfs2(int u=1, int p=0) {
	if(u!=1) res[u] = res[p] + n - 2*sub[u];
	for(auto v : adj[u]) {
		if(v == p) continue ;
		dfs2(v, u);
		
	}
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n; t = n;
	while(--t) {
		int u, v; cin >> u >> v; 
		adj[u].emplace_back(v); adj[v].emplace_back(u);
	}
 
	dfs();
	dfs2();
	for(int i=1; i<=n; ++i) cout << res[i] << ' ';
	return 0;
}
