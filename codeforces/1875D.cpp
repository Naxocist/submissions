#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void f() {
	ll n; cin >> n;
	ll mex = 0, mn = LLONG_MAX;
	unordered_map<ll, ll> cnt;
	vector<ll> v(n); for(auto &x : v) cin >> x;
	sort(v.begin(), v.end());

	for(auto x : v) mex += (x == mex), cnt[x] ++, mn = min(mn, x);

	ll res = LLONG_MAX, rm = 0;
	for(auto e : cnt) {
		ll t = mex*(e.second-1) + e.first;
		if(e.first != mn) t += e.first*(cnt[mn]-1);
		if(!mex) t = 0;
		if(t < res) {
			res = t;
		}
	}

	cout << res << '\n';
}

int main() {
	int n; cin >> n;
	while(n--) f();
	return 0;
}