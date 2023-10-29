#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6 + 7;
int dp[50004];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, t, x; cin >> n >> t;
	dp[0] = 1;
	while(n--) {
		int x; cin >> x;
		for(int j=t; j>=x; --j) dp[j] += dp[j-x], dp[j] %= mod;
	}
	cout << dp[t];
}