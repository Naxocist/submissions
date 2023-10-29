#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
using pi = pair<int, int>;
vector<pi> adj[N];

int dfs(int u, int k, int p) {
	int cnt = 1;
	for(auto e : adj[u]) {
		int v = e.first,  vw = e.second;
		if(v == p) continue ;
		if(vw >= k) cnt += dfs(v, k, u); 
	}

	return cnt;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("mootube.in", "r", stdin);
	// freopen("mootube.out", "w", stdout);
	int n, m; cin >> n >> m;
	for(int i=1; i<n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
	}

	while(m--) {
		int k, u; cin >> k >> u;
		cout << dfs(u, k, 0) - 1 << '\n';
	}
	return 0;
}