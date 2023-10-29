#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
vector<int> adj[N], flip[N];
bool vis[N];
 
void dfs(int u, int p, vector<int> g[]) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(vis[v]) continue ;
        dfs(v, u, g);
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); flip[v].push_back(u);
    }
    
    dfs(1, 0, adj);
    
    for(int i=1; i<=n; ++i) {
        if(!vis[i]) {
            cout << "NO\n" << 1 << ' ' << i; return 0;
        }
    }
    
    memset(vis, 0, sizeof vis);
    
    dfs(1, 0, flip);
    
    for(int i=1; i<=n; ++i) {
        if(!vis[i]) {
            cout << "NO\n" << i << ' ' << 1; return 0;
        }
    }
    cout << "YES";
 
    return 0;
}
