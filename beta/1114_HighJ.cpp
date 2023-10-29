#include <bits/stdc++.h>
using namespace std;

const int N = 6e2 + 3;
int v[N][N];

int main() {

    int n; scanf("%d", &n); n*=2;
    
    for(int i=1; i<=n; ++i) 
        for(int j=1; j<=n; ++j) scanf("%d", &v[i][j]);
        
    vector<int> dp(n+1);
    for(int i=3; i<=n; ++i) {
        dp[i] = 1e9;
        for(int j=2; j<i; ++j) {
            dp[i] = min(dp[i], dp[j] + v[i][j]);
        }
    }

    printf("%d", dp[n]);
    return 0;
}