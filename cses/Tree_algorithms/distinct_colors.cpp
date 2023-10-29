#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int fw[N], c[N], t = 1, st[N], tour[N];
vector<int> adj[N];
 
void upd(int i, int x) {
	for(;i<N;i+=i&-i) fw[i] += x;
}
 
int qry(int i) {
	int s = 0;
	for (;i>0;i-=i&-i) s += fw[i];
	return s;
}
 
void dfs(int u = 1, int p = 0) {
	st[u] = t;
	for(int v : adj[u]) if(v != p) dfs(v, u);
	tour[t] = u;
	t++;
}
 
int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) cin >> c[i];
	for(int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v), adj[v].emplace_back(u);
	}
	dfs();
	map<int, int> last;
	vector<int> res(n+1);
	for(int i=1; i<=n; ++i) {
		if(last.count(c[tour[i]])) {
			upd(last[c[tour[i]]], -1);
		}
		last[c[tour[i]]] = i;
		upd(last[c[tour[i]]], 1);
		res[tour[i]] = qry(i) - qry(st[tour[i]] - 1);
	}
 
	for(int i=1; i<=n; ++i) cout << res[i] << ' ';
	return 0;
}
