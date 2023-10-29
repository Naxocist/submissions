#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 3;
vector<int> adj[N];
int vis[N], path[N];
 
bool cycle(int u, int p) {
 
	if(vis[u] == 1) {
		int p = path[u];
		vector<int> res;
		while(p != u) res.push_back(p), p = path[p];
		printf("%d\n%d ",res.size()+2, u);
		for(int x : res) printf("%d ", x);
		printf("%d", u);
		return true;
	}
 
	vis[u] = 1;
	for(int v : adj[u]) {
		if(vis[v] == 2 || v == p) continue ;
		path[v] = u;
		if(cycle(v, u)) return true;
	}
 
	vis[u] = 2;
	return false;
}
 
int main() {
 
	int n, m; scanf("%d%d", &n, &m);
 
	for(int i=0; i<m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v); adj[v].push_back(u);
	}
 
	for(int i=1; i<=n; ++i) {
		if(!vis[i]) {
			if(cycle(i, -1)) {
				return 0;
			}
		}
	}
 
	printf("IMPOSSIBLE");
	return 0;
}
