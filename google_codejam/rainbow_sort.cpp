#include <bits/stdc++.h>
using namespace std;



void solve() {
	int n; cin >> n;

	vector<int> v(1e5 + 3, 0), res ;
	bool ok = 1;
	for(int i=1; i<=n; ++i) {
		int x; cin >> x;
		if(v[x] == 0) res.push_back(x), v[x] = i;
		else {
			if(v[x] != i-1) ok = 0;
			else v[x] = i;
		}
	}

	if(ok) for(auto x : res) cout << x << ' ';
	else cout << "IMPOSSIBLE";
	cout << '\n';
}

int main() {
	int q; cin >> q;
	for(int i=1; i<=q; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}