#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; scanf("%d", &n);

    vector<int> dp(n+1, 0), v(n+1);

    for(int i=1; i<=n; ++i) scanf("%d", &v[i]);

    dp[2] = abs(v[2] - v[1]);
    for(int i=3; i<=n; ++i) {
        dp[i] = min(abs(v[i] - v[i-1]) + dp[i-1], abs(v[i] - v[i-2]) + dp[i-2]);
    }
    
    printf("%d", dp[n]);
    return 0;
}