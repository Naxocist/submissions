#include <bits/stdc++.h>
using namespace std;
const int N = 303, mod = 1e9 + 7;
using ll = long long;
ll n, k, d, qs[N], dp[N][N][13];

ll f(int l, int r, int k) {
	if(k == 1) return 1;
	if(dp[l][r][k] != -1) return dp[l][r][k];

	ll s = 0;
	for(int m=l; m<r; ++m) {
		ll left = qs[m] - qs[l-1], right = qs[r] - qs[m];
		if(abs(left - right) > d) continue ;
		s += f(l, m, k-1) * f(m+1, r, k-1);
		s %= mod;
	}

	return dp[l][r][k] = s;
}

int main() {
	cin >> n >> k >> d;
	for(int i=1; i<=n; ++i) {
		cin >> qs[i]; qs[i] += qs[i-1];
	}
	memset(dp, -1, sizeof dp);
	cout << f(1, n, k);
	return 0;
}