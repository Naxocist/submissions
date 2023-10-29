#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
const int N = 1e5 + 3;
ll dp[N], w[N], v[N];

int main() {

    int n, k; scanf("%d%d", &n, &k);

    for(int i=1; i<=n; ++i) {
        scanf("%lld%lld", &w[i], &v[i]);
    }

    for(int i=1; i<=n; ++i) {
        for(int j=k; j>=w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    printf("%lld", dp[k]);
    return 0; 
}