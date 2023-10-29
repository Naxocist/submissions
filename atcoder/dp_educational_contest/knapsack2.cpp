#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {

    ll n, k; scanf("%lld%lld", &n, &k);
    vector<ll> w(n+1), v(n+1);
    ll s = 0;
    for(int i=1; i<=n; ++i) {
        scanf("%lld%lld", &w[i], &v[i]);
        s += v[i];
    }

    vector<ll> dp(s+1, 1e18L + 3);
    dp[0] = 0; 
    for(int i=1; i<=n; ++i) {
        for(int j=s; j>=v[i]; --j) {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    ll res = 0;
    for(int i=1; i<=s; ++i) {
        if(dp[i] <= k) res = max(res, (ll)i);
    }

    printf("%lld", res);
    return 0;
}