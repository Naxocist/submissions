#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 3;
int dsu[N], sz[N];
int group, mx = 1;
 
int par(int u) {
	return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}
 
void un(int u, int v) {
	u = par(u), v = par(v);
	if(u == v) return;
	group --;
	dsu[u] = v;
	sz[v] += sz[u];
	mx = max(mx, sz[v]);	
} 
 
int main() {
	int n, m; cin >> n >> m;
	group = n;
	for(int i=1; i<=n; ++i) dsu[i] = i, sz[i] = 1;
 
	for(int i=0; i<m; ++i) {
		int u, v; cin >> u >> v;
		un(u, v);
		cout << group << ' ' << mx << '\n';
	}
	return 0;
}
