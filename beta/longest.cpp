#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

using ll = long long;

const int N = 1e3 + 3;
string ar[N];


int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int q; cin >> q;

    while(q--){
        int n, m; cin >> n >> m;
        
        for(int i=0; i<n; ++i) cin >> ar[i];

        int dp[4][n+3][m+3];
        memset(dp, 0, sizeof(dp));

        // right && down
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(ar[i-1][j-1] == '1'){
                    dp[0][i][j] = dp[0][i][j-1] + 1;
                    dp[1][i][j] = dp[1][i-1][j] + 1;
                }
            }
        }

        // left && up
        for(int i=n; i>0; --i){
            for(int j=m; j>0; --j){
                if(ar[i-1][j-1] == '1'){
                    dp[2][i][j] = dp[2][i][j+1] + 1;
                    dp[3][i][j] = dp[3][i+1][j] + 1;
                }
            }
        }

        int a, b, mx = -1e9;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                a = max(dp[0][i][j], dp[2][i][j]);
                b = max(dp[1][i][j], dp[3][i][j]);
                mx = max(mx, a + b - 1); // right + up // right + down // left + up // left + down
            }
        }
        cout << mx << '\n';
        
    }
    return 0;

}

