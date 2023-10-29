#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
using pi = pair<int, int>;
vector<pi> adj[N];
int res = 0;

void dfs(int u, int p, int x) {
    res = max(x, res);

    for(pi e : adj[u]) {
        int v = e.first, vw = e.second;
        if(v == p) continue ;
        dfs(v, u, x + vw);
    }
    return ;
}


int main() {

    int n; scanf("%d", &n);

    for(int i=1; i<n; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }

    dfs(1, 0, 0);

    printf("%d", res);
    return 0;
}