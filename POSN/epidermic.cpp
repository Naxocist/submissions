#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define pb emplace_back
#define sz(x) (int) (x).size()
#define ln '\n'
using ll = long long;
using pi = pair<ll, ll>;
const ll INF = 2e18;
const int N = 2e5 + 3;
ll d1[N], d2[N], d3[N];
vector<pi> adj[N], group[N];
int n, m, s, e; 

void dijk(int s, ll d[], vector<pi> graph[]) {
    priority_queue<pi> pq;
    for(int i=0; i<=n; ++i) d[i] = INF;
    d[s] = 0;
    pq.emplace(0, s);
    while(pq.size()) {
        ll t; int u; tie(t, u) = pq.top(); pq.pop();

        for(auto e : graph[u]) {
            ll vw; int v; tie(v, vw) = e;
            if(d[u] + vw < d[v]) {
                d[v] = d[u] + vw;
                pq.emplace(-d[v], v);
            }
        }
    }
    return ;
}

bool is_group(int u) {
    return (d1[u] + d2[u] == d1[e]);
}

void runcase() {
    cin >> n >> m >> s >> e;
    for(int i=0; i<m; ++i) {
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].pb(v, w); adj[v].pb(u, w);
    }

    dijk(s, d1, adj);
    dijk(e, d2, adj);
    
    for(int i=1; i<=n; ++i) {
        int a = (is_group(i) ? 0 : i);
        for(auto e : adj[i]) {
            ll vw; int v; tie(v, vw) = e;
            int b = (is_group(v) ? 0 : v);
            if(a == b) continue ;
            group[a].pb(b, vw);
        }
    }

    dijk(0, d3, group);

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        if(d3[x] == INF) cout << 0 << ln;
        else cout << d3[x] << ln;
    }
    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}
