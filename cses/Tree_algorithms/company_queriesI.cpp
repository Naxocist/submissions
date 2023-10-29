#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3, LOG = 20;
int up[N][LOG];
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q; cin >> n >> q;
	for(int i=2; i<=n; ++i) {
		cin >> up[i][0];
	}
	up[1][0] = 0;
	for(int j=1; j<LOG; ++j) {
		up[1][j] = 0;
		for(int i=2; i<=n; ++i) {
			up[i][j] = up[up[i][j-1]][j-1];
		}
	}
 
	while(q--) {
		int x, k; cin >> x >> k;
		for(int i=0; i<LOG; ++i) {
			if(k & (1 << i)) x = up[x][i];
		}
		if(!x) cout << -1 << '\n';
		else cout << x << '\n';
	}
	return 0;
}