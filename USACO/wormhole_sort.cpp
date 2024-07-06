#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define pb emplace_back
const int N = 1e5 + 3;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
int x[N], dsu[N];

int par(int u) {
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
    u = par(u), v = par(v);
    if(u == v) return;
    dsu[u] = v;
    return ;
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, w, u, v;
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> x[i];

    iota(dsu, dsu+N, 0);
    vector<T> t;
    int idx = 0;
    while(m--) {
        cin >> u >> v >> w;
        t.pb(w, u, v);
    }
    sort(allrev(t));
    
    int res = 2e9;
    for(int i=1; i<=n; ++i) {
        while(par(i) != par(x[i])) {
            tie(w, u, v) = t[idx++];
            res = min(res, w);
            un(u, v);
        }
    }

    cout << (res == 2e9 ? -1 : res);
    return 0;
}
