#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
vector<pi> adj[N];
bool vis[N][20];

int main() {
	int n, m, q; cin >> n >> m >> q;
	while(m--) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
	}

	priority_queue<T, vector<T>, greater<T>> pq;
	pq.emplace(0, 1, 0);
	pq.emplace(0, 1, q);
	while(pq.size()) {
		int d, u, c; tie(d, u, c) = pq.top(); pq.pop();
		if(vis[u][c]) continue ;
		vis[u][c] = 1;
		if(u == n) {
			cout << d; return 0;
		}
		for(auto e : adj[u]) {
			int v, vw; tie(v, vw) = e;
			if(c == 0) pq.emplace(d, v, q-1), pq.emplace(d + vw, v, 0);
			else pq.emplace(d + vw, v, c-1);
		}
	}

}