#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	vector<pi> v(n);
	for(auto &x : v) cin >> x.first >> x.second;

	sort(v.begin(), v.end());
	using ll = long long;
	ll now = 0, res = 0;
	
	for(auto x : v) {
		int t, d; tie(t, d) = x;
		now += t;
		res += d - now;
	}

	cout << res;
	return 0;
}