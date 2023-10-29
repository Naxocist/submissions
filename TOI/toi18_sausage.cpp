#include <bits/stdc++.h>
using namespace std; 

const int N = 5005;
int ar[N], dp[N][N], res[N];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr);

    int n; scanf("%d", &n);

    for(int i=1; i<=n; ++i) scanf("%d", &ar[i]); 

    for(int l=n; l>=1; --l) {
        for(int r=1; r<=n; ++r) {
            if(l > r) continue ;
            if(l == r) {
                dp[l][r] = ar[l];
                continue ;
            }

            dp[l][r] = max(ar[l] + dp[l+1][r], ar[r] + dp[l][r-1]) + abs(ar[l] - ar[r]);
        }
    }

    for(int i=1; i<=n; ++i) {
        res[i] = dp[1][i]; // no cut
        for(int l=1; l<i; ++l) {
            res[i] = max(res[i], res[l] + dp[l+1][i]); // try cut = (cut till l) + (no cut from l+1 to i) {cut at l - l+1}
        }
    }

    cout << res[n];

    return 0;
}

/*
7
6 83 82 88 11 63 8
*/