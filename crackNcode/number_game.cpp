#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 503;
ll ar[N], dp[N][N];

int main() {
	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; ++i) {
		scanf("%lld", &ar[i]);
	}

	for(int s=3; s<=n; ++s) {
		for(int l=1; l<=n; ++l) {
			int r = l + s - 1;
			if(r > n) break ;

			dp[l][r] = INT_MIN;

			for(int k=l+1; k<r; ++k) {
				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + ar[l] + ar[r]);
			}
		}
	}

	printf("%lld", dp[1][n]);
	
	return 0;
}