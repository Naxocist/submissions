#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 3, M = 1e9 + 7;
vector<int> adj[N], flip[N];
int dp[N], in[N];
 
int main() {
 
	int n, m; cin >> n >> m;
	while(m--) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		flip[v].push_back(u);
		in[v]++;
	}
 
	queue<int> q;
	for(int i=1; i<=n; ++i) {
		if(in[i] == 0) q.push(i);
	}
	dp[1] = 1;
 
 
	while(q.size()) {
		int u = q.front(); q.pop();
 
		for(int v : adj[u]) {
			if(--in[v] == 0) {
				q.push(v);
			}
		}
		
		for(int f : flip[u]) {
			dp[u] += dp[f];
			dp[u] %= M;
		}
 
	}
 
 
	cout << dp[n];
	return 0;
}
