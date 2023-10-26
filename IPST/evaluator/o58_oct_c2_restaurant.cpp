#include <bits/stdc++.h>
using namespace std;
const int N = 303;
int d[N][N], deg[N];
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, t; cin >> n >> t;
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) cin >> d[i][j];

	for(int i=1; i<=n; ++i) {
		for(int j=i+1; j<=n; ++j) {
			for(int k=1; k<=n; ++k) {
				if(k == i || k == j) continue ;
				if(d[i][k] + d[k][j] == d[i][j]) 
					goto g;
			}
			deg[i] ++, deg[j] ++;
			g:;
		}
	}

	for(int i=1; i<=n; ++i) {
		if(deg[i] >= 3) {
			cout << i << '\n';
			if(t == 2) cout << deg[i];
			return 0;
		}
	}
	return 0;
}