#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
const int N = 1e6 + 3;
vector<int> adj[N];

void solve() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);

    for(int i=1; i<=n; ++i) adj[i].clear();
    while(m--) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v); adj[v].push_back(u);
    }

    vector<int> vis(n+1, -1);
    bool ok = 1;
    while(k--) {
        int s, d; scanf("%d%d", &s, &d);
        queue<pi> q; 
        q.emplace(s, 0);
        while(q.size() && ok) {
            int u = q.front().first, t = q.front().second; q.pop();
            
            if(vis[u] == -1) {
                vis[u] = k; n--;
            }else if(vis[u] > k){
                ok = 0; break ;
            }
            if(t == d) continue ;

            for(int v : adj[u]) {
                if(vis[v] >= 0) continue ;
                q.emplace(v, t+1);
            }
        }
    }

    if(ok && !n) printf("Yes\n");
    else printf("No\n");
}

int main() {

    int t; scanf("%d", &t);
    while(t--) solve();
    return 0;
}

/*
1
6 6 3
1 2
2 3
3 4
4 5
4 6
1 4
1 3
5 0
6 0
*/