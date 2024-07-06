#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
using ll = long long int;
using pi = pair<int, ll>;

vector<pi> adj[N], adj2[N], flip[N];
ll A[N], B[N], res[N];

void dijk(ll dist[], int s, vector<pi> g[N]) {
    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, s);
    dist[s] = 0;
    
    while(pq.size()) {
        int u; ll w; tie(w, u) = pq.top(); pq.pop();
        
        for(pi e : g[u]) {
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
        adj[u].emplace_back(v, w); adj2[v].emplace_back(u, w);
    }

    for(int i=1; i<=n+1; ++i) A[i] = B[i] = res[i] = 1e18;
    dijk(A, s, adj); 
    dijk(B, e, adj2);
    
    for(int u=1; u<=n; ++u) {
        if(A[e] == A[u] + B[u]) continue ; 
        
        for(pi edge : adj[u]) {
            int v = edge.first; ll vw = edge.second;
            if(A[e] == A[v] + B[v]) flip[n+1].emplace_back(u, vw);
            else flip[v].emplace_back(u, vw);
        }
    }


    dijk(res, n+1, flip);
    int q; scanf("%d", &q);
    while(q--) {
        int x; scanf("%d", &x);

        if(A[e] == A[x] + B[x]) printf("0\n");
        else if(res[x] == 1e18) printf("-1\n");
        else printf("%lld\n", res[x]);
    }
    
    return 0;
}

/*
10 20 6 8
1 2 2
2 3 100
1 6 8
1 4 10
2 4 10
2 5 100
3 5 100
3 8 100
4 5 2
6 4 1
4 7 100
7 5 100
5 8 1
6 7 10
7 10 8
6 9 1
9 7 1
7 10 1
10 8 1
9 10 2
4
2
3
7
3
*/