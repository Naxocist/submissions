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
const int N = 5e5 + 3;
vector<int> adj[N];
int r, res, t;
int tin[N], low[N];

void dfs(int u, int p) {
    tin[u] = low[u] = ++t;
    for(auto v : adj[u]) {
        if(v == p) continue ;
        if(tin[v]) {
            low[u] = min(low[u], tin[v]);
        }else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]) r ++;
        }
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    for(int i=1; i<=n; ++i) if(!tin[i]) r=0,dfs(i,-1),res+=r+1;
    cout << res;
    return 0;
}
