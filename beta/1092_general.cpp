#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int dsu[N], p[N];

int par(int u) {
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
    u = par(u); v = par(v);
    if(u == v) return ;

    dsu[u] = v;
}

int main() {

    int n, m; scanf("%d%d", &n, &m);

    for(int i=1; i<=n; ++i) {
        dsu[i] = i;
        scanf("%d", &p[i]);
    }

    while(m--) {
        int x, y; scanf("%d%d", &x, &y);

        int a = par(x), b = par(y);
        if(a == b) {
            printf("-1\n");
            continue ;
        }

        int w, l;
        if(p[a] > p[b]) w = a;
        else if(p[a] < p[b]) w = b;
        else if(a < b) w = a;
        else w = b;

        if(w == a) l = b;
        else l = a;

        un(l, w);
        p[w] += p[l]/2;

        printf("%d\n", w);
    }

    return 0;
}