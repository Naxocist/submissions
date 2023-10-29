#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
const int N = 1e3 + 3;
pi dp[N][N];
int a[N], b[N], n, l;

pi add(pi a, int b) {
    if(a.second + b > l) a.first++, a.second = b;
    else a.second += b;

    return a;
}

int main() {

    scanf("%d%d", &l, &n);

    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &b[i]);

    dp[0][0] = pi(0, l);
    for(int i=1; i<=n; ++i) dp[0][i] = add(dp[0][i-1], a[i]);
    

    for(int i=1; i<=n; ++i) dp[i][0] = add(dp[i-1][0], b[i]);
    
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            pi x = add(dp[i][j-1], a[j]), y = add(dp[i-1][j], b[i]);
            dp[i][j] = min(x, y);
        }
    }

    printf("%d\n%d", dp[n][n].first, dp[n][n].second);
    return 0;
}