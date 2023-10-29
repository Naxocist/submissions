#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int ar[N][N];

int main() {

    int n, m, k; scanf("%d%d%d", &n, &m, &k);

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            scanf("%d", &ar[i][j]);
        }
    }

    int mx = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            int s = ar[i][j];
            for(int h=1; h<=k && j+h <= m; ++h) {
                s += ar[i][j+h] * (h&1 ? -1 : 1);
            }
            for(int h=1; h<=k && j-h >= 1; ++h) {
                s += ar[i][j-h] * (h&1 ? -1 : 1);
            }
            for(int h=1; h<=k && i-h >= 1; ++h) {
                s += ar[i-h][j] * (h&1 ? -1 : 1);
            }
            for(int h=1; h<=k && i+h <= n; ++h) {
                s += ar[i+h][j] * (h&1 ? -1 : 1);
            }

            mx = max(mx, s);
        }
    }

    printf("%d", mx);
    return 0;
}