#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
vector<int> adj[N];
int dp[N];

int dfs(int u) {

    int mx = 0;
    for(int v : adj[u]) {
        mx = max(mx, (dp[v] ? dp[v] : dp[v] = dfs(v) + 1));
    }

    return mx;
}



int main() {
    int n, m; scanf("%d%d", &n, &m);

    for(int i=0; i<m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].emplace_back(v);
    }

    int res = 0;
    for(int i=1; i<=n; ++i) res = max(res, dfs(i));


    printf("%d", res);
    return 0;
}