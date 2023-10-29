#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using pi = pair<int, ll>;
using T = tuple<ll, int, int>;
const int N = 1e4 + 3;
vector<pi> adj[N];
bool vis[N][10];
ll dist[N][10];

int main() {

    int n, m, t; scanf("%d%d%d", &n, &m, &t);

    int s, e; scanf("%d%d", &s, &e);

    for(int i=0; i<m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        
        adj[u].emplace_back(v, (ll)w);
    }

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=t; ++j) dist[i][j] = 1e15;
    }
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.emplace(0, s, 1);
    dist[s][1] = 0;

    while(pq.size()) {
        ll d; int u, x; tie(d, u, x) = pq.top(); pq.pop();
        if(u == e && x == t) {
            printf("%lld", d);
            return 0;
        }
        int y = (x%t) + 1;
        for(auto k : adj[u]) {
            int v = k.first; ll vw = k.second;
            if(dist[u][x] + vw < dist[v][y]) {
                dist[v][y] = dist[u][x] + vw;
                pq.emplace(dist[v][y], v, y);
            }
        }
    }
    printf("-1");
    return 0;
}