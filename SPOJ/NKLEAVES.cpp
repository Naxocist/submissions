#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 1e5 + 3;
ll ar[N], dp[13][N], qs[N], mul[N];
int n, k, m;

ll cost(int l, int r) {
    if(l > r) return 0;
    ll res = mul[r] - mul[l-1];
    res -= (qs[r] - qs[l-1])*l;
    return res;
}

void f(int i, int l, int r, int optl, int optr) {
    if(l > r) return ;
    // cout << i << ' ' << l << ' ' << r << ' ' << optl << ' ' << optr << endl;
    int md = l + (r-l)/2;
    int opt_k = 0;
    dp[i][md] = INF;

    for(int k=optl; k<=min(optr, md); ++k) {
        // cout << dp[i^1][k] + cost(k+1, min(optr, md)) << endl;
        if(dp[i^1][k] + cost(k+1, md) < dp[i][md]) {
            dp[i][md] = dp[i^1][k] + cost(k+1, min(optr, md));
            opt_k = k;
        }
    }
    // div()
    f(i, l, md-1, optl, opt_k);
    f(i, md+1, r, opt_k, optr);
    return ;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        cin >> ar[i];
        qs[i] = qs[i-1] + ar[i];
        mul[i] = mul[i-1] + ar[i]*i;
        dp[1][i] = cost(1, i);
    }
    for(int i=2; i<=m; ++i) f(i%2, 1, n, 1, n);

        
    cout << dp[m%2][n];
    return 0;
}
