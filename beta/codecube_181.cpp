#include <bits/stdc++.h>
using namespace std;
using T = tuple<int, int, int>; 
using pi = pair<int, int>;
const int N = 4e4 + 3;
int dsu[N], u, v, w, n, m, p, mw;
int par(int u) {return dsu[u] == u ? u : dsu[u] = par(dsu[u]);}
void un(int u, int v) {u = par(u), v = par(v); if(u == v) return; dsu[u] = v;}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> p;
	vector<T> ed; 
	vector<pi> P;
	while(m--) {
		cin >> u >> v >> w; mw = max(mw, w);
		ed.emplace_back(u, v, w); un(u, v);
	}
	while(p--) cin >> u >> v, P.emplace_back(u, v);
	int l = 0, r = mw+1, res = -1;
	while(l <= r) {
		int md = l + (r-l)/2;
		for(int i=1; i<=n; ++i) dsu[i] = i;
		for(auto e : ed) {
			tie(u, v, w) = e;
			if(w < md) un(u, v);
		}
		bool ok = true;
		for(auto x : P) 
			if(par(x.first) == par(x.second)) ok = 0; 	
		if(ok) res = md, l = md + 1;
		else r = md - 1;
	}
	cout << (res == mw + 1 ? -1 : res);
	return 0;
}