#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3, LOG = 20;
int n, q, up[N][LOG], pref[N], d[N];
vector<int> adj[N];
 
void dfs(int u=1, int p=0) {
	up[u][0] = p;
	for(int i=1; i<LOG; ++i) up[u][i] = up[up[u][i-1]][i-1];
	for(int v : adj[u]) {
		if(v == p) continue ;
		d[v] = d[u] + 1;
		dfs(v, u);
	}
}
 
int lca(int a, int b) {
	if(d[a] < d[b]) swap(a, b);
	int t = d[a] - d[b];
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
 
void dfs2(int u=1, int p=0) {
	for(int v : adj[u]) {
		if(v == p) continue ;
		dfs2(v, u);
		pref[u] += pref[v];
	}
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v), adj[v].emplace_back(u);
	}
 
	dfs();
	while(q--) {
		int a, b; cin >> a >> b;
		int l = lca(a, b);
		l+=!l;
		if(l == a || l == b) {
			if(l == a) swap(a, b);
			pref[a]++ , pref[up[b][0]]--;
			continue ;
		}
 
		pref[a]++, pref[up[l][0]]--;
		pref[b]++, pref[l]--;
	}
 
	dfs2();
	for(int i=1; i<=n; ++i) cout << pref[i] << ' ';
	return 0;
}
