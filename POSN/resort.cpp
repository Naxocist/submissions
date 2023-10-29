#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
const int N = 120;
int dp[N][5*N];
bool no[N];

void f(int &n, int m) {
	n = min(n, m);
	return ;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	int c = 5*n;
	while(m--) {
		int x; cin >> x;
		no[x] = 1;
	}
	// vector<int> v(m);
	// for(auto &x : v) cin >> x;
	for(int i=0; i<=n; ++i) {
		for(int j=0; j<=c; ++j) dp[i][j] = INF;
	}

	dp[0][0] = 0;
	for(int i=0; i<=n; ++i) {

		for(int j=0; j<=c; ++j) {
			if(dp[i][j] == INF) continue ;
			if(no[i]) {
				dp[i][j] = dp[i-1][j];
			}
			f(dp[i+1][j], dp[i][j] + 10000);
			f(dp[i+3][j+1], dp[i][j] + 25000);
			f(dp[i+5][j+2], dp[i][j] + 37000);

			if(j >= 3) {
				f(dp[i+1][j-3], dp[i][j]);
			}
		}
	}

	// for(int i=0; i<=n; ++i) {
	// 	for(int j=0; j<=c; ++j) {
	// 		if(dp[i][j] == INF) continue ;
	// 		cout << i << ' ' << j << " : ";
	// 		cout << dp[i][j] << '\n';
	// 	}
	// 	// cout << endl;
	// }
	int res = 1e9;
	for(int i=0; i<=c; ++i) res = min(res, dp[n][i]);
	cout << res;
	return 0;
}