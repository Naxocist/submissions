#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using T = tuple<int, int, int>;
const int N = 1e5 + 3;
int dsu[N];
int group;
 
int par(int u) {
	return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}
 
bool un(int u, int v) {
	u = par(u), v = par(v);
	if(u == v) return false;
	dsu[u] = v;
	group--;
	return true;
}
 
int main() {
 
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; ++i) dsu[i] = i;
	vector<T> edge;
	int u, v, w; 
	group = n;
	while(m--) {
		cin >> u >> v >> w;
		edge.emplace_back(w, u, v);
	}
 
	sort(begin(edge), end(edge));
 
	ll res = 0;
	for(auto e : edge) {
		tie(w, u, v) = e;
		if(!un(u, v)) continue; 
		res += (ll)w;
	}
 
 
	if(group != 1) {
		cout << "IMPOSSIBLE"; return 0;
	}
	
	cout << res;
	return 0;
}
