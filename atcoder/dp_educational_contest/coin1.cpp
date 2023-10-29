#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; scanf("%d", &n);

    vector<double> dp(n+1);

    dp[0] = 1;
    for(int coin = 0; coin < n; ++coin) {
        double heads; scanf("%lf", &heads);
        for(int i = coin + 1; i >= 0; --i) {
            dp[i] = (i == 0 ? 0 : dp[i-1]*heads) + dp[i]*(1-heads);
        }
        
    }
    for(int coin = 0; coin <= n; ++coin) {
        printf("%lf ", dp[coin]);
    }
    printf("\n");

    double res = 0;
    for(int coin = n; coin > n/2; --coin) res += dp[coin];

    printf("%.10lf", res);
    return 0;
}