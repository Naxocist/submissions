#include <bits/stdc++.h>
using namespace std;
const int N = 8e4 + 3, M = (1<<19) + 3;
using pi = pair<int, int>;
vector<pi> adj[M];
int dist[M];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, s; cin >> n >> s;

	vector<int> bad;
	for(int i=0; i<n; ++i) {
		int w; cin >> w;
		int a = 0, b = 0;
		for(int j=0; j<s; ++j) {
			int x; cin >> x;
			if(x == -1) b |= (1 << j);
			if(x == 1) a |= (1 << j);
		}
		adj[b].emplace_back(a, w);
		bad.emplace_back(b);
	}

	for(int i=0; i<(1<<s); ++i) {
		for(int j=0; j<s; ++j) {
			if(i&(1<<j)) {
				adj[i].emplace_back(i^(1<<j), 0);
			}
		}
	}

	for(int i=0; i<(1<<s); ++i) dist[i] = 2e9;
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.emplace(0, 0);
	dist[0] = 0;
	while(pq.size()) {
		int d, u; tie(d, u) = pq.top(); pq.pop();
		if(dist[u] < d) continue ;
		for(auto e : adj[u]) {
			int v, vw; tie(v, vw) = e;
			if(dist[u] + vw < dist[v]) {
				dist[v] = dist[u] + vw;
				pq.emplace(dist[v], v);
			}
		}
	}

	int res = 0;
	for(auto b : bad) res = max(res, (dist[b]==2e9?0:dist[b]));

	cout << res;
	return 0;
}