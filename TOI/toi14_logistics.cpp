#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using tiiii = tuple<int, int, int, int>;

const int N = 105;
vector<pi> adj[N];
int vis[N][N][2];
int pr[N];


int main() {
    // freopen("input.in", "r", stdin);
    
    int n; scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &pr[i]);

    int s, e, lim; scanf("%d%d%d", &s, &e, &lim);

    int m; scanf("%d", &m);

    for(int i=0; i<m; ++i){
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<tiiii, vector<tiiii>, greater<tiiii>> pq;
    pq.emplace(0, 0, s, 1);

    while(pq.size()){
        int cost, fuel, u, t; 
        tie(cost, fuel, u, t) = pq.top(); pq.pop();
        
        if(u == e && fuel == lim){
            printf("%d", cost);
            return 0;
        }

        if(vis[u][fuel][t]) continue;
        vis[u][fuel][t] = 1;

        if(t) pq.emplace(cost, lim, u, 0); // fill free fuel
        

        if(fuel < lim) pq.emplace(cost + pr[u], fuel + 1, u, t); // fill fuel one unit
        
        for(pi x : adj[u]){
            if(fuel < x.second) continue;
            pq.emplace(cost, fuel-x.second, x.first, t);
        }
    }   

}
