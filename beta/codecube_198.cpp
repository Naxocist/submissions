#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 3, mod = 1e9+7, b = 25;
ll pw[N], ar[N], chk[N], hsh, val, cnt;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	pw[0] = 1;
	for(int i=1; i<=m; ++i) pw[i] = (pw[i-1] * b) % mod;
	
	for(int i=1; i<=n; ++i) cin >> ar[i];

	vector<int> one;
	for(int i=m-1; i>=0; --i) {
		int x; cin >> x;
		if(x == 1) one.push_back(i);
		else val += (x * pw[i]) % mod, val %= mod;
	}
	for(int i=1; i<=m-1; ++i) hsh += (ar[i] * pw[m-i]) % mod, hsh %= mod;

	for(int i=m; i<=n; ++i) {
		hsh += ar[i] % mod, hsh %= mod;
		int t = hsh;
		for(int o : one) t -= (ar[i-o]*pw[o])%mod, t=(t+mod)%mod;
		if(t == val) cnt++;
		hsh -= (ar[i-m+1] * pw[m-1]) % mod, hsh=(hsh+mod)%mod;
		hsh *= b, hsh %= mod;
	}
	cout << cnt;
	return 0;
}