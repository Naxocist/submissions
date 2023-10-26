#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX

using ll = long long;
using pi = pair<ll, ll>;

const int N = 2e5 + 9;
vector<pi> adj[N], flip[N], group[N];
ll dA[N], dB[N], dG[N];

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

    int n, m, A, B; cin >> n >> m >> A >> B;

    for(int i=0; i<m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        flip[v].emplace_back(u, w);
    }

    dijk(A, dA, adj);
    dijk(B, dB, flip);

    for(int u=1; u<=n; ++u) {
        if(dA[u] + dB[u] ==  dA[B]) {
            cout << u << ' ';
            continue ;
        }

        for(auto e : adj[u]) {
            int v = e.first, vw = e.second;
            if(dA[v] + dB[v] == dA[B]) group[n+1].emplace_back(u, vw);
            else group[v].emplace_back(u, vw);
        }
    }

   
    dijk(n+1, dG, group);
    cout << '\n';
    int Q; cin >> Q;
    while(Q--) {
        int P; cin >> P;
        if(dA[P] + dB[P] == dA[B]) cout << 0 << '\n';
        else if(dG[P] == INF) cout << -1 << '\n';
        else cout << dG[P] << '\n';
    }
    return 0;
}
