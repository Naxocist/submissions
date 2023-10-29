#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const ll mod = 1e9 + 7;
 
ll binpow(ll a, ll b, ll mod) {
	a%=mod;
	ll res = 1;
	for(;b;a=(a*a)%mod, b>>=1) if(b&1) res=(res*a)%mod;
	return res;
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q; cin >> q;
	while(q--) {
		ll x, y, z; cin >> x >> y >> z;
		cout << binpow(x, binpow(y, z, mod-1), mod) << '\n';
	}
	return 0;
}
