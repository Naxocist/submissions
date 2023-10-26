#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

void solve() {
	int m, y, n; cin >> m >> y >> n;

	int end = 0, ok = 1, cnt = 0, c = 0;
	for(int i=0; i<n; ++i) {
		int x; cin >> x;
		int l = max(0, x-y), r = min(m, x+y);
		if(l > c) ok = 0;
		if(l > end) {
			cnt ++ ;
			end = c;
		}
		c = r;
	}
	if(end != m) cnt++;
	if(!ok || c != m) cout << "IMPOSSIBLE\n";
	else cout << cnt << '\n';
}

int main() {
	int q; cin >> q;
	for(int i=1; i<=q; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}