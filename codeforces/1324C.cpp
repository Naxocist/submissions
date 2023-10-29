#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

void f() {
	int prev = 0, mx = 0;
	string s; cin >> s; int n = s.size();
	for(int i=1; i<=n; ++i) {
		char x = s[i-1];
		if(x == 'R') {
			mx = max(mx, i - prev);
			prev = i;
		}
	}

	cout << max(mx, n+1-prev) << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) f();
	return 0;
}