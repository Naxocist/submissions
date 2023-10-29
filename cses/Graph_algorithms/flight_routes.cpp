#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 3;
using ll = long long;
using pi = pair<ll, ll>;
vector<pi> adj[N];
int cnt[N];
 
int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
 
	for(int i=0; i<m; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].emplace_back(v, w);
	}
 
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.emplace(0, 1);
 
	while(pq.size()) {
		int u; ll d; tie(d, u) = pq.top(); pq.pop();
		if(cnt[u] > 10) continue ;
		cnt[u] ++;
 
		if(u == n) {
			k--;
			printf("%lld ", d);
		}
		if(!k) break ;
 
		for(auto e : adj[u]) {
			int v = e.first; ll vw = e.second;
			pq.emplace(d + vw, v);
		}
	}
 
 
	return 0;
}
