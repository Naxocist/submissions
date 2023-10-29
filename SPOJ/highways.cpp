#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
void solve() {
	int n, m, s, t; cin >> n >> m >> s >> t;

	vector<pi> adj[n+1];
	vector<int> dist(n+1, 2e9);
	for(int i=0; i<m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
	}

	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.emplace(0, s);
	dist[s] = 0;
	while(pq.size()) {
		int d, u; tie(d, u) = pq.top(); pq.pop();

		for(auto e : adj[u]) {
			int v = e.first, vw = e.second;
			if(dist[u] + vw < dist[v]) {
				dist[v] = dist[u]+vw;
				pq.emplace(dist[v], v);
			}
		}
	}

	if(dist[t] == 2e9) cout << "NONE";
	else cout << dist[t] ;
	cout << '\n';
}
int main() {
	int q; cin >> q;
	while(q--) {
		solve();
	}
	return 0;
}