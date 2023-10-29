#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 5, M = 1e4 + 5;
int sp[N], w[N], t[N], r[M];

int main() {

    int n, m; scanf("%d%d", &n, &m);

    for(int i=0; i<=N; ++i) t[i] = N;

    int mx = 0;
    for(int i=0; i<n; ++i) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        r[y]++; 
        int k = r[y];
        
        if(z > sp[k] || (z == sp[k] && t[k] > y)) {
            sp[k] = z;
            t[k] = y;
            w[k] = x;
        }
        mx = max(mx, k);
    }

    for(int i=1; i<=mx; ++i) {
        printf("%d\n", w[i]); 
    }

    return 0;
}
/*
4 3
3 1 100
4 1 10
2 2 101
1 2 11
*/