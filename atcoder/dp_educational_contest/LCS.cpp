#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 3;
int dp[N][N], path[N][N];

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    s = '&' + s, t = '&' + t;

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            dp[i][j] = dp[i-1][j];
            path[i][j] = 1;

            if(dp[i][j-1] > dp[i][j]) dp[i][j] = dp[i][j-1], path[i][j] = 2;

            if((s[i] == t[j]) + dp[i-1][j-1] > dp[i][j]) dp[i][j] = (s[i] == t[j]) + dp[i-1][j-1], path[i][j] = 3;

            // dp[i][j] =  max({dp[i-1][j], dp[i][j-1], (s[i] == t[j]) + dp[i-1][j-1]});

        }
    }
    string res;
    while(n && m) {
        if(path[n][m] == 1) n--;
        else if(path[n][m] == 2) m--;
        else res += s[n], n--, m--;
    }
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}