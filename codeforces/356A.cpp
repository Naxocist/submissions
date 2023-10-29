#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 3;
int res[4*N];

void upd(int i, int l, int r, int L, int R, int v) {
	if(R < l || r < L || L > R || res[i]) return ;
	if(L <= l and r <= R) {
		res[i] = v;
		return ;
	}
	int m = (l+r)>>1;
	upd(i<<1, l, m, L, R, v); upd(i<<1|1, m+1, r, L, R, v);
}

int qry(int i, int l, int r, int x) {
	if(l == r) {
		return res[i];
	}
	if(res[i]) {
		if(res[i<<1]==0) res[i<<1]=res[i];
		if(res[i<<1|1]==0) res[i<<1|1]=res[i];
	}
	int m = (l+r)>>1;
	if(x <= m) return qry(i<<1, l, m, x); 
	return qry(i<<1|1, m+1, r, x);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;

	while(m--) {
		int l, r, v; cin >> l >> r >> v;
		upd(1, 1, n, l, v-1, v); upd(1, 1, n, v+1, r, v);
	}

	for(int i=1; i<=n; ++i) cout << qry(1, 1, n, i) << ' '; 
	return 0;
}