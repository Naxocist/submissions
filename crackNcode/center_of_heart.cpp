#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 3;
using pi = pair<int, int>;
pi edge[N];
vector<int> adj[N], flip[N], adj2[N], flip2[N];
bitset<N> vis;

void dfs(int u, int p) {

	vis[u] = 1;
	for(int v : adj2[u]) {
		if(vis[v] || v == p) continue ;
		dfs(v, u);
	}
	return ;
}

int main() {

	int n, m, t, d; scanf("%d%d%d%d", &n, &m, &t, &d);

	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v); flip[v].push_back(u);
	}

	for(int i=1; i<=t; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		edge[i] = pi(u, v);
	}

	int l = 1, r = t;
	int res = -1;
	while(l < r) {
		int md = l + (r-l)/2;


		for(int i=1; i<=n; ++i) {
			adj2[i].clear();
			adj2[i] = adj[i];
			flip2[i].clear();
			flip2[i] = flip[i];
		}

		for(int i=1; i<=md; ++i) {
			int u, v; tie(u, v) = edge[i];
			adj2[u].push_back(v); flip2[v].push_back(u);
		}

		int PP = 0;

		PP--;
		if(PP <= d) r = md - 1, res = md;
		else l = md + 1;
	}

	printf("%d", res);

	return 0;
}