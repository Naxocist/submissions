#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 1e3 + 3;
int dsu[N];
int par(int u) {return dsu[u] == u ? u : dsu[u] = par(dsu[u]);};
void un(int u, int v) {if(u == v) return ; dsu[u] = v;};
int dist(pi a, pi b) {
	int x1, y1, x2, y2;
	tie(x1, y1) = a, tie(x2, y2) = b;
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k; cin >> n >> k;
	vector<pi> v(n); vector<T> edge; vector<int> res;
	for(auto &x : v) cin >> x.first >> x.second;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<i; ++j) 
			edge.emplace_back(dist(v[i], v[j]), i, j);
	}

	iota(dsu, dsu+1+n, 0);
	sort(all(edge));
	for(auto e : edge) {
		int d, u, v; tie(d, u, v) = e; u = par(u), v = par(v);
		if(u == v) continue ;
		un(u, v);
		res.emplace_back(-d);
	}
	sort(all(res));
	cout << -res[k-1];
	return 0;
}