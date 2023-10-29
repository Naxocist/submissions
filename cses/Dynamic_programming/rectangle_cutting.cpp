#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int dp[N][N];
int main() {
    
    int r, c; cin >> r >> c;
    
    for(int i=1; i<=r; ++i) {
        for(int j=1; j<=c; ++j) {
            if(i == j) continue ;
                
            dp[i][j] = INT_MAX;
            for(int k=1; k<i; ++k) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }
            
            for(int k=1; k<j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }
    
    cout << dp[r][c];
    return 0;
}
