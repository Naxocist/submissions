#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
using ll = long long int;
using T = tuple<ll, int, int, int>;
int dsu[N], G;

int par(int u) {
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
    u = par(u), v = par(v);

    if(u == v) return ;
    G--;
    dsu[u] = v;
}

int main() {

    int n, m; scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) dsu[i] = i;
    G = n;
    vector<T> edge(m+1);
    for(int i=0; i<m; ++i) {
        int u, v; ll w; scanf("%d%d%lld", &u, &v, &w);
        edge[i] = T(w, u, v, i+1);
    }

    sort(edge.rbegin(), edge.rend());

    ll res = 0, mx = 0;
    int add = 0;
    vector<int> p;
    for(auto e : edge) {
        int u, v, x; ll w; tie(w, u, v, x) = e;
        
        if(par(u) == par(v)) {
            if(w > mx) mx = w, add = x;
            continue ;
        }
        un(u, v);
        p.push_back(x);
        res += w;
    }

    res += mx; p.push_back(add);
    if(G > 1 || m < n) {
        printf("-1");
        return 0;
    }

    printf("%lld\n", res);

    int k; scanf("%d", &k);
    if(k == 2) {
        for(int r : p) printf("%d ", r);
    }
    return 0;
}