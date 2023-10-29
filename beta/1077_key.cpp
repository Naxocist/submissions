#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
const int N = 1005;
int qs[N][N];

int main() {

    int n, q; scanf("%d%d", &n, &q);

    for(int i=0; i<n; ++i) {
        int x, y; scanf("%d%d", &x, &y); x++, y++; // row col
        qs[x][y] ++;
    }

    for(int i=1; i<=1001; ++i) {
        for(int j=1; j<=1001; ++j) {
            qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
        }
    }
    while(q--) {
        int a, b, k; scanf("%d%d%d", &a, &b, &k);
        a++, b++; 
        int t1 = max(1, a-k), t2 = min(1001, a+k), t3 = max(1, b-k), t4 = min(1001, b+k);
        printf("%d\n", qs[t2][t4] - qs[t1-1][t4] - qs[t2][t3-1] + qs[t1-1][t3-1]);
    }

    return 0;
}

/*
5 1
1 2
1 4
4 1
4 2
4 3
2 2 1
*/