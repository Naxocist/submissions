#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 3;
multiset<int> adj[N];
int main() {
    int n, m; cin >> n >> m;
    while(m--) {
        int u ,v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for(int i=1; i<=n; ++i) {
        cout << adj[i].size() << " ";
        for(int v : adj[i]) {
            cout << v << ' ';
        }
        cout << '\n';
    }

    return 0;
}