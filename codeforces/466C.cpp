#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 3;
using ll = long long;
ll qs[N];
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n; vector<ll> v(n+1);
	ll s = 0;
	for(int i=1; i<=n; ++i) {
		cin >> v[i]; s += v[i];
	}

	if(s%3) {
		cout << 0; return 0;
	}
	ll k = s/3;

	ll t = 0;
	for(int i=n; i>=1; --i) {
		t += v[i];
		qs[i] = qs[i+1] + (t==k);
	}

	ll res = 0; t = 0;
	for(int i=1; i<=n-2; ++i) {
		t += v[i];
		res += (t==k)*qs[i + 2];
	}
	cout << res;
	return 0;
}