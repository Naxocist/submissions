#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3, M = 13;
int dp[N], coin[M], path[N], A[M], B[M], C[N];

int main() {

    int n, m, k; scanf("%d%d%d", &n, &m, &k);

    for(int i=1; i<=m; ++i) dp[i] = 1e9, path[i] = -1;

    for(int i=0; i<k; ++i) {
        scanf("%d", &coin[i]);
        C[coin[i]] = i;
    }


    for(int i=1; i<=m; ++i) {
        for(int j=0; j<k; ++j) {
            int t = i - coin[j];
            if(t >= 0 && dp[t] + 1 < dp[i]) {
                dp[i] = dp[t] + 1;
                path[i] = coin[j];
            }
        }
    }

    
    int a = 0, b = 0, mn = INT_MAX;
    
    for(int i=n; i<=m; ++i) {
        if(dp[i] + dp[i-n] < mn) {
            mn = dp[i] + dp[i-n];
            a = i; b = a - n;
        }
    }

    int x = 0, y = 0;

    while(a) {
        A[C[path[a]]] ++;
        a -= path[a]; x++;
    }
    

    while(b) {
        B[C[path[b]]] ++;
        b -= path[b]; y++;
    }

    printf("%d %d\n", x, y);
    for(int i=0; i<k; ++i) printf("%d ", A[i]);
    printf("\n");
    for(int i=0; i<k; ++i) printf("%d ", B[i]);
    
    return 0;
}