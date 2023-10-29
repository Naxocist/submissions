#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
using ll = long long;
ll v[N], qs[N];

ll f(ll t) {
	ll c = 0;
	for(;t&1^1;t>>=1) c++;
	return 1<<c;
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		ll x; cin >> x;
		v[i] = x;
		qs[i] += qs[i-1] + f(x);
	}

	int q; cin >> q;
	while(q--) {
		ll x; cin >> x;
		ll t = lower_bound(qs+1, qs+1+n, x) - qs;
		cout << v[t]/(qs[t] - qs[t-1]) << '\n';
	}

	return 0;
}