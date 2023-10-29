#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ll n, t; cin >> n >> t;
	vector<ll> v(n);
 
	ll mx = 0;
	for(auto &x : v) {
		cin >> x; mx = max(mx, x);
	}
 
	ll l = 0, r = 2e18, res = LLONG_MAX;
	while(l <= r) {
		ll md = l + (r-l)/2;
 
		ll cnt = 0;
		for(ll x : v) {
			cnt += md/x;
			if(cnt >= t) break ;
		}
 
		if(cnt >= t) r = md - 1, res = min(res, md);
		else l = md + 1;
	}
 
	cout << res;
	return 0;
}
