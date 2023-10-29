#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ll n, d; cin >> n >> d;
	ll l = 1e9, r = 0;
	vector<ll> v(n); for(auto &x : v) cin >> x, r += x, l = min(l, x);
 
	ll res = LLONG_MAX;
	while(l <= r) {
		ll md = l + (r-l)/2;
 
		ll s = 0, nd = 1;
		bool ok = 1;
		for(auto x : v) {
			if(s + x > md) s = 0, nd++;
			s += x;
 
			if(x > md) ok = 0;
		}
		// cout << md <<  ' ' << nd << endl;
		if(nd <= d and ok) r = md - 1, res = min(res, md);
		else l = md + 1;
	}
	cout << res;
	return 0;
}
