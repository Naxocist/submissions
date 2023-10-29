#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 3;
using ll = long long;
ll a[N], b[N], n, m;

bool ok(ll md) {
	long long cnt = 0;
	for(int i=1; i<=n; ++i) {
		if(a[i] * m >= md) cnt += (md + a[i] - 1)/a[i];
		else cnt += m + (md - a[i]*m + b[i] - 1)/b[i];
		if(cnt > n*m) return 0;
	}
	return 1;
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n; ++i) cin >> a[i];

	ll l = 0, r = LLONG_MAX;
	for(int i=1; i<=n; ++i) {
		cin >> b[i];
		a[i] = max(a[i], b[i]);
	}

	ll res = 0;
	while(l <= r) {
		ll md = l + (r-l)/2;
		if(ok(md)) l = md + 1, res = max(res, md);
		else r = md - 1;
	}
	cout << res;
	return 0;
}