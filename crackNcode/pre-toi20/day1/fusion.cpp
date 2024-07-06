#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " is: " << x << '\n'
#define div() cout << "############\n"
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back

using ll = long long int;
const int mod = 1e9 + 7;
const int INF = 2e9;
const int N = 1e5 + 3;
ll res = 0;
ll ar[N], qs[N];

void solve() {
    int n, q; cin >> n >> q;

    for(int i=1; i<=n; ++i) {
        cin >> ar[i];
        qs[i] = qs[i-1] + ar[i];
    }

    ll sum = qs[n];

    for(int i=1; i<=n; ++i) {
        res += ar[i] * (qs[n] - qs[i]);
    }

    if(q == 0) {
        cout << res << '\n';
        return ;
    }

    ll S = sum/2;
    bitset<2000009> dp;
    dp[0] = 1;
   
    for(int i=1; i<=n; ++i) {
        dp = dp | (dp<<ar[i]);
    }
    
    ll out = 0;
    for(int i=S; i>=0; --i) {
        if(dp[i]) {
            out = i; 
            break ;
        }
    }

    cout << res - out*(sum - out) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int TC = 1; 
    // cin >> TC;
    while(TC--) solve();
    return 0;
}
