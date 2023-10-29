#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int N = 2e4 + 3;
int dp[N], cut[N], aroi[N];


int main() {

    int n, m, k; scanf("%d%d%d", &n, &m, &k);

    for(int i=1; i<=m; ++i) scanf("%d", &cut[i]);
    for(int i=1; i<=k; ++i) scanf("%d", &aroi[i]);

    for(int i=0; i<=m; ++i) {
        dp[i] = aroi[1] * n;
    }

    for(int i=2; i<=k; ++i) {
        int t = dp[i-2];
        for(int j=i-1; j<=m; ++j) {
            int left = n - cut[j];
            int x = max((j == i-1 ? -1 : dp[j-1]), t - (aroi[i-1]*left) + (aroi[i]*left));
            t = dp[j];
            dp[j] = x;
        }
    }

    printf("%d", dp[m]);
    return 0;
}

/*
10 5 3
1 3 5 8 9
4 2 2

10 5 3
2 4 6 8 9
4 3 9
*/