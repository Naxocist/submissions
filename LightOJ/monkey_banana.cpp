#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; scanf("%d", &t);
    for(int k=1; k<=t; ++k) {
        int n; scanf("%d", &n);
        vector<vector<int>> dp(3*n, vector<int>(3*n, 0));
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=i; ++j) {
                scanf("%d", &dp[i][j]);
                dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
            }
        }
        
        for(int i=n+1, r=n-1; i<2*n; ++i, --r) {
            for(int j=1; j<=r; ++j) {
                scanf("%d", &dp[i][j]);
                dp[i][j] += max(dp[i-1][j], dp[i-1][j+1]);
            }
        }

        
        cout << "Case " << k << ": " << dp[2*n-1][1] << '\n';
    }
    return 0;
}