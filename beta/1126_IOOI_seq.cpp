#include <bits/stdc++.h>
using namespace std;
const int N = 5003, mod = 2553;
int dp[N], qs[N];

int cube(int a) {
	return (((a*a)%mod)*a)%mod;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k; cin >> n >> k;
	for(int i=0; i<=n; ++i) qs[i] = 1;
	int res = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			dp[j] = qs[j-1];
			if(j-k-1 >= 0) dp[j]=(dp[j] - qs[j-k-1]+mod)%mod;
		}
		qs[0] = 0;
		for(int j=1; j<=n; ++j) qs[j]=(qs[j-1] + dp[j])%mod; 
		res += cube(dp[n]);
		res %= mod;
	}
	cout << res;
	return 0;
}