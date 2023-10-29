#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 10;
int ar[N][N], qsv[N][N], qsh[N][N], di1[N][N], di2[N][N];

int main() {

    int n, m, k; scanf("%d%d%d", &n, &m, &k);

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            scanf("%d", &ar[i][j]);
            qsv[i][j] = qsh[i][j] = di1[i][j] = di2[i][j] = ar[i][j];

            qsv[i][j] += qsv[i-1][j];
            qsh[i][j] += qsh[i][j-1];
            di1[i][j] += di1[i-1][j-1];
            di2[i][j] += di2[i-1][j+1];
        }
    }

    int s = 0, mx = INT_MIN;

    for(int i=1; i<=k; ++i) for(int j=1; j<=i; ++j) s += ar[i][j];
    
    for(int i=1; i<=n-k+1; ++i) {
        int t = s;
        for(int j=1; j<=m-k+1; ++j) {
            int r = i + k - 1, c = j + k - 1;
            mx = max(mx, t);
            
            t -= qsv[r][j] - qsv[i-1][j];
            t += di1[r][c+1] - di1[i-1][j];
        }
        
        s -= di1[i+k-1][k];
        s += qsh[i+k][k];
        
    }
    s = 0;
    for(int i=1; i<=k; ++i) for(int j=m; j>=m-i+1; --j) s += ar[i][j];

    for(int i=1; i<=n-k+1; ++i) {
        int t = s;
        for(int j=m; j>=k; --j) {
            int r = i + k - 1, c = j - k + 1;
            mx = max(mx, t);
            t -= qsv[r][j] - qsv[i-1][j];
            t += di2[r][c-1] - di2[i-1][j];
        }
        s -= di2[i+k-1][m-k+1];
        s += qsh[i+k][m] - qsh[i+k][m-k];
    }

    printf("%d", mx);
    return 0;
}
/*
4 5 3
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
*/