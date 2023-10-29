#include <bits/stdc++.h>
using namespace std;
using ll = long double;
using pi = pair<ll, ll>;
using T = tuple<ll, ll, ll>;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<pi> v(n);
	for(auto &x : v) cin >> x.first >> x.second;

	vector<T> c(m);
	for(int i=0; i<m; ++i) {
		ll x, y, r; cin >> x >> y >> r;
		c[i] = T(x, y, r);
	}

	int cnt = 0;
	for(auto i : c) {
		bool in = false, out = false;
		ll a, b, r; tie(a, b, r) = i;
		for(auto j : v) {
			ll x, y; tie(x, y) = j;
			ll t = (x-a)*(x-a) + (y-b)*(y-b);
			in |= (t < r*r);
			out |= out or (t > r*r);
		}
		if(in && out) cnt ++;
	}
	cout << cnt;
	return 0;
}