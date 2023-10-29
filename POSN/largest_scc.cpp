#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
stack<int> st;
bitset<N> vis;
vector<int> adj[N], rev[N], nd;

void dfs(int u) {
	vis[u] = 1;
	for(int v : adj[u]) {
		if(vis[v]) continue ;
		dfs(v);
	}
	st.emplace(u);
}

void dfs2(int u) {
	vis[u] = 1;
	nd.push_back(u);
	for(int v : rev[u]) {
		if(vis[v]) continue ;
		dfs2(v);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	while(m--) {
		int u, v; cin >> u >> v; adj[u].emplace_back(v);
		rev[v].emplace_back(u);
	}

	for(int i=1; i<=n; ++i) {
		if(!vis[i]) dfs(i);
	}
	vis.reset();
	vector<int> res;
	int mx = 0;
	while(st.size()) {
		int u = st.top(); st.pop();
		if(vis[u]) continue ;
		dfs2(u);
		sort(nd.begin(), nd.end());
		if(nd.size() > mx || (nd.size() == mx && nd[0] < res[0])) {
			res = nd;
			mx = nd.size();
		}
		nd.clear();
	}
	cout << mx << '\n';
	for(int x : res) cout << x << ' ';
	return 0;
}