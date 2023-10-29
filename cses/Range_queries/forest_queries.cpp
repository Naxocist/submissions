#include <bits/stdc++.h>
using namespace std;
 
int ar[1005][1005];
 
int main() {
 
    int n, q; scanf("%d%d", &n, &q);
 
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            char c; scanf(" %c", &c);
            if(c == '*') ar[i][j] = 1;
            ar[i][j] += ar[i-1][j] + ar[i][j-1] - ar[i-1][j-1];
        }
    }
 
    while(q--) {
        int a, b, x, y; scanf("%d%d%d%d", &a, &b, &x, &y);
 
        printf("%d\n", ar[x][y] - ar[x][b-1] - ar[a-1][y] + ar[a-1][b-1]);
    }
    return 0;
}
