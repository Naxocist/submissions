#include <bits/stdc++.h>
using namespace std;
 
int M = 1e9 + 7;
 
int main() {
    
    int n; scanf("%d", &n);
    
    vector<int> dp(n+1, 0);
    for(int i=1; i<=n; ++i) {
        if(i <= 6) dp[i] = 1;
        
        for(int j=1; j<=6; ++j) {
            if(i - j < 0) continue ;
            
            dp[i] = (dp[i] + dp[i-j]) % M;
        }
    }
    
    printf("%d", dp[n]);
    return 0;
}
