#include <bits/stdc++.h>
using namespace std; 
const int N = 1e5 + 3;
using T = tuple<int, int, int>;
using ll = long long;
using pi = pair<int, int>;
int dsu[N], color[N];
vector<pi> adj[N];

int par(int u) {
	return (dsu[u] == u ? dsu[u] : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
	u = par(u), v = par(v);
	if(u == v) return ;
	dsu[u] = v;
}
int main() {
	iota(dsu, dsu+N, 0);
	int n, m; cin >> n >> m;

	for(int i=1; i<=n; ++i) {
		cin >> color[i];
	}

	vector<T> edge;
	while(m--) {
		int u, v, w; cin >> u >> v >> w;
		edge.emplace_back(w, u, v);
	}
	sort(edge.begin(), edge.end());

	for(auto e : edge) {
		int u, v, w; tie(w, u, v) = e;
		if(par(u) == par(v)) continue ;
		un(u, v);
		adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
	}

	ll res = 0;
	

	cout << res;
	return 0;
}

/*
7 6
1 1 4 1 3 2 4
1 2 2
1 3 50
2 6 100
6 7 1
3 4 2
3 5 2
*/