#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k; scanf("%d%d", &n, &k);

    vector<int> dp(n+1, 1e9), v(n+1);

    for(int i=1; i<=n; ++i) scanf("%d", &v[i]);

    dp[1] = 0;
    dp[2] = abs(v[2] - v[1]);
    for(int i=3; i<=n; ++i) {
        for(int j=1; j<=k; ++j) {
            if(i-j >= 1) dp[i] = min(abs(v[i] - v[i-j]) + dp[i-j], dp[i]);
        }
    }

    
    printf("%d", dp[n]);
    return 0;
}