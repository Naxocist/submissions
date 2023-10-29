#include <bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<int, int> mp;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ll n, m; cin >> n >> m;
	vector<ll> v(n);
	for(auto &x : v) cin >> x;

	for(int i=1; i<=m; ++i) {
		ll res = 0;
		for(auto x : v) res += x/i;
		cout << res << '\n';
	}
	return 0;
}