#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
vector<int> adj[N], lvl[N];
int cnt, vis[N];
bool cycle;

void dfs(int u) {
    cnt++;

    vis[u] = 1;
    for(int v : adj[u]) {
        if(vis[v] == 1) cycle = true;
        else if(vis[v] == 0) dfs(v);
    }
    vis[u] = 2;

}

int main() {

    int n, k, t; scanf("%d%d%d", &n, &k, &t);


    for(int u=1; u<=n; ++u) {
        int x, l; scanf("%d%d", &l, &x);
        lvl[l].emplace_back(u);
        
        while(x--) {
            int v; scanf("%d", &v);
            adj[u].emplace_back(v);
        }
    }

    int res = -1;
    for(int i=1; i<=k; ++i) {
        for(int u : lvl[i]) {
            if(vis[u]) continue ;
            dfs(u);
        }

        if(cycle) break ;

        if(cnt <= t) {
            res = i;
        }
    }
    printf("%d", res);
    
    return 0;
}