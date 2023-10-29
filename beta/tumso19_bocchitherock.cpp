#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
using ll = long long;
const int N = 1e5 + 3;
using pi = pair<ll, ll>;
ll dist[N];
vector<pi> adj[N];
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	while(m--) {
		ll u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
	}

	int t; cin >> t;
	while(t--) {
		ll u, w; cin >> u >> w;
		adj[n+1].emplace_back(u, w); adj[u].emplace_back(n+1, w);
	}

	for(int i=0; i<=n; ++i) dist[i] = INF;
	priority_queue<pi> pq;
	pq.emplace(0, n+1);

	while(pq.size()) {
		ll d, u; tie(d, u) = pq.top(); pq.pop();

		for(auto e : adj[u]) {
			ll v, vw; tie(v, vw) = e;
			if(dist[u] + vw < dist[v]) {
				dist[v] = dist[u] + vw;
				pq.emplace(-dist[v], v);
			}
		}
	}

	cout << dist[0];
	return 0;
}