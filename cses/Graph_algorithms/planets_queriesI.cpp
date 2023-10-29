#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3, M = 1e9+3;
const int L = log2(M);
int jump[N][L+3]; // jump 2^j times from i
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q; cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> jump[i][0];
	}
 
	for(int i=1; i<=L; ++i) {
		for(int j=1; j<=n; ++j) {
			jump[j][i] = jump[jump[j][i-1]][i-1];
		}
	}
 
	while(q--) {
		int x, t; cin >> x >> t;
		for(int c=0;t;t>>=1, c++) {
			if(t&1) x = jump[x][c];
		}
		cout << x << '\n';
	}
 
	return 0;
}
