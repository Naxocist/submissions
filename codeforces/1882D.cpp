#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
using ll = long long;
const int N = 2e5 + 3;
vector<ll> adj[N], val, res; 
ll sub[N], par[N], n, t;

void dfs(int u, int p) {
	sub[u] = 1;
	for(int v : adj[u]) {
		if(v == p) continue ;
		dfs(v, u);
		sub[u] += sub[v];
	}
	if(p) t += sub[u]*(val[u]^val[p]);
}

void dfs2(int u, int p, ll t) {
	res[u] = t;
	for(int v : adj[u]) {
		if(v == p) continue ;
		ll xr = val[u]^val[v];
		dfs2(v, u, t - xr*sub[v] + xr*(n-sub[v]));
	}
}


void f() {
	cin >> n;
	val.resize(n+1); res.resize(n+1);
	t = 0;
	for(int i=1; i<=n; ++i) cin >> val[i], adj[i].clear(), sub[i]=0, res[i] = 0;
	

	for(int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].pb(v), adj[v].pb(u);
	}
	dfs(1, 0);
	dfs2(1, 0, t);
	for(int i=1; i<=n; ++i) cout << res[i] << ' ';
	cout << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) f();
	return 0;
}