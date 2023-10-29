#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
using ll = long long;
using pi = pair<int, int>;
ll deg[N], d1[N], d2[N], mxd[N];
vector<pi> adj[N];

void dfs(int u, int p, ll d[]) {
	for(auto e : adj[u]) {
		int v, vw; tie(v, vw) = e;
		if(v == p) continue ;
		d[v] = d[u] + vw;
		dfs(v, u, d);
	}
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for(int i=1; i<n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		deg[u] ++, deg[v] ++;
	}

	for(int i=1; i<=n; ++i) {
		if(deg[i] == 1) {
			dfs(i, 0, d1);
			break ;
		}
	}
	ll mx = 0, a = 0;
	for(int i=1; i<=n; ++i) {
		if(d1[i] > mx) mx = d1[i], a = i;
	}

	memset(d1, 0, sizeof d1);
	dfs(a, 0, d1);
	mx = 0; ll b = 0;
	for(int i=1; i<=n; ++i) {
		if(d1[i] > mx) mx = d1[i], b = i;
	}

	dfs(b, 0, d2);

	for(int i=1; i<=n; ++i) {
		mxd[i] = max(d1[i], d2[i]);
	}
	
	sort(mxd+1, mxd+1+n);
	vector<int> v(m);
	for(auto &x : v) cin >> x;
	sort(v.rbegin(), v.rend());

	ll res = 0;
	for(int i=0; i<m; ++i) {
		res += v[i] * mxd[i+1];
	}
	cout << res;
	return 0;
}
