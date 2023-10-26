#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int N = 502;
ll g[N][N];

int main() {

    int n, m; scanf("%d%d", &n, &m);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(i == j) continue ;
            g[i][j] = 2e9;
        }
    }

    for(int i=0; i<m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        g[u][v] = (ll)w;
        g[v][u] = (ll)w;
    }

    for(int k=0; k<n; ++k) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    ll d; scanf("%lld", &d);
    int a = 0;   
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            if(g[i][j] <= d) {
                a ++;
            }
        }
    }
    if(a == 0) {
        printf("0/1");
        return 0;
    }
    n--;
    int b = (n * (n+1))/2;
    int t = __gcd(a, b);
    a /= t; b/= t;
    
    printf("%d/%d", a, b);
    return 0;
}
