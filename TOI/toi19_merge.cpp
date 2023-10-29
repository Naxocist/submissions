#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int x[N], y[N], xt[N], yt[N];
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, q; cin >> n >> m >> q;
	for(int i=0; i<n; ++i) cin >> x[i];
	for(int i=1; i<=n; ++i) cin >> xt[i], xt[i] += xt[i-1];

	for(int i=0; i<m; ++i) cin >> y[i];
	for(int i=1; i<=m; ++i) cin >> yt[i], yt[i] += yt[i-1];

	while(q--) {
		int a, b, k; cin >> a >> b >> k;

		int l = -1e9, r = 1e9, res = 0;
		while(l < r) {
			int md = l + (r-l)/2;
			int xx = xt[upper_bound(x,x+n, md) - x];
			int yy = yt[upper_bound(y, y+m, (md-b)/a) - y];
			if(xx + yy >= k) r = md, res = md;
			else l = md + 1; 
		}
		cout << res << '\n';
	}

	return 0;
}