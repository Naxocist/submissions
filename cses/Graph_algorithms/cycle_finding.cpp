#include <bits/stdc++.h>
using namespace std;
 
const int N = 2505;
using ll = long long;
using T = tuple<int, int, int>;
using pi = pair<int, int>;
vector<T> edge;
vector<pi> adj[N];
ll dist[N];
int path[N], vis[N];
 
 
int main() {
	int n, m; scanf("%d%d", &n, &m);
 
	while(m--) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		edge.emplace_back(u, v, w);
		adj[u].emplace_back(v, w);
	}
 
	for(int i=1; i<=n; ++i) path[i] = -1, dist[i] = 2e18;
	dist[1] = 0;
 
	int x;
	for(int i=0; i<n; ++i) {
		x = -1;
		for(auto e : edge) {
			int u, v, w; tie(u, v, w) = e;
			if(dist[u] + (ll)w < dist[v]) {
				dist[v] = dist[u] + (ll)w;
				path[v] = u;
				x = v;
			}
		}
	}
 
 
	if(x == -1) {
		printf("NO"); return 0;
	}
	for(int i=1; i<=n; ++i) x = path[x];
 
	stack<int> res;
	printf("YES\n");
	for(int u = x; ;u = path[u]) {
		res.push(u);
		if(u == x && res.size() > 1) break ;
	}
	while(res.size()) printf("%d ", res.top()), res.pop();
	return 0;
}
