#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
const int L = log2(N);
using ll = long long int;
ll qs[N], sp[N][L+1];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;

	for(int i=1; i<=n; ++i) {
		cin >> sp[i][0];
	}

	for(int i=1; i<=n; ++i) cin >> qs[i], qs[i] += qs[i-1];

	for(int j=1; j<=L; j++) {
		for(int i=1; i+(1 << j)-1<=n; ++i) {
			sp[i][j] = max(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
		}
	}

	while(q--) {
		int l, r; cin >> l >> r, l++, r++;
		int lg = log2(r - l + 1);
		cout << max(sp[l][lg], sp[r-(1<<lg)+1][lg]) << ' ';
		cout << qs[r] - qs[l-1] << '\n';
	}
	return 0;
}