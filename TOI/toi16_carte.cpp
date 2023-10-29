#include <bits/stdc++.h>
using namespace std;

const int N = 403, INF = 1e9;;
int dp[N][N], ar[N];

int main() {

	int q, m; scanf("%d%d", &q, &m);

	int res = 0;
	while(q--) {
		int n; scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", &ar[i]);


		for(int s=1; s<=n; ++s) {
			for(int l=1; l <= n; ++l) {
				int r = l + s - 1;
				if(r > n) break ;

				if(l == r) {
					dp[l][r] = 1; continue ;
				}

				dp[l][r] = INF;
				
				for(int k=l; k<r; ++k) {
					dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
				}
				if(ar[l] == ar[r]) dp[l][r]--;
			}
		}
		res = max(res, dp[1][n]);
	}

	printf("%d", res);

	return 0;
}