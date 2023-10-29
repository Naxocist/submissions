#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;

	ll mn = LLONG_MAX, s = 0, t = n;
	while(t--) {
		ll x; cin >> x;
		mn = min(mn, x);
		s += x;
	}

	cout << s + (n-2)*mn;
	return 0;
}