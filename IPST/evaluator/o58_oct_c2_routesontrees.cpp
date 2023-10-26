#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using T = tuple<ll, ll, ll>;
using pi = pair<int, ll>;
const int N = 1e5 + 3;
vector<pi> adj[N];
bool vis[N][6];
#define pb emplace_back

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;
	for(int i=0; i<m; ++i) {
		ll u, v, w; cin >> u >> v >> w;
		adj[u].pb(v, w);
	}

	priority_queue<T, vector<T>, greater<T>> pq;
	pq.emplace(0, 1, k);
	while(pq.size()) {
		ll d, u, kk; tie(d, u, kk) = pq.top(); pq.pop();
		if(vis[u][kk]) continue ;
		vis[u][kk] = 1;
		if(u == n) {
			cout << d; 
			return 0;
		}
		for(auto e : adj[u]) {
			ll v, vw; tie(v, vw) = e;
			if(vw < -100) {
				if(kk) pq.emplace(d, v, kk-1);
			}
			else if(vw < 0) pq.emplace(d, v, kk);
			else pq.emplace(d+vw, v, kk);
		}
	}
	cout << -1;
	return 0;
}