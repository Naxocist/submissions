#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int no[N], dist[N], res, n;
bool vis[N];

void dfs(int u, int d) {
    dist[u] = d;
    // printf("%d %d\n", u, d);
    for(int i=1; i<=n; ++i) {
        if(i == no[u] || i == u) continue ;
        if(vis[i]) {
            res = max(res, d - dist[i]);
            continue ;
        }
        vis[i] = 1;
        dfs(i, d+1);
    }
}

void solve() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &no[i]), vis[i] = 0, dist[i] = 0;
    
    res = 0;
    vis[1] = 1;
    for(int i=1; i<=n; ++i) dfs(i, 0);

    printf("%d\n", res);
    
}

int main() {

    int q; scanf("%d", &q);
    while(q--) solve();
    return 0;
}

/*
2
4
2 3 1 1
5
2 3 1 5 4
*/