#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
using ll = long long;
using pi = pair<int, int>;
vector<int> adj[N];
ll fw[N], idx, p[N];
int st[N], ed[N];
 
void upd(int i, ll x) {
	for(;i<N;i+=i&-i) fw[i] += x;
}
 
ll qry(int i) {
	ll s=0;
	for(;i>0;i-=i&-i) s += fw[i];
	return s;
}
 
void dfs(int u=1, int r=0) {
	upd(st[u] = ++idx, p[u]);
	for(auto v : adj[u]) {
		if(v == r) continue ;
		dfs(v, u);
	}
	ed[u] = idx;
}
 
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q; cin >> n >> q;
	for(int i=1; i<=n; ++i) cin >> p[i];
	for(int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v), adj[v].emplace_back(u);
	}
	dfs();
	while(q--) {
		int k, a, c, d; cin >> k >> a;
		if(k == 2) {
			cout << qry(ed[a]) - qry(st[a]-1) << '\n';
		}else {
			upd(st[a], -p[a]);
			cin >> p[a];
			upd(st[a], p[a]);
		}
	}
	return 0;
}
