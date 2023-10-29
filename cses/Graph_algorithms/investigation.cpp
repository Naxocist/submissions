#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 3, M = 1e9 + 7;
using ll = long long;
 
const ll INF = 2e18;
using pi = pair<ll, ll>;
vector<pi> adj[N];
ll dist[N], cnt[N], mn[N], mx[N];
 
int main() {
 
	int n, m; cin >> n >> m;
 
	while(m--) {
		ll u, v, w; cin >>u >> v>> w;
		adj[u].emplace_back(v, w);
	}
 
	for(int i=1; i<=n; ++i) dist[i] = INF;
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.emplace(0, 1);
	dist[1] = 0;
	cnt[1] = 1;
	while(pq.size()) {
		ll d, u; tie(d, u) = pq.top(); pq.pop();
 
		if(d > dist[u]) continue ;
 
		for(auto e : adj[u]) {
			ll v = e.first, vw = e.second;
			if(dist[u] + vw < dist[v]) {
				dist[v] = dist[u] + vw;
				cnt[v] = cnt[u];
				mn[v] = mn[u] + 1;
				mx[v] = mx[u] + 1;
				pq.emplace(dist[v], v);
			}else if(dist[u] + vw == dist[v]) {
				cnt[v] = (cnt[v] + cnt[u]) % M;
				mn[v] = min(mn[v], mn[u] + 1);
				mx[v] = max(mx[v], mx[u] + 1);
			}
		}
	}
 
	cout << dist[n] << ' ' << cnt[n] << ' ' << mn[n] << ' ' << mx[n];
	return 0;
}
