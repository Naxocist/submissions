#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

const int N = 1005;
vector<pi> adj[N];
bool vis[N][105];
int pr[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    
    for(int i=0; i<n; ++i) cin >> pr[i];

    while(m--){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int q; cin >> q;
    while(q--){
        int lim, s, e; cin >> lim >> s >> e;

        priority_queue<T, vector<T>, greater<T>> pq;
        bool chk = 1;
        pq.emplace(0, 0, s);

        while(pq.size()){
            int cost, fuel, u;
            tie(cost, fuel, u) = pq.top(); pq.pop();

            if(u == e){
                cout << cost << '\n';
                chk = 0;
                break;
            }
            
            if(vis[u][fuel]) continue;
            vis[u][fuel] = 1;
            if(fuel < lim) pq.emplace(cost + pr[u], fuel+1, u);

            for(pi x : adj[u]){
                if(fuel < x.second) continue;
                pq.emplace(cost, fuel-x.second, x.first);
            }

        }

        if(chk) cout << "impossible\n";
        memset(vis, false, sizeof(vis));
    }

}
