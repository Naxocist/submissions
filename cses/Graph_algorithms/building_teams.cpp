#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 3;
vector<int> adj[N];
int color[N];
 
bool dfs(int u, int c) {
	// printf("%d %d\n", u, c);
	if(color[u]) return color[u] == c;
 
	color[u] = c;
	for(int v : adj[u]) {
		if(!dfs(v, (c == 1 ? 2 : 1))) return false;
 
	}
 
	return true;
}
 
int main() {
 
	int n, m; scanf("%d%d", &n, &m);
 
	for(int i=0; i<m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v); adj[v].push_back(u);
	}
 
	for(int i=1; i<=n; ++i) {
		if(!color[i] && !dfs(i, 1)) {
			printf("IMPOSSIBLE");
			return 0;
		}
	}
 
	for(int i=1; i<=n; ++i) printf("%d ", color[i]);
	return 0;
}
