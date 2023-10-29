#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k; scanf("%d%d", &n, &k);

	int mod = 2009;

	// dp(n) = dp(n-1) + dp(n-2) + ... + dp(n-k);
	vector<int> dp(n+1, 0);
	dp[0] = 1;
	int prev = 1;
	for(int i=1; i<=n; ++i) {
		if(i-k-1 >= 0) prev -= dp[i-k-1];

		dp[i] += prev;
		dp[i] %= mod;

		prev += dp[i];

	}

	printf("%d", dp[n]);
	return 0;
}