#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;

struct T {
    int t=400, b=-1, l=400, r=-1;
} ar[N];

int dp[4][N];

int main() {

    int n, m, q; scanf("%d%d%d", &n, &m, &q);

    int mx = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            int x; scanf("%d", &x);
            mx = max(mx, x);
            ar[x].t = min(ar[x].t, i); ar[x].b = max(ar[x].b, i);
            ar[x].l = min(ar[x].l, j); ar[x].r = max(ar[x].r, j);
        }
    }
    dp[0][mx] = ar[mx].t; dp[1][mx] = ar[mx].b;
    dp[2][mx] = ar[mx].l; dp[3][mx] = ar[mx].r;

    for(int i=0; i<2; ++i) {
        for(int j=mx-1; j>=0; --j) {
            if(i == 0) {
                dp[i][j] = min(dp[i][j+1], ar[j].t); // 0
                dp[i+2][j] = min(dp[i+2][j+1], ar[j].l); // 2
            }else {
                dp[i][j] = max(dp[i][j+1], ar[j].b); // 1
                dp[i+2][j] = max(dp[i+2][j+1], ar[j].r); // 3
            }
        }
    }

    while(q--) {
        int s, x; scanf("%d%d", &s, &x);

        if(s == 1) {
            if(ar[x].t == 400) {
                printf("0\n"); continue ;
            }
 
            int k = 2*(ar[x].b - ar[x].t + 1) + 2*(ar[x].r - ar[x].l + 1);
            printf("%d\n", k);
        }else {
            if(x > mx) {
                printf("0\n"); continue ;
            }
            int k = 2*(dp[1][x] - dp[0][x] + 1) + 2*(dp[3][x] - dp[2][x] + 1);
            printf("%d\n", k);
        }
    }
    return 0;
}