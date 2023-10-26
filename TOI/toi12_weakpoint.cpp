#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 3;
vector<int> adj[N];
bitset<N> vis;
int node = 1e9, num = 0, n, x;

int dfs(int u) {

    int s = 0;
    bool no = 0;
    for(int v : adj[u]) {
        if(v == x) no = 1;
        if(vis[v] || v == x) continue ;
        vis[v] = 1;

        int t = dfs(v);
        if(!t) no = 1;

        s += t;
    }
    
    if(s > num) node = u, num = s;  
    else if(s == num) node = min(u, node);

    if(no) return 0;
    return s + 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> x;

    while(n--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis[x] = 1;
    dfs(x);

    cout << node << '\n' << num;
    return 0;
}