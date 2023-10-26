#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
using ll = long long;
ll fw[2*N], v[N];
int n, q, idx=1, st[N], ed[N];
vector<int> adj[N];
 
void upd(int i, ll x) {
    for(;i<2*N;i+=i&-i) fw[i] += x;
}
 
ll qry(int i) {
    ll s = 0;
    for(;i>0;i-=i&-i) s += fw[i];
    return s;
}
 
void dfs(int u = 1, int p = 0) {
    upd(st[u] = idx, v[u]);
    for(int v : adj[u]) if(v != p) dfs(v, u);
    ed[u] = ++idx;
    upd(ed[u] + 1, -v[u]);
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> v[i];
    for(int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v), adj[v].emplace_back(u);
    }
    dfs();
 
    while(q--) {
        int k, s; cin >> k >> s;
        if(k == 2) {
            cout << qry(st[s]) << '\n';
        }else {
            upd(st[s], -v[s]), upd(ed[s] + 1, v[s]);
            cin >> v[s];
            upd(st[s], v[s]), upd(ed[s] + 1, -v[s]);
        }
    }
    return 0;
}
