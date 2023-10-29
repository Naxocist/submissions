#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int ar[N];

int main() {

	int n, q; cin >> n >> q;

	for(int i=1; i<=n; ++i) cin >> ar[i];

	while(q--) {
		char c; int l, r, x;
		cin >> c;
		if(c == 'M') {
			cin >> l >> r;
			ar[l] = r;
		}else {
			cin >> l >> r >> x; int cnt = 0;
			for(;l<=r; ++l) cnt += (ar[l] <= x);
			cout << cnt << '\n';
		}
	}
	return 0;
}