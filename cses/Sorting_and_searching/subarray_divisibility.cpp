#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	vector<ll> v(n); for(auto &x : v) cin >> x;
	map<ll, int> cnt;
	ll qs = 0, res = 0;
	cnt[0] = 1;
	for(auto x : v) {
		qs += x%n; qs += n, qs %= n;
		res += cnt[qs % n];
		cnt[qs % n] ++;
	}
	cout << res;
	return 0;
}
