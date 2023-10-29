#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int dp[N][4];

int main() {

    int n; scanf("%d", &n);

    for(int i=1; i<=n; ++i) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        dp[i][1] = a + max(dp[i-1][2], dp[i-1][3]);
        dp[i][2] = b + max(dp[i-1][1], dp[i-1][3]);
        dp[i][3] = c + max(dp[i-1][1], dp[i-1][2]);
    }

    printf("%d", max({dp[n][1], dp[n][2], dp[n][3]}));
    return 0;
}