#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
using pi = pair<int, int>;
vector<int> adj[N];
bool vis[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i=0; i<n; ++i) {
        adj[i].emplace_back(i+1); adj[i+1].emplace_back(i);
    }

    for(int i=0; i<m; ++i) {
        int l, r; cin >> l >> r;
        l--;
        adj[l].emplace_back(r); adj[r].emplace_back(l);
    }

    queue<pi> q;
    q.emplace(0, 0);
    vis[0] = 1;
    while(q.size()) {
        int d, u; tie(d, u) = q.front(); q.pop();
        if(u == n) {
            cout << d;
            return 0;
        }
        for(int v : adj[u]) {
            if(vis[v]) continue ;
            vis[v] = 1;
            q.emplace(d+1, v);
        }
    }
 
    return 0;
}