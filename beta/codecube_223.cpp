#include <bits/stdc++.h>
using namespace std;
const int N = 7003;
int dp[2][N], dff[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m ;
	for(int i=1; i<=n; ++i) {
		string s; cin >> s;
		for(int j=1; j<=m; ++j) {
			int x =  s[j-1] - '0';
			if(x == 1) {
				dp[i&1][j] = min({dp[i&1^1][j], dp[i&1^1][j-1], dp[i&1][j-1]}) + 1;
				dff[1] ++, dff[dp[i&1][j] + 1] --;
			}else dp[i&1][j] = 0;
		}
	}

	for(int i=1; i<=min(n, m); ++i) dff[i] += dff[i-1], cout << dff[i] << '\n';
	return 0;
}