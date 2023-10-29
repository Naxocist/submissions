#include <bits/stdc++.h>
using namespace std;

const int N = 2003, M = 3003;
int l[N], r[N];
int dp[N][M], dp2[N][M], dp3[N][M], dp4[N][M];
int n, m, s;

void f(int &a, int b) {
	a = max(a, b);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> s;

	for(int i=1; i<=n; ++i) cin >> l[i];
	for(int i=1; i<=n; ++i) cin >> r[i];

	for(int i=1; i<=n; ++i) {
		for(int j=0; j<=m; ++j) {
			dp[i][j] = dp[i-1][j];
			int t = j + min(r[i], 0);
			if(t >= 0) f(dp[i][j], dp[i-1][t] + l[i]);
		}
	}

	for(int i=1; i<=n; ++i) {
		for(int j=0; j<=m; ++j) {
			dp2[i][j] = dp2[i-1][j];
			int t = j + min(l[i], 0);
			if(t >= 0) f(dp2[i][j], dp2[i-1][t] + r[i]);
		}
	}

	for(int i=n; i>=1; --i) {
		for(int j=0; j<=m; ++j) {
			dp3[i][j] = dp3[i+1][j];
			int t = j + min(r[i], 0);
			if(t >= 0) f(dp3[i][j], dp3[i+1][t] + l[i]);
		}
	}

	for(int i=n; i>=1; --i) {
		for(int j=0; j<=m; ++j) {
			dp4[i][j] = dp4[i+1][j];
			int t = j + min(l[i], 0);
			if(t >= 0) f(dp4[i][j], dp4[i+1][t] + r[i]);
		}
	}

	int res = dp[n][m] + dp2[n][m];

	if(s) {
		for(int i=1; i<=n; ++i) {
			int mxl = 0, mxr = 0;
			for(int j=0; j<=m; ++j) {
				mxl = max(mxl, dp[i][j] + dp4[i+1][m-j]);
				mxr = max(mxr, dp2[i][j] + dp3[i+1][m-j]);
			}
			res = max(res, mxl + mxr);
		}
	}
	cout << res;
	return 0;
}
