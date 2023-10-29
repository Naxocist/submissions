#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {

    int n; scanf("%d", &n); 

    vector<ll> dp(n+1);

    for(int i=1; i<=n; ++i) scanf("%lld", &dp[i]);
    
    if(n <= 2) {
        printf("%lld", dp[n]);
        return 0;
    }

    dp[3] += dp[1] + dp[2];
    for(int i=4; i<=n; ++i) {
        dp[i] = min(dp[i] + dp[1] + dp[i-1], dp[i] + dp[1] + 2*dp[2] + dp[i-2]);
    }

    printf("%lld", dp[n]);

    return 0;
}