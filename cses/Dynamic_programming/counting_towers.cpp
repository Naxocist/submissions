#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+3, mod = 1e9 + 7;
using ll = long long;
ll dp[2][N];
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q; cin >> q;
	while(q--) {
		int n; cin >> n;
		memset(dp, 0, sizeof dp);
		dp[0][1] = dp[1][1] = 1;
		for(int i=2; i<=n; ++i) {
			dp[0][i] += 4*dp[0][i-1] + dp[1][i-1], dp[0][i]%=mod;
			dp[1][i] += dp[0][i-1] + 2*dp[1][i-1], dp[1][i]%=mod;
		}
 
		cout << (dp[0][n]+dp[1][n])%mod << '\n';
	}
	
 
	return 0;
}
