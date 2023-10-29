#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

void f() {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> w(n+1), h(n+1);
    vector<ll> dp(n+1, 1e18);

    for(int i=1; i<=n; ++i) scanf("%d", &w[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &h[i]);
    
    dp[0] = 0;
    for(int i=1; i<=n; ++i) {
        int s = 0, mx = 0;
        for(int j=i; j<=n; ++j) {
            if(s + w[j] > k) break ;
            s += w[j];
            mx = max(mx, h[j]);
            dp[j] = min(dp[j], dp[i-1] + (ll)mx);
        }
    }

    printf("%lld\n", dp[n]);
}

int main() {
    int q; scanf("%d", &q);

    while(q--) f();
    return 0;
}