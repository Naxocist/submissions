#include <bits/stdc++.h>
using namespace std;
#define D 1

void solve() {
	int n, x; cin >> n >> x;

	int l = -1, r = 0, s = 0;
	for(int i=0; i<n; ++i) {
		int a; cin >> a; s += a;

		if(a % x) {
			if(l == -1) l = i;
			r = i;
		}
	}

	if(s % x) cout << n << '\n';
	else if(l == -1) cout << -1 << '\n';
	else cout << n - min(l+1, n-r) << '\n';

	// if(D) cout << s << '\n';
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}