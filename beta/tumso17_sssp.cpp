#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3, mod = 1e9 + 7;
using pi = pair<int, int>;

vector<pi> adj[N];
int path[N], dist[N];

int mul(int a, int b) {
    return (a * b) % mod;
}

int main() {

    int n, m; scanf("%d%d", &n, &m);

    int s, t; scanf("%d%d", &s, &t); s++, t++;

    for(int i=0; i<m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        u++, v++; w = log(w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for(int i=0; i<=n; ++i) dist[i] = 2e9;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[s] = 0;
    pq.emplace(1, s);

    while(pq.size()) {
        int d, u; tie(d, u) = pq.top(); pq.pop();
        // printf("%d %d\n", d, u);
        // if(d > dist[u]) continue ;

        for(auto x : adj[u]) {
            int v = x.first, vw = x.second;
            if(d + vw < dist[v]) {
                path[v] = u;
                dist[v] = d + vw;
                pq.emplace(dist[v], v);
            }
        }
    }

    // for(int i=1; i<=n; ++i) printf("%d ", path[i]);
    // printf("\n");

    stack<int> p;
    while(t) {
        p.push(t);
        t = path[t];
    }

    while(p.size()) printf("%d ", p.top() - 1), p.pop();
    return 0;
}

/*
4 4
0 3
0 1 2
1 3 11
0 2 3
2 3 5
*/