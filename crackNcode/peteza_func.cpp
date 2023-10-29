#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
using ll = long long;
const int M = 5e5 + 3, N = 1e3 + 5, K = 1002, R = 1000, mod = 1e9 + 7;
ll cnt[2*K], pref[2*K], res[K*K*2], two[M], n, q, x;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	two[0] = 1;
	for(int i=1; i<=n; ++i) cin >> x, cnt[x + K] ++, two[i] = two[i-1]*2, two[i]%=mod;

	for(int i=-R; i<=R; ++i) pref[i + K] += pref[i-1 + K] + cnt[i + K];

	for(int i=-R; i<=R; ++i) {
		for(int j=i+1; j<=R; ++j) {
			ll t = (two[cnt[i + K]]-1)*(two[cnt[j + K]]-1);
			t %= mod;
			t *= two[pref[j-1 + K] - pref[i + K]], t %= mod;
			res[i * j + R*R] += t, res[i * j + R*R]%=mod;
		}

		res[i*i + R*R] += two[cnt[i + K]] - 1, res[i*i + R*R]%=mod;
	}

	for(int i=-R*R; i<=R*R; ++i) res[i + R*R] += res[i-1 + R*R], res[i + R*R]%=mod;


	while(q--) {
		int a, b; cin >> a >> b;
		cout << (res[b + R*R] - res[a-1 + R*R] + mod)%mod << '\n';
	}
	return 0;
}