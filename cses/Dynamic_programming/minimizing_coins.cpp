#include <bits/stdc++.h>
using namespace std;
 
int M = 1e9 + 7;
 
int main() {
    
    int n, k; scanf("%d%d", &n, &k);
    vector<int> dp(k+1, 1e9);
    
    vector<int> c(n);
    for(int i=0; i<n; ++i) scanf("%d", &c[i]);
    
    dp[0] = 0;
    for(int i=1; i<=k; ++i) {
        for(int j=0; j<n; ++j) {
            if(i - c[j] < 0) continue ;
            
            dp[i] = min(dp[i], dp[i-c[j]] + 1);
        }
    }
    
    if(dp[k] == 1e9) printf("-1");
    else printf("%d", dp[k]);
    return 0;
}
