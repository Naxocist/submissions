#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int low[N], t[N], c = 0;
vector<int> adj[N];
set<int> ap;

void dfs(int u, int p) {
	low[u] = t[u] = ++c;
	int child = 0;
	for(int v : adj[u]) {
		if(!t[v]) {
			child ++;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if((p and low[v] >= t[u]) || (p == 0 and child > 1)) {
				ap.insert(u);
			}

			if(low[v] > t[u]) {
				cout << u << ' ' << v << '\n';
			}
		}else if(v != p){
			low[u] = min(low[u], low[v]);
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v); adj[v].emplace_back(u);
	}
	dfs(1, 0);
	for(auto x : ap) cout << x << '\n';
	return 0;
}
/*
12 14
1 2
2 3
3 4
4 1
4 5
5 6
6 7
7 8
8 9
9 6
8 10
10 11
11 12
12 10
*/