#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pi = pair<int, int>;
using tiii = tuple<int, int, int>;
using ll = long long;

const int N = 2005;
vector<pi> adj[N], dist[N];
pi par[N];


int main() {
    freopen("input.in", "r", stdin);
    
    int n, m, s, e; scanf("%d%d%d%d", &n, &s, &e, &m);
    

    for(int i=0; i<m; ++i){
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].emplace_back(v, w);
    }


    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    pq.emplace(0, s, 0);

    while(pq.size()){
        int w, u, l;
        tie(w, u, l) = pq.top(); pq.pop();

        for(pi x : adj[u]){
            int v, vw;
            tie(v, vw) = x;
            bool chk = 1;
            for(pi e : dist[v]){
                if(e.first <= w + vw && e.second <= l + 1) {
                    chk = 0;
                    break;
                }
            }

            if(chk) {
                dist[v].emplace_back(w + vw, l + 1); // add possible path
                pq.emplace(w + vw, v, l + 1);
            }
        }
    }

    int q; scanf("%d", &q);
    while(q--){
        int h; scanf("%d", &h);

        int ans = 1e9;
        for(pi x : dist[e]) ans = min(ans, x.first + (x.second-1)*h);

        printf("%d ", ans);
        
    }
}
