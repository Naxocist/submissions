#include <bits/stdc++.h>
using namespace std;

const int N = 21;
int ar[N][N], dp[1<<N];
int n;

void solve() {
	scanf("%d", &n);
	
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			scanf("%d", &ar[i][j]);
		}
	}

	for(int i=0; i<(1<<n); ++i) {
		dp[i] = 0;
		for(int j=1; j<=n; ++j) {
			if(i & (1 << (j-1))) {
				dp[i] = max(dp[i], dp[i^(1 << (j-1))] + ar[__builtin_popcount(i)][j]);
			}
		}
	}

	printf("%d\n", dp[(1<<n) - 1]);

}

int main() {
	int t; scanf("%d", &t);
	while(t--) solve();
	return 0;
}