#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
using ll = long long;
ll fw[N], ar[N];

void upd(ll i, ll x) {
	for(;i<=N;i+=i&-i) fw[i] += x;
}

ll sum(ll i) {
	ll s = 0;
	for(;i;i-=i&-i) s += fw[i];
	return s;
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int n, q; cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> ar[i];
		upd(i, ar[i] - ar[i-1]);
	}

	while(q--) {
		int c, l, r, t; cin >> c;
		if(c == 1) cin >> l >> r >> t, upd(l, t), upd(r+1, -t);
		else cin >> t, cout << sum(t) << '\n';
	}
}

/*
1 4 3 2 5 [1 5 8 10 15]
[1 10 13 15 15]
1 9 8 7 5 
*/