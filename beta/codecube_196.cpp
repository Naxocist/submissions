#include <bits/stdc++.h>
using namespace std;

#define L LONG_LONG_MAX
using ll = long long int ;
using pi = pair<ll, ll>;
const int N = 1e5 + 3;
vector<pi> adj[N];
ll A[N], B[N], C[N];
bitset<N> vis, path;

inline void dijk(int s, ll *dist) {
    priority_queue<pi> pq;
    dist[s] = 0;
    pq.emplace(0, s);
    while(pq.size()) {
        int u = pq.top().second; pq.pop();
        vis[u] = 1;
        
        for(auto x : adj[u]) {
            ll v = x.first, vw = x.second;
            if(path[v]) continue ;

            if(dist[u] + vw < dist[v]) {
                dist[v] = dist[u] + vw;
                pq.emplace(-dist[v], v);
            }
        }
    }

    return ;
}

int main() {

    int n, m; scanf("%d%d", &n, &m);

    for(int i=0; i<m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int s, e, a, b; scanf("%d%d%d%d", &s, &e, &a, &b);
    for(int i=1; i<=n; ++i) A[i] = B[i] = C[i] = L;

    dijk(s, A); 
    dijk(e, B);

     for(int i=1; i<=n; ++i) {
        if(A[i] + B[i] == A[e]) path[i] = 1;
    }

    vis = 0;
    dijk(a, C);
    printf("%lld", (vis[b] ? C[b] : -1));
    return 0;
}