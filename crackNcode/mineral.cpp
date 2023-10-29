#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
using ll = long long;
ll a[N], b[N], x[N], t[N], n, k, inv;

void merge(int l, int r, int md) {
	int ld = l, rd = md+1, k = 0;

	while(ld <= md and rd <= r) {
		if(x[ld] < x[rd]) t[k++] = x[ld++];
		else inv += r - rd + 1, t[k++] = x[rd++]; 
	}

	while(ld <= md) t[k++] = x[ld++];
	while(rd <= r) t[k++] = x[rd++];

	for(int i=0; i<r-l+1; ++i) {
		x[l+i] = t[i];
	}
}

void f(int l, int r) {
	if(l >= r) return ;
	int md = l + (r-l)/2;
	f(l, md), f(md + 1, r);
	merge(l, r, md);
	return ;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n; ++i) cin >> a[i], a[i]*=1000;
	for(int i=1; i<=n; ++i) cin >> b[i], b[i];

	ll l = 1, r = 1e7, res = 0;
	while(l <= r) {
		ll md = l + (r-l)/2;
		for(int i=1; i<=n; ++i) x[i] = x[i-1] + a[i] - md*b[i];
		inv = 0;
		if(inv >= k) {
			l = md + 1, res = md;
		}else {
			r = md - 1;
		}
	}

	cout << res;
	return 0;
}