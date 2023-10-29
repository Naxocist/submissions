#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
using ll = long long int;
using pi = pair<int, ll>;

vector<pi> adj[N];
ll A[N], B[N], res[N];

void dijk(ll dist[], int s) {
    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, s);
    dist[s] = 0;
    
    while(pq.size()) {
        int u; ll w; tie(w, u) = pq.top(); pq.pop();
        
        for(pi e : adj[u]) {
            int v = e.first; ll vw = e.second;
            if(dist[u] + vw < dist[v]) {
                dist[v] = dist[u] + vw;
                pq.emplace(-dist[v], v);
            }
        }
    }
    
    return ;
}

int main() {
    
    int n, m, s, e; scanf("%d%d%d%d", &n, &m, &s, &e);
    
    for(int i=0; i<m; ++i) {
        int u, v; ll w; scanf("%d%d%lld", &u, &v, &w);
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    for(int i=1; i<=n; ++i) A[i] = B[i] = res[i] = 1e18;
    dijk(A, s); 
    dijk(B, e);

    priority_queue<pi> pq;
    for(int i=1; i<=n; ++i) {
        if(A[i] + B[i] == A[e]) {
            pq.emplace(0, i);
            res[i] = 0;
        }
    }

    while(pq.size()) {
        int u; ll w; tie(w, u) = pq.top(); pq.pop();

        if(w > res[u]) continue ;

        for(auto edge : adj[u]) {
            int v = edge.first; ll vw = edge.second;
            if(res[u] + vw < res[v]) {
                res[v] = res[u] + vw;
                pq.emplace(-res[v], v);
            }
        }
    }
    
    int q; scanf("%d", &q);
    while(q--) {
        int x; scanf("%d", &x);
        printf("%lld\n", res[x]);
    }
    
    return 0;
}
