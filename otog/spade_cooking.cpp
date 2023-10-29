#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 3, INF = 2e9;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
vector<pi> adj[N];
bool has[N];
int dist[N], distc[N][21];
int n, m, p, k, s; 

void a() {
	for(int i=0; i<=n; ++i) dist[i] = INF;
	priority_queue<pi> pq;
	pq.emplace(0, s);
	dist[s] = 0;
	while(pq.size()) {
		int d, u; tie(d, u) = pq.top(); pq.pop();

		for(auto e : adj[u]) {
			int v, vw; tie(v, vw) = e;
			if(dist[u] + vw < dist[v]) {
				dist[v] = dist[u] + vw;
				pq.emplace(-dist[v], v);
			}
		}
	}
}

void b() {
	for(int i=0; i<=n; ++i) for(int j=0; j<=k; ++j)
		distc[i][j] = INF;

	priority_queue<T> pq;
	pq.emplace(0, has[s], s);
	distc[s][has[s]] = 0;
	while(pq.size()) {
		int d, c, u; tie(d, c, u) = pq.top(); pq.pop();
		if(c > k) continue ;

		for(auto e : adj[u]) {
			int v, vw; tie(v, vw) = e;
			int cc = c + has[v];
			if(distc[u][c] + vw < distc[v][cc]) {
				distc[v][cc] = distc[u][c] + vw;
				pq.emplace(-distc[v][cc], cc, v);
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> p >> k;

	while(m--) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
	}

	while(p--) {
		int u; cin >> u; has[u] = 1;
	}

	cin >> s;
	a(), b();

	int res = INF;
	for(int i=1; i<=n; ++i) {
		if(distc[i][k] == INF) continue ;
		res = min(res, distc[i][k] + dist[i]);
	}

	if(res == INF) cout << "NO FOOD :("; 
	else cout << res;
	return 0;
}