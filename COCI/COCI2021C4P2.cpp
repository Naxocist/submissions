#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX

using ll = long long;
using pi = pair<ll, ll>;
using T = tuple<ll, int, int>;
const int N = 73;
ll edge[N][N], dist[N][N];
vector<pi> adj[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for(int i=0; i<=n; ++i) {
		for(int j=0; j<=n; ++j) edge[i][j] = INF;
		edge[i][i] = 0;
	}
	while(m--) {
		ll u, v, w; cin >> u >> v >> w;
		edge[u][v] = min(edge[u][v], w);
	}

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if(i == j || edge[i][j] == INF) continue ;
			adj[i].emplace_back(j, edge[i][j]);
		}
	}

	ll lim, q; cin >> lim >> q;
	lim = min(lim, (ll)n);
	while(q--) {
		int x, y; cin >> x >> y;

		priority_queue<T, vector<T>, greater<T>> pq;
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) dist[i][j] = INF;
		}
		pq.emplace(0, x, 0);
		dist[x][0] = 0;
		while(pq.size()) {
			ll d, u, p; tie(d, u, p) = pq.top(); pq.pop();
			if(u == y) {
				cout << d << '\n';
				goto g;	
			}
			
			if(p == lim) continue ;
			for(auto e : adj[u]) {
				ll v, vw; tie(v, vw) = e;
				if(dist[u][p] + vw < dist[v][p + 1]) {
					dist[v][p+1] = dist[u][p] + vw;
					pq.emplace(dist[v][p+1], v, p+1);
				}
			}
		}
		cout << -1 << '\n';
		g:;
	}
	return 0;
}