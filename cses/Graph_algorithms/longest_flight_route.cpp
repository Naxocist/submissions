#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 3;
vector<int> adj[N];
int dist[N], path[N];
 
int main() {
 
	int n, m; scanf("%d%d", &n, &m);
	for(int i=0; i<m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
 
	for(int i=1; i<=n; ++i) path[i] = -1;
	stack<int> q;
	q.emplace(1);
 
	dist[1] = 1;
 
	int mx = 0;
	
	while(q.size()) {
		int u = q.top(); q.pop();
 
		for(int v : adj[u]) {
			if(dist[u] + 1 <= dist[v]) continue ;
			path[v] = u;
			dist[v] = dist[u] + 1;
			q.emplace(v);
		}
	}
 
	if(dist[n] == 0) {
		printf("IMPOSSIBLE"); return 0;
	}
 
	printf("%d\n", dist[n]);
 
	int p = path[n];
	vector<int> res;
	res.push_back(n);
	while(p != -1) res.push_back(p), p = path[p];
 
	for(int i=res.size()-1; i>=0; --i) printf("%d ", res[i]);
	return 0;
}
