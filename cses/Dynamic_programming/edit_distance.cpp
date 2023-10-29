#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e3 + 3;
int dp[N][N];
 
int main() {
 
	string s, z; cin >> s >> z;
	s = '.' + s;
	z = '.' + z;
	int n = s.size(), m = z.size();
 
	for(int i=1; i<=n; ++i) dp[i][0] = i;
	for(int i=1; i<=m; ++i) dp[0][i] = i;
 
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
 
			if(s[i] == z[j]) {
				dp[i][j] = dp[i-1][j-1];
				continue ;
			}
 
			dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
 
		}
	}
 
	cout << dp[n][m];
	return 0;
}
