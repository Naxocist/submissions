#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 3;
int ar[N], dp[N][N];

int main() {

    int n; scanf("%d", &n);

    for(int i=1; i<=n; ++i) {
        scanf("%d", &ar[i]);
    }

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=i; ++j) {
            dp[i][j] = max(dp[i-1][j-1] + ar[i], dp[i-1][j+2] - ar[i]);
        }
        dp[i][0] = max(dp[i-1][0], dp[i-1][2] - ar[i]);
    }

    // for(int i=1; i<=n; ++i) {
    //     for(int j=0; j<=i; ++j) {
    //         printf("%d ", dp[i][j]);
    //         if(!j) printf("| ");
    //     }
    //     printf("\n");
    // }

    printf("%d", dp[n][0]);
    return 0;
}