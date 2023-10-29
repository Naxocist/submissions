#include <bits/stdc++.h>
using namespace std;
const int N = 260;
bool dp[N][N][3];
void f() {
	memset(dp, 0, sizeof dp);
	int n; string s; cin >> n >> s;
	for(int i=0; i<n; ++i) dp[i][i][s[i] - '0'] = 1;
	for(int sz = 2; sz <= n; ++sz) {
		for(int l=0; l<n; ++l) {
			int r = l + sz - 1;
			if(r >= n) break ;
			for(int k=l; k<r; ++k) {
				dp[l][r][0] |= dp[l][k][0] and dp[k+1][r][2];

				dp[l][r][1] |= dp[l][k][0] and dp[k+1][r][1];
				dp[l][r][1] |= dp[l][k][1] and dp[k+1][r][1];
				dp[l][r][1] |= dp[l][k][1] and dp[k+1][r][2];
				dp[l][r][1] |= dp[l][k][2] and dp[k+1][r][0];
				dp[l][r][1] |= dp[l][k][2] and dp[k+1][r][2];

				dp[l][r][2] |= dp[l][k][0] and dp[k+1][r][0];
				dp[l][r][2] |= dp[l][k][1] and dp[k+1][r][0];
				dp[l][r][2] |= dp[l][k][2] and dp[k+1][r][1];
			}
		}
	}

	cout << (dp[0][n-1][0] ? "yes" : "no") << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t = 20;
	while(t--) f();
	return 0;
}