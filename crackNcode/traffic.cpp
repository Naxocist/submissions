#include <bits/stdc++.h>
using namespace std;

#define INF 2e18

const int N = 1e5 + 3;
using ll = long long int;
using T = tuple<ll, ll, ll>;
using pi = pair<ll, ll>;
vector<T> adj[N];
ll dist[N];

ll cal(ll w, ll t) {
	return w + t*((w-1)/t);
}

int main() {

	int n, m; scanf("%d%d", &n, &m);

	for(int i=0; i<m; ++i) {
		ll u, v, w, t; scanf("%lld%lld%lld%lld", &u, &v, &w, &t);
		adj[u].emplace_back(v, w, t);
		adj[v].emplace_back(u, w, t);
	}

	priority_queue<pi, vector<pi>, greater<pi>> pq;

	for(int i=1; i<=n; ++i) dist[i] = INF;
	pq.emplace(0, 1);
	dist[1] = 0;

	while(pq.size()) {
		ll d, u; tie(d, u) = pq.top(); pq.pop();
		if(d > dist[u]) continue ;

		for(auto e : adj[u]) {
			ll v, vw, t; tie(v, vw, t) = e;

			ll r = d/t, left = t - (d % t);

			if(r % 2 == 0) {
				if(left < vw) vw = left + t + cal(vw - left, t);
			}else {
				vw = left + cal(vw, t);
			}

			if(dist[u] + vw < dist[v]) {
				dist[v] = dist[u] + vw;
				pq.emplace(dist[v], v);
			}
		}
	}

	printf("%lld", dist[n]);
	return 0;
}
