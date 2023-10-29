#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int dp[N][N], cnt[N][N];

int main() {

    int n, m; scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i) cnt[1][i] = 1;
    
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            scanf("%d", &dp[i][j]);
            int k = (i & 1 ? dp[i-1][j-1] : dp[i-1][j+1]), c = (i & 1 ? cnt[i-1][j-1] : cnt[i-1][j+1]);
            if(dp[i-1][j] == k) cnt[i][j] += cnt[i-1][j] + c;
            else if(dp[i-1][j] > k) cnt[i][j] += cnt[i-1][j];
            else cnt[i][j] += c;

            dp[i][j] += max(dp[i-1][j], k);
        }
    }

    int a = -1e9, b = 0;
    for(int i=1; i<=m; ++i) {
        if(dp[n][i] > a)  a = dp[n][i], b = cnt[n][i];
        else if(dp[n][i] == a) b += cnt[n][i];
    }
    printf("%d %d", a, b);
    return 0;
}