#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
using ll = long long;
const int N = 5e5 + 3, mod = 1e9 + 7;
int ar[N], n, q, l, r;
vector<int> v;
int res = 0;

int binpow(ll a, ll b) {
	ll res = 1;
	for(;b;a*=a, a%=mod,b>>=1) if(b&1)res*=a, res%=mod;
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=n; ++i) cin >> ar[i];

	while(q--) {
		cin >> l >> r;
		int x = ar[1] * ar[1];
		if(l <= x && x <= r) cout << binpow(2, n)-1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}