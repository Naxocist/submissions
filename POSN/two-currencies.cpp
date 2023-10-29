#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

using T = tuple<ll, ll, ll>;
using pi = pair<ll, ll>;
const int N = 5e2 + 3;
vector<T> adj[N];
pi change[N];
bool vis[N][N*10];
ll res[N];


int main() {

    int n, m, s; scanf("%d%d%d", &n, &m, &s);

    for(int i=0; i<m; ++i) {
        ll u, v, a, b; scanf("%lld%lld%lld%lld", &u, &v, &a, &b);
        adj[u].emplace_back(v, a, b);
        adj[v].emplace_back(u, a, b);
    }

    for(int i=1; i<=n; ++i) {
        ll c, d; scanf("%lld%lld", &c, &d);
        change[i] = {c, d};
        res[i] = LONG_LONG_MAX;
    }

    priority_queue<T, vector<T>, greater<T>> pq;

    pq.emplace(0, 1, min(2500LL, (ll)s));

    while(pq.size()) {
        ll d, u, silver; tie(d, u, silver) = pq.top(); pq.pop();
        ll c, t; tie(c, t) = change[u];
        res[u] = min(d, res[u]);
        // printf("Traverse : %lld %lld %lld\n", d, u, silver);
        if(vis[u][silver]) continue;
        vis[u][silver] = 1;

        
        for(auto x : adj[u]) {
            ll v, cost, vw; tie(v, cost, vw) = x;
            // printf("EDGE : %lld %lld %lld\n", v, cost, vw);
            if(silver >= cost) pq.emplace(d + vw, v, silver - cost);
            if(silver + c <= 2500) pq.emplace(d + t, u, silver + c);
        }
    }

    for(int i=2; i<=n; ++i) printf("%lld\n", res[i]);
    
    return 0;
}