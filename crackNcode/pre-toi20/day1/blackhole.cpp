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
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int mod = 1e9 + 7;
const int INF = 2e9;
const int N = 2e6 + 3;
int p[N], sz[N], dp[1003][703], dp2[1003][703];

int n, m, k;

int par(int u) {
    return (p[u] == u ? u : p[u] = par(p[u]));
}

void un(int u, int v) {
    u = par(u), v = par(v);
    if(u == v) return ;
    if(sz[u] > sz[v]) swap(u, v);

    p[u] = v;
    sz[v] += sz[u];
}


void solve() {
    cin >> n >> m >> k;

    for(int i=1; i<=n; ++i) {
        for(int j=0; j<=k; ++j) dp[i][j] = dp2[i][j] = -2e9;
    }

    for(int q=0; q<m; ++q){
        for(int i=1; i<=n; ++i) p[i] = i, sz[i] = 1;
        int e; cin >> e;
        while(e--) {
            int u, v; cin >> u >> v;
            un(u, v);
        }
        
        if(!q) {
            for(int i=1; i<=n; ++i) {
                if(par(i) == par(1)) 
                    dp[i][0] = sz[par(i)];
            }
            continue ;
        }

        for(int i=1; i<=n; ++i) {
            int p = par(i);
            for(int j=1; j<=k; ++j) {
                dp2[p][j] = max(dp2[p][j], dp[i][j-1] + sz[p]);
            }
        }

        for(int i=1; i<=n; ++i) {
            int p = par(i);
            for(int j=1; j<=k; ++j) {
                dp[i][j] = max(dp[i][j], dp2[p][j]);
            }
        }
    }

    int res = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<=k; ++j) res = max(res, dp[i][j]);
    }
    cout << res << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int TC = 1; 
    // cin >> TC;
    while(TC--) solve();
    return 0;
}


/*
7 4 2
5
1 2
2 3
3 4
4 5
6 7
4
1 2 
2 3
3 4
6 7
2
5 6
6 7
2
5 6
6 7
*/
