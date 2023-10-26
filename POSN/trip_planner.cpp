#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using tiii = tuple<int, int, int>;

const int N = 1005;
vector<pi> adj[N];
bool vis[N][105];
int pr[N], dsu[N];


int par(int u){
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}


void un(int u, int v){
    int x = par(u), y = par(v);
    if(x == y) return ;
    dsu[x] = y;
}


int main() {
    //freopen("input.in", "r", stdin);
    
    int n, m; scanf("%d%d", &n, &m);
    
    for(int i=0; i<n; ++i) scanf("%d", &pr[i]);

    while(m--){
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        un(u, v);
    }

    int q; scanf("%d", &q);
    while(q--){
        int lim, s, e; scanf("%d%d%d", &lim, &s, &e);

        if(par(s) != par(e)){
            printf("impossible\n");
            continue;
        }

        priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
        bool chk = 1;
        pq.emplace(0, 0, s);

        while(pq.size()){
            int cost, fuel, u;
            tie(cost, fuel, u) = pq.top(); pq.pop();

            if(u == e){
                printf("%d\n", cost);
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

        if(chk) printf("impossible\n");
        memset(vis, false, sizeof(vis));
    }

}
