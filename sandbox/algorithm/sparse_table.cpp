#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
const int L = log2(N);
int sp[N][L+1], ar[N];

int main() {

	int n; cin >> n;

	for(int i=1; i<=n; ++i) cin >> ar[i], sp[i][0] = ar[i];

	for(int j=1; j<=L; j++) {
		for(int i=1; i+(1<<(j-1))<=n; ++i) {
			sp[i][j] = max(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
		}
	}


	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;

		int lg = log2(r - l + 1);
		cout << max(sp[l][lg], sp[r-(1 << lg)+1][lg]) << '\n';
	}

	return 0;
}