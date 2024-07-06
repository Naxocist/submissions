#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int n, sub[N];
vector<int> adj[N];

int dfs(int u = 1, int p = 0) {
	int s = 1;
	for(int v : adj[u]) {
		if(v == p) continue ;
		s += dfs(v, u);
	}
	return sub[u] = s;
}

int centroid(int u = 1, int  p = 0) {
	for(int v : adj[u]) {
		if(v == p) continue ;
		if(sub[v] > n/2) return centroid(v, u);
	}
	return u;
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v), adj[v].emplace_back(u);
	}
	dfs();
	cout << centroid();
	return 0;
}