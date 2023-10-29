#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

const int N = 2e4 + 3;
int jakim[N], dist[N];
int par[N];
vector<pi> adj[N], res;
vector<int> shortest_tree[N];
bitset<N> vis;

void dfs(int u) {

    for(int v : shortest_tree[u]) {
        if(vis[v]) continue ;
        vis[v] = 1;
        res.push_back({u, v});
        dfs(v);
    }
    return ;
}

int main() 
{

    int n, m, k, p; scanf("%d%d%d%d", &n, &m, &k, &p);

    for(int i=0; i<k; ++i) scanf("%d", &jakim[i]);


    for(int i=0; i<m; ++i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }

    for(int i=0; i<n; ++i) dist[i] = INT_MAX, par[i] = -1;


    priority_queue<pi, vector<pi>, greater<pi>> pq;

    pq.emplace(0, p);
    dist[p] = 0;

    while(pq.size()) {
        int u, d; tie(d, u) = pq.top(); pq.pop();

        for(auto x : adj[u]) {
            int v = x.first, vw = x.second;
            if(dist[u] + vw < dist[v]) {
            dist[v] = dist[u] + vw;
            par[v] = u;
            pq.emplace(dist[v], v);
            }
        }
    }

    //   for(int i=0; i<n; ++i) cout << par[i] << ' ';

    for(int i=0; i<k; ++i) {
        int c = jakim[i];

        while(c != -1) {
            shortest_tree[par[c]].push_back(c);
            c = par[c];
        }
    }

    dfs(p);
    for(int i=0; i<k; ++i) cout << dist[jakim[i]] << ' ';
    cout << '\n' << res.size() << '\n';

    for(int i=res.size()-1; i>=0; --i) {
        pi x = res[i];
        int a, b; tie(a, b) = x;
        cout << min(a, b) << ' ' << max(a, b) << '\n';
    }

    return 0;
}

/*
6 8 3 4
0 2 3
0 1 7
1 3 1
1 5 8
0 4 20
3 5 4
2 4 63
4 5 3
1 2 3


*/