#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
using T = tuple<int, int, int>;
int dsu[N], ar[N];

int par(int u) {
	return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}


int main() {

	int n; scanf("%d", &n);

	vector<T> edge;
	for(int i=1; i<=n; ++i) {
		scanf("%d", &ar[i]);
		dsu[i] = i;
	}

	int m; scanf("%d", &m);
	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		edge.emplace_back(ar[u] + ar[v], u, v);
	}

	int res = 0;
	sort(edge.begin(), edge.end());
	for(auto e : edge) {
		int u, v, w; tie(w, u, v) = e;
		u = par(u), v = par(v);
		if(u == v) continue ;
		dsu[u] = v;
		res += w;
	}

	printf("%d", res);
	return 0;
}