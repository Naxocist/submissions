#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 1e5 + 3;
const ll mod = 1e6 + 3;
vector<int> adj[N];
ll fac[N], inv[N], cnt[N], dp[N];

ll binpow(ll a, ll b) {
    ll res = 1;
    for(;b;a*=a, a%=mod, b/=2) {
        if(b&1) res*=a, res%=mod;
    }
    return res;
}

ll C(ll n, ll r) {
    return (((fac[n]*inv[n-r])%mod)*inv[r])%mod;
}

void dfs(int u, int p) {
    cnt[u] = 1;
    for(int v : adj[u]) {
        if(v == p) continue ;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}

void dfs2(int u, int p) {
    int c = cnt[u] - 1;
    dp[u] = 1;
    for(int v : adj[u]) {
        if(v == p) continue ;
        dfs2(v, u);
        dp[u] *= C(c, cnt[v]), dp[u]%=mod;
        dp[u] *= dp[v], dp[u]%=mod;
        c-=cnt[v];
    }
}


int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n; cin >> n;
    fac[0] = inv[0] = 1;
    for(int i=1; i<=n; ++i) {
        fac[i] = (fac[i-1] * i)%mod;
        inv[i] = binpow(fac[i], mod-2);
    }

    for(int i=1; i<n; ++i) {
        int u, v; cin >> v >> u;
        adj[u].emplace_back(v);
    }
    dfs(1, 0);
    dfs2(1, 0);
    cout << dp[1];
    return 0;
}