#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3, LOG = 20;
int up[N][LOG], dt[N];
vector<int> adj[N];
 
void dfs(int u=1, int p=0, int d = 0) {
	for(int i=1; i<LOG; ++i) up[u][i] = up[up[u][i-1]][i-1];
	for(auto v : adj[u]) {
		if(v == p) continue ;
		dt[v] = dt[u] + 1;
		dfs(v, u, d+1);
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
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q; cin >> n >> q;
	for(int i=2; i<=n; ++i) {
		int p; cin >> p; up[i][0] = p;
		adj[p].emplace_back(i);
	}
	dfs();
	for(int j=0; j<LOG; ++j) up[1][j] = 1;
 
	while(q--) {
		int a, b; cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
	return 0;
}
