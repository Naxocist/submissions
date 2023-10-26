#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 1003;
vector<int> adj[N];
int sz[N], st[N], ed[N], ver[N], cnt[N], col[N];
int t = 0;
vector<int> res;

void dfs(int u) {
    sz[u] = 1;
    ver[++t] = u;
    st[u] = t;
    for(auto v : adj[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
    ed[u] = ++t;
    // cout << u << ' ' << sz[u] << endl;
}

void color(int u, int p, bool keep) {
    int mx = 0, bigCh = -1;
    for(auto v : adj[u]) {
        if(sz[v] > mx and v != p) mx = sz[v], bigCh = v;
    }

    for(auto v : adj[u]) {
        if(v != bigCh and v != p) color(v, u, 0);
    }

    if(bigCh != -1) color(bigCh, u, 1);

    show(u)
    for(auto v : adj[u]) {
        if(v != p and v != bigCh) {
            for(int i=st[v]; i<ed[v]; ++i) {
                cout << ver[i] << ' ';
                cnt[ col[ ver[i] ] ] ++;
            }
        }
    }
    cout << endl;
    cnt[ col[u] ] ++;
    if(!keep){
        for(int i=st[u]; i<ed[u]; ++i) 
            cnt[ col[ ver[i] ] ] --;
    }
    return ;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    res.resize(n+1);
    for(int i=1; i<=n; ++i) cin >> col[i];
    for(int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
    }

    dfs(1);

    div()
    for(int i=1; i<=t; ++i) cout << st[i] << ' ' << ed[i] << endl;
        cout<<endl;
    color(1, 0, 1);
    return 0;
}
