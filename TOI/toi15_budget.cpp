#include <bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>;
using pi = pair<int, int>;
const int N = 3e3 + 3;
int dsu[N];
vector<pi> package;

int par(int u) {
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
    u = par(u), v = par(v);
    if(u == v) return ;
    dsu[u] = v;
    return ;
}


int main() {

    int n, m; scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) dsu[i] = i;

    vector<T> edge;
    for(int i=0; i<m; ++i) {
        int u, v, w, o; scanf("%d%d%d%d", &u, &v, &w, &o);
        if(o == 1) {
            un(u, v);
            continue ;
        }
        edge.emplace_back(w, u, v);
    }

    int p; scanf("%d", &p);
    for(int i=0; i<p; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        package.emplace_back(a, b);
    }

    sort(package.begin(), package.end());
    sort(edge.begin(), edge.end());

    int res = 0;
    for(auto e : edge) {
        int u, v, w; tie(w, u, v) = e;

        if(par(u) == par(v)) continue ;
        un(u, v);
        int t = lower_bound(package.begin(), package.end(), pi(w, 0)) - package.begin();
        int c = 1e9;
        for(int i=t; i<package.size(); ++i) {
            c = min(c, package[i].second);
        }
        res += c;
    }

    printf("%d", res);
    return 0;
}