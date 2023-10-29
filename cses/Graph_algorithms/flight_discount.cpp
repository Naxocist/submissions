#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 3;
using ll = long long ;
using pi = pair<ll, ll>;
using T = tuple<ll, int, bool>;
vector<pi> adj[N];
bool vis[N][2];
 
int main() {
	int n, m; scanf("%d%d", &n, &m);
 
	for(int i=0; i<m; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].emplace_back(v, w);
	}
 
	priority_queue<T, vector<T>, greater<T>> pq;
	pq.emplace(0, 1, 1);
 
	while(pq.size()) {
		ll d; int u; bool can; tie(d, u, can) = pq.top(); pq.pop();
		if(vis[u][can]) continue ;
		vis[u][can] = true;
		if(u == n) {
			printf("%lld", d);
			return 0;
		}
 
		for(auto e : adj[u]) {
			int v = e.first, vw = e.second;
 
			if(can) pq.emplace(d+(vw/2), v, false);
			pq.emplace(d+vw, v, can);
		}
	}
	return 0;
}
