#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3, M = 1e9 + 7;
int ar[N], dp[N][103];
 
int main() {
 
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", &ar[i]);
 
	if(ar[1] == 0) {
		for(int i=1; i<=m; ++i) dp[1][i] = 1;
	}else {
		dp[1][ar[1]] = 1;
	}
 
	for(int i=2; i<=n; ++i) {
		if(ar[i] == 0) {
			for(int j=1; j<=m; ++j) {
				for(int k=j-1; k<=j+1; ++k) {
					dp[i][j] += dp[i-1][k];
					dp[i][j] %= M;
				}
			}
		}else {
			for(int k=ar[i]-1; k<=ar[i]+1; ++k) {
				dp[i][ar[i]] += dp[i-1][k];
				dp[i][ar[i]] %= M;
			}
		}
	}
 
	int res = 0;
	for(int i=0; i<=m; ++i) {
		res += dp[n][i];
		res %= M;
	}
 
	printf("%d", res);	
	return 0;
}
