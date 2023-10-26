#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 3, mod = 1e9 + 7;
using ll = long long;
vector<int> adj[N];
ll dp[N], fac[N];

void dfs(int u, int p) {

	dp[u] = 1;
	int child = 0;
	for(int v : adj[u]) {
		if(v == p) continue ;
		dfs(v, u);
		dp[u] *= dp[v], dp[u] %= mod;
		child ++;
	}

	dp[u] *= fac[child], dp[u] %= mod;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	fac[0] = 1;
	for(int i=1; i<N; ++i) fac[i] = fac[i-1] * i, fac[i] %= mod;
	int n; cin >> n;
	unordered_set<int> s;
	int p = -1;
	for(int i=0; i<2*n-1; ++i) {
		int u; cin >> u;
		if(s.find(u) == s.end() and i) adj[u].emplace_back(p), adj[p].emplace_back(u);
		s.insert(u);
		p = u;
	}
	dfs(p, -1);
	cout << dp[p];
	return 0;
}