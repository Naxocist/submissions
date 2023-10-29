#include <bits/stdc++.h>
using namespace std;


int f(int i, int j, int h, int k, vector<vector<int>> &v) {
    return v[h][k] - v[i-1][k] - v[h][j-1] + v[i-1][j-1];
}


int main() {

    int q = 2;
    while(q--) {
        int n, m, k; scanf("%d%d%d", &n, &m, &k);
        vector<vector<int>> v(n+3, vector<int>(m+3, 0));
        
        while(k--) {
            int x, y; scanf("%d%d", &x, &y); x++; y++;
            v[x][y] = 1;
        }

        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
            }
        }

        int s = min(n, m);
        while(s >= 1) {
            int t = s - 1;
            for(int i=1; i+t<=n; ++i) {
                for(int j=1; j+t<=m; ++j) {
                    if(f(i, j, i+t, j+t, v) - f(i+1, j+1, i+t-1, j+t-1, v) > 0) continue ;

                    printf("%d\n", s);
                    goto z;
                }
            }
            s--;
        }
        z:;
    }
    return 0;
}