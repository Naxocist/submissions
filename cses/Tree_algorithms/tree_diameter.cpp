#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
vector<int> adj[N];
int crr, f;
 
void dfs(int u, int p, int d) {
	if(d > crr) crr = d, f = u;
	for(auto v : adj[u]) {
		if(v == p) continue ;
		dfs(v, u, d + 1);
	}
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, s=0; cin >> n;
	while(--n) {
		int u, v; cin >> u >> v; 
		adj[u].emplace_back(v), adj[v].emplace_back(u);
		s = u;
	}
 
	dfs(s, 0, 0);
	dfs(f, 0, 0);
	cout << crr;
	return 0;
}