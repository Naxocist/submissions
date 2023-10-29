 #include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
void f() {
	int n; cin >> n;

	int mn = INF, mnW = INF, res = 0;
	for(int i=1; i<=n; ++i) {
		int x; cin >> x;
		if(x > mn and x < mnW) res ++, mnW = x;
		mn = min(mn, x);
	}
	cout << res << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) f();
	return 0;
} 