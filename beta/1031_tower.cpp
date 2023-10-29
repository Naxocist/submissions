#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
const int N = 1e4 + 3;
vector<int> adj[N];
int step[N]; bool vis[N];

int main() {

    int k, n, m; cin >> k >> n >> m;

    while(m--){
        int u, v; cin >> u >> v;

        adj[u].push_back(v); 
    }

    int res = 1;
    queue<pi> q;
    q.emplace(1, 0); vis[1] = 1;
    for(int i=1; i<=n; ++i) step[i] = 1e9;
    while(q.size()) {
        int u, t; tie(u, t) = q.front(); q.pop();

        step[u] = min(step[u], t);

        if(t + 1 > k) continue ;

        for(int v : adj[u]) {
            if(vis[v]) continue ;
            vis[v] = 1;
            q.emplace(v, t+1);
        }
    }

    for(int i=n; i>=1; --i) {
        if(step[i] <= k) {
            cout << i; return 0;
        }
    }
    return 0;
}