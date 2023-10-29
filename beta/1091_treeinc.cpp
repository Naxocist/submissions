#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 3;

vector<int> adj[N];
int dp[N], res;

int dfs(int u) {
    if(dp[u]) return dp[u] ;
    if(adj[u].size() == 0) return 1;
    // printf("U : %d\n", u);
    int mx = 0;
    for(int v : adj[u]) {
        if(v < u) continue ;
        mx = max(mx, dfs(v));
    }

    dp[u] = mx + 1;
    res = max(res, dp[u]);
    return dp[u];
}

int main() {

    int n; scanf("%d", &n);

    for(int i=1; i<n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        if(u > v) swap(u, v);
        adj[u].emplace_back(v);
    }

    for(int i=1; i<=n; ++i) dfs(i);
    printf("%d", res);
    return 0;
}