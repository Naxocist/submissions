#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

const int N = 1e5 + 3;
vector<pi> adj[N];
int path[N], dist[N];

int main() {

    ios_base::sync_with_stdio(false); cout.tie(nullptr);

    int n, m, s, t; scanf("%d%d%d%d", &n, &m, &s, &t);

    for(int i=0; i<m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }

    for(int i=0; i<n; ++i) path[i] = -1, dist[i] = INT_MAX;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.emplace(0, s);
    dist[s] = 0;

    while(pq.size()) {
        int u, d; tie(d, u) = pq.top(); pq.pop();

        for(auto x : adj[u]) {
            int v = x.first, vw = x.second;
            if(dist[u] + vw < dist[v]) {
                dist[v] = dist[u] + vw;
                path[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << dist[t] << '\n';
    // for(int i=0; i<n; ++i) cout << path[i] << ' ';
    vector<int> res;
    int c = t;
    while(c != -1) res.push_back(c), c = path[c];

    cout << res.size() << '\n';
    for(int i=res.size()-1; i>=0; --i) cout << res[i] << ' ';
    
    return 0;
}