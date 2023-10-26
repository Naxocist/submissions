#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int dp[N][103], ar[N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &ar[i]);

    for(int i=1; i<=k; ++i) {
        if(ar[1] == i) dp[1][i] = 0;
        else dp[1][i] = 1;
    }

    for(int i=2; i<=n; ++i) {
        for(int j=1; j<=k; ++j) {
            if(j == 1) dp[i][j] = min(dp[i-1][2], dp[i-1][k]);
            else if(j == k) dp[i][j] = min(dp[i-1][1], dp[i-1][k-1]);
            else dp[i][j] = min(dp[i-1][j-1], dp[i-1][j+1]);

            dp[i][j] += (ar[i] == j ? 0 : 1);
        }
    }

    int mn = 1e9;
    for(int i=1; i<=k; ++i) {
        mn = min(mn, dp[n][i]);
    }
    printf("%d", mn);
    return 0;
}