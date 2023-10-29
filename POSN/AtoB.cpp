#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX

using ll = long long;
using pi = pair<ll, ll>;

const int N = 2e5 + 9;
vector<pi> adj[N], flip[N], group[N];
ll ds[N], dt[N], dg[N];

void dijk(int s, ll dist[], vector<pi> G[]) {
    for(int i=0; i<N; ++i) dist[i] = INF;
    priority_queue<pi> pq;

    dist[s] = 0;
    pq.emplace(0, s); 

    while(pq.size()) {
        ll d, u; tie(d, u) = pq.top(); pq.pop();

        for(auto e : G[u]) {
            int v = e.first, vw = e.second;
            if(dist[u] + vw < dist[v]) {
                dist[v] = dist[u] + vw;
                pq.emplace(-dist[v], v);
            }
        }
    }

    return ;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, s, t; cin >> n >> m >> s >> t;

    for(int i=0; i<m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        flip[v].emplace_back(u, w);
    }

    dijk(s, ds, adj);
    dijk(t, dt, flip);

    for(int u=1; u<=n; ++u) {
        if(ds[u] + dt[u] ==  ds[t]) continue ;

        for(auto e : adj[u]) {
            int v = e.first, vw = e.second;
            if(ds[v] + dt[v] == ds[t]) group[n+1].emplace_back(u, vw);
            else group[v].emplace_back(u, vw);
        }
    }

    dijk(n+1, dg, group);

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        if(ds[x] + dt[x] == ds[t]) cout << 0 << '\n';
        else if(dg[x] == INF) cout << "-1\n";
        else cout << dg[x] << '\n';
    }
    return 0;
}