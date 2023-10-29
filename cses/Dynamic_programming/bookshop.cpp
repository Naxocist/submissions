#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e3 + 3;
int p[N], s[N], dp[N][100*N];
 
int main() {
    int n, x; scanf("%d%d", &n, &x);
 
    for(int i=1; i<=n; ++i) scanf("%d", &p[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &s[i]);
 
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<=x; ++j) {
            if(j - p[i] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-p[i]] + s[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
 
    printf("%d", dp[n][x]);
    return 0;
}