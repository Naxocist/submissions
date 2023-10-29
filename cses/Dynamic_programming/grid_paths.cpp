#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e3 + 3, M = 1e9 + 7;
int dp[N][N];
 
int main() {
    
    int n; scanf("%d", &n);
    memset(dp, 0, sizeof dp);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            char c; scanf(" %c", &c);
            if(c == '*') continue ;
            
            if(i == 1 && j == 1) {
                dp[i][j] = 1; continue ;
            }
            
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % M;
        }
    }
    
    printf("%d", dp[n][n]);
    return 0;
}
