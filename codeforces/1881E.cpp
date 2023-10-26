#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

void solve() {
    int n; cin >> n;
    vector<int> v(n); 
    for(auto &x : v) cin >> x;
    vector<int> dp(n+1, 0);
    reverse(all(v));
    for(int i=1; i<=n; ++i) {
        dp[i] = dp[i-1];
        if(i - v[i-1] - 1 >= 0) dp[i] = max(dp[i], 1 + v[i-1] + dp[i-v[i-1]-1]);
    }

    cout << n - dp[n] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();    
    return 0;
}
