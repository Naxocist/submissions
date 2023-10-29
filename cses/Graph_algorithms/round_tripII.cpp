#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 3;
vector<int> adj[N];
int path[N], color[N];
 
int dfs(int u) {
	if(color[u] == 2) return 0;
	if(color[u] == 1) return u;
 
	color[u] = 1;
	for(int v : adj[u]) {
		if(color[v] == 2) continue ;
		path[v] = u;
		int d = dfs(v);
		if(d) return d;
	}
 
	color[u] = 2;
 
	return 0;
}
 
int main() {
 
	int n, m; scanf("%d%d", &n, &m);
 
	for(int i=0; i<m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
 
	for(int i=1; i<=n; ++i) path[i] = 0;
 
	for(int i=1; i<=n; ++i) {
		if(color[i] == 0) {
			int head = dfs(i);
			if(!head) continue ;
 
			stack<int> st;
			int p = path[head];
			st.push(head);
			while(p != head && p) st.push(p), p = path[p];
			st.push(head);
			printf("%d\n", st.size());
			while(st.size()) printf("%d ", st.top()), st.pop();
			return 0;
		}
	}
 
	printf("IMPOSSIBLE");
	return 0;
}
