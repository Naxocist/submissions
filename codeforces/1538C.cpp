#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void f() {
	int n, l, r; cin >> n >> l >> r;
	vector<int> v(n); for(auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	ll res = 0;
	for(int i=0; i<n; ++i) {
		int a = lower_bound(v.begin(), v.end(), l-v[i]) - v.begin();
		int b = upper_bound(v.begin(), v.end(), r-v[i]) - v.begin();
		res += b-a-(l <= 2*v[i] and 2*v[i] <= r);
	}
	cout << res/2 << '\n';
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;cin >> t;
	while(t--) f();
	return 0;
}