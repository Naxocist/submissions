#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 3, M = 1e9 + 7;
int dp[503][N];
 
int main() {
 
	int n; cin >> n;
 
	int s = n*(n+1)/2;
 
	if(s & 1) {
		cout << 0;
		return 0;
	}
 
 
	s /= 2;
	dp[0][0] = 1;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=s; ++j) {
			dp[i][j] = dp[i-1][j] + (j-i >= 0 ? dp[i-1][j-i] : 0);
			dp[i][j] %= M;
		}
	}
 
	cout << dp[n][s];
 
	return 0;
}