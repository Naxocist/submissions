#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
using pi = pair<int, int>;
vector<pi> adj[N];
int dp[N];

void dfs(int u, int p) {

    for(auto x : adj[u]) {
        int v = x.first, w = x.second;
        if(v == p) continue ;
        
        dp[v] = w ^ dp[u];
        dfs(v, u);
    }
}

int main() {

    int n, m; scanf("%d%d", &n, &m);

    for(int i=1; i<n; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dfs(1, -1);

    while(m--) {
        int u, v; scanf("%d%d", &u, &v);
        printf("%d\n", dp[u] ^ dp[v]);
    }
    return 0;
}