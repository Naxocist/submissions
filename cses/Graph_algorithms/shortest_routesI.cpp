#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
using pi = pair<ll, ll>;
const int N = 1e5 + 3;
ll dist[N];
vector<pi> adj[N];
 
int main() {
 
 
	int n, m; scanf("%d%d", &n, &m);
	for(int i=0; i<m; ++i) {
		int u, v; ll w; scanf("%d%d%lld", &u, &v, &w);
		adj[u].emplace_back(v, w); 
	}
 
	for(int i=0; i<=n; ++i) dist[i] = 2e18;
 
 
	priority_queue<pi> pq;
	pq.emplace(0, 1);
	dist[1] = 0;
	while(pq.size()) {
		int u; ll d; tie(d, u) = pq.top(); pq.pop();
		d *= -1;
		if(d > dist[u]) continue ;
 
		for(auto e : adj[u]) {
			int v = e.first; ll vw = e.second;
			if(dist[u] + vw < dist[v]) {
				dist[v] = dist[u] + vw;
				pq.emplace(-dist[v], v);
			}
		}
	}
 
	for(int i=1; i<=n; ++i) printf("%lld ", dist[i]);
 
	return 0;
}
