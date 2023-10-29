#include <bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<int, int> mp;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ll n, m; cin >> n >> m;
	vector<ll> v(n);
	for(auto &x : v) cin >> x, mp[x] ++;
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));

	for(int i=1; i<=m; ++i) {
		ll res = 0;
		for(auto x : v) res += (x/i) * mp[x], cout << x%i << ' ';
		cout << endl;
		cout << res << '\n';
	}
	return 0;
}