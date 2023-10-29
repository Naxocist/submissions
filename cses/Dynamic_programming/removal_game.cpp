#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e3 + 3;
using ll = long long;
ll dp[2][N][N], ar[N], qs[N];
 
int main() {
 
	int n; cin >> n;
	for(int i=1; i<=n; ++i) cin >> ar[i], qs[i] = qs[i-1] + ar[i];
 
 
	for(int l=n; l>=1; --l) {
		for(int r=1; r<=n; ++r) {
			if(l > r) continue ;
 
			if(l == r) {
				dp[0][l][r] = ar[l];
				dp[1][l][r] = ar[r];
				continue ;
			}
 
			dp[0][l][r] = max(qs[r] - qs[l] - dp[1][l+1][r] + ar[l], qs[r-1] - qs[l-1] - dp[1][l][r-1] + ar[r]);
			dp[1][l][r] = max(qs[r] - qs[l] - dp[0][l+1][r] + ar[l], qs[r-1] - qs[l-1] - dp[0][l][r-1] + ar[r]);
		}
	}
 
	cout << dp[0][1][n];
	return 0;
}