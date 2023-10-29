#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
using tiii = tuple<int, int, int>;
const int N = 1e5 + 3;
vector<pi> adj[N];
int dist[N][2];

int main() {

    int n, m; scanf("%d%d", &n, &m);

    int s, e; scanf("%d%d", &s, &e);

    int res = 0;
    for(int i=0; i<m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        res += w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for(int i=0; i<n; ++i) {
        dist[i][0] = dist[i][1] = INT_MAX;
    }

    priority_queue<tiii> pq;
    pq.emplace(0, s, 0);
    dist[s][0] = 0 ;
    while(pq.size()) {
        int d, u, x; tie(d, u, x) = pq.top(); pq.pop();

        for(auto e : adj[u]) {
            int v = e.first, vw = e.second;
            if(dist[u][x] + vw < dist[v][x]) {
                dist[v][x] = dist[u][x] + vw;
                pq.emplace(-dist[v][x], v, x);
            }

            if(!x && dist[u][x] < dist[v][1]) {
                dist[v][1] = dist[u][x];
                pq.emplace(-dist[v][x], v, 1);
            }
        }
    }

    printf("%d", res - dist[e][1]);
    return 0;
}

/*
6 7
0 5
0 1 1
0 2 1
2 4 3
4 3 2
2 1 3
4 5 7
5 3 1
*/