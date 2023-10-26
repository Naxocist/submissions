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
    ll res = mul[r] - mul[l-1];
    res -= (qs[r] - qs[l-1])*l;
    return res;
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
    
    for(int i=2; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            dp[i][j] = INF;
            for(int k=1; k<j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i-1][k] + cost(k+1, j));
            }
        }
    }

    cout << dp[m][n];
    return 0;
}
 