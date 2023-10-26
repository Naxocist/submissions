#include <bits/stdc++.h>
using namespace std;

#define INF 2e9

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

const int N = 1e4 + 3;
vector<pi> adj[N];
int dist[N], distr[N];

int main() {

	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;

    for(int i=0; i<n; ++i) dist[i] = INF, distr[i] = INF;

    int s, e, l; cin >> s >> e >> l;

    for(int i=0; i<m; ++i){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(pq.size()){
        pi t = pq.top(); pq.pop();
        int w = t.first, u = t.second;

        if(w > dist[u]) continue;

        for(pi x : adj[u]){
            int v = x.second, vw = x.first;
            if(dist[u] + vw < dist[v]){
                dist[v] = dist[u] + vw;
                pq.push({dist[v], v});
            }
        }
    }

    if(dist[e] <= l){
        cout << e << ' ' << dist[e] << ' ' << 0;
        return 0;
    }

    pq.push({0, e});
    distr[e] = 0;

    while(pq.size()){
        pi t = pq.top(); pq.pop();
        int w = t.first, u = t.second;

        if(w > distr[u]) continue;

        for(pi x : adj[u]){
            int v = x.second, vw = x.first;
            if(distr[u] + vw < distr[v]){
                distr[v] = distr[u] + vw;
                pq.push({distr[v], v});
            }
        }
    }

    int mn = 1e9, z = e;
    for(int i=0; i<n; ++i) {
        if(i == e || dist[i] > l) continue;
        if(distr[i] < mn) mn = distr[i], z = i;
    }
    cout << z << ' ' << dist[z] << ' ' << mn;
}
