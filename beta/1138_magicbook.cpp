#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
const int N = 1e5 + 3;
int seg[4*N], x[N], v[N], t[N], L, R, u;

void upd(int i, int l, int r, int mx) {
	if(l == r) {
		seg[i] = mx; 
		return ;
	}
	int md = l + (r-l)/2;
	u <= md ? upd(2*i, l, md, mx) : upd(2*i+1, md+1, r, mx);
	seg[i] = max(seg[2*i], seg[2*i+1]); 
	return ;
}

int qry(int i, int l, int r) {
	if(r < L || R < l) return 0;
	if(L <= l && r <= R) return seg[i];
	int md = l + (r-l)/2;
	return max(qry(2*i, l, md), qry(2*i+1, md+1, r));
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k, s; cin >> n >> k >> s;
	for(int i=1; i<=n; ++i) cin >> x[i] >> v[i], t[i] = x[i];
	sort(t+1, t+1+n);
	for(int i=n; i>=1; --i) {
		L = lower_bound(t+1, t+1+n, x[i]-k) - t;
		R = upper_bound(t+1, t+1+n, x[i]+k) - t - 1;
		u = lower_bound(t+1, t+1+n, x[i]) - t;
		upd(1, 1, n, qry(1, 1, n) + v[i]);
	}
	L = lower_bound(t+1, t+1+n, s-k) - t;
	R = upper_bound(t+1, t+1+n, s+k) - t - 1;
	cout << qry(1, 1, n);
	return 0;
}