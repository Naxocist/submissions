#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
using ll = long long;
const int N = 5e5 + 3, mod = 1e9 + 7;
ll ar[N], n, q;

int binpow(ll a, ll b) {
	ll res = 1;
	for(;b;a*=a, a%=mod,b>>=1) if(b&1)res*=a, res%=mod;
	return res;
}

ll get(ll l, ll r) {
	if(l > r) return 0;
	return (binpow(2, r+1) - binpow(2, l) + mod)%mod;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=n; ++i) cin >> ar[i];

	sort(ar+1, ar+1+n);
	// for(int i=1; i<=n; ++i) {
	// 	cout << ar[i] << ' ';
	// }
	// cout << '\n';
	while(q--) {
		ll a, b; cin >> a >> b;
		ll res = 0;
		for(int i=1; i<=n; ++i) {
			ll na, nb;
			if(ar[i] == 0) {
				if(a <= 0 and 0 <= b) res += get(0, n-i-1) + 1;
				res %= mod;
				continue ;
			}
			if(ar[i] < 0) {
				na = floor((double)a/ar[i]), nb = ceil((double)b/ar[i]);
			}else {
				na = ceil((double)a/ar[i]), nb = b/ar[i];
			}
			
			if(ar[i] < 0) swap(na, nb);
			// cout << i << ' ' << na << ' ' << nb << endl;

	
			int lw = lower_bound(ar+i, ar+1+n, na) - ar;
			int up = upper_bound(ar+i, ar+1+n, nb) - ar - 1;
			// cout << lw << ' ' << up << endl;
			if(lw > up) continue ;

			ll x = lw - i - 1, y = up - i - 1;
			if(x < 0) x++, res++;
			res += get(x, y);
			res %= mod;
		}

		cout << res << '\n';
	}
	return 0;
}