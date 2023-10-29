#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
using ll = long long;
const int N = 5e5 + 3, mod = 1e9 + 7;
int ar[N], n, q;

int binpow(ll a, ll b) {
	ll res = 1;
	for(;b;a*=a, a%=mod,b>>=1) if(b&1)res*=a, res%=mod;
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=n; ++i) cin >> ar[i];
	sort(ar+1, ar+1+n);
	while(q--) {
		int l, r; cin >> l >> r;
		int res = 0;
		for(int i=1; i<=n; ++i) {
			for(int j=i; j<=n; ++j) {
				int d = ar[i] * ar[j];
				if(l <= d and d <= r) {
					if(i == j) res ++;
					else res += binpow(2, j - i - 1), res %= mod;
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}