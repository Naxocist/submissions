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
bool one[N];
vector<pair<int, int>> adj[N];
vector<int> dp(N, -2e9), dp2(N, -2e9);

void dfs(int u, int p) {
    if(one[u]) dp[u] = 0;
    for(auto [v, vw] : adj[u]) {
        if(v == p) continue ;
        dfs(v, u);
        if(!one[u]) dp[u] = max(dp[u], dp[v] + vw);
    }
    return ;
}

void dfs2(int u, int p, int mx) {

    multiset<int> ms;
    ms.insert(mx);

    if(one[u]) {
        dp2[u] = 0;
    }else {
        dp2[u] = mx;
        for(auto [v, vw] : adj[u]) {
            if(v == p) continue ;
            ms.insert(dp[v] + vw);
        }
    }

    for(auto [v, vw] : adj[u]) {
        if(v == p) continue ;
        if(one[u]) {
            dfs2(v, u, vw);
        }else {
            ms.erase(ms.find(dp[v] + vw));
            dfs2(v, u, *ms.rbegin() + vw);
            ms.insert(dp[v] + vw);
        }
    }

}

void solve() {
    int n, q; cin >> n >> q;

    for(int i=0; i<n; ++i) cin >> one[i];

    for(int i=0; i<n-1; ++i) {
        int u, v, w; 
        cin >> u >> v >> w;
        adj[u].pb(v, w), adj[v].pb(u, w);
    }

    dfs(0,0);
    dfs2(0,0,-2e9);

    while(q--) {
        int x; cin >> x;
        cout << max(dp[x], dp2[x]) << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int TC = 1; 
    // cin >> TC;
    while(TC--) solve();
    return 0;
}

