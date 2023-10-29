#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3, mod = 1e9 + 7;;
int dp[N][N];
int main() {
    int n, m; scanf("%d%d", &n, &m);

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            char c; scanf(" %c", &c);
            if(c == '#') dp[i][j] = -1;
        }
    }
    dp[1][1] = 1;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(i == 1 && j == 1) continue ;
            if(dp[i][j] == -1) {
                dp[i][j] = 0; 
                continue ;
            } 

            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

    
    printf("%d", dp[n][m]);
    return 0;
}