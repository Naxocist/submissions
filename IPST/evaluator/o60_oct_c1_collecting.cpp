#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 5e4 + 3;
int x[N];
vector<pi> adj[N];
bool vis[N][33];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, l; cin >>n >> m >> l;
    int s, t; cin >> s>> t;

    for(int i=1; i<=n; ++i) cin >> x[i];

    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb(v, w);
    }



    priority_queue<T, vector<T>, greater<T>> pq;
    pq.emplace(0, s, 0);
    while(pq.size()) {
        int d, u, c; tie(d, u, c) = pq.top(), pq.pop();
        if(vis[u][c]) continue ;
        vis[u][c] = 1;
        if(u == t and c == l) {
            cout << d; return 0;
        }
        for(auto e : adj[u]) {
            int v, vw; tie(v, vw) = e;
            pq.emplace(d+vw, v, c + (x[v]==c+1));
        }
    }
    return 0;
}
