#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " is: " << x << '\n'
#define div() cout << "############\n"
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back

using ll = long long int;
const int mod = 1e9 + 7;
const int INF = 2e9;
const int N = 303;
int ar[N][3];
ll dp[2][N][N][3][2];

void solve() {
    int n, t; cin >> n >> t;
    for(int i=1; i<=n; ++i) {
        cin >> ar[i][1] >> ar[i][2];
    }

    for(int i=0; i<=1; ++i) {
        for(int j=0; j<=n; ++j) {
            for(int k=0; k<=n; ++k) 
                for(int h=0; h<3; ++h) {
                    dp[i][j][k][h][0] = -1e18;
                    dp[i][j][k][h][1] = -1e18;
                }
        }
    }


    dp[0][0][0][0][0] = dp[1][0][0][1][0] = dp[1][0][0][2][0] = 0;

    dp[1][0][1][1][0] = ar[1][2];
    dp[1][1][0][2][0] = ar[1][1];
    for(int i=1; i<=n; ++i) {

        ll left = ar[i][1], right = ar[i][2];

        ll topleft = ar[i-1][1], topright = ar[i-1][2];

        if(i > 1)
            for(int j=0; j<=n; ++j) {
                for(int k=0; k<=n; ++k)  {
                    for(int h=0; h<3; ++h) {
                        dp[i%2][j][k][h][0] = -1e18;
                        dp[i%2][j][k][h][1] = -1e18;
                    }
                }
            }

        for(int a=0; a<=i; ++a) {
            for(int b=0; b<=i; ++b) {

                // 0, 1
                for(int q=0; q<=t; ++q) {
                    dp[i%2][a][b][0][q] = max({
                            dp[(i-1)%2][max(0, a-1)][max(0, b-1)][0][q] + left*(a>0) + right*(b>0),
                            dp[(i-1)%2][a+1][b][0][q] - left + right,
                            dp[(i-1)%2][a][b+1][0][q] + left - right,

                            // pick type 1 as special jigsaw at row i
                            dp[(i-1)%2][a][b][1][q^1] - left + right + topleft,

                            // pick type 2 as speicl jigsaw at row i
                            dp[(i-1)%2][a][b][2][q^1] + left - right + topright
                    });
                }

                if(i > 1) {
                    dp[i%2][a][b][1][0] = max({
                            dp[(i-1)%2][a+1][b][1][0] - topleft + right,
                            dp[(i-1)%2][a][b+1][1][0] + topleft - right,
                            dp[(i-1)%2][max(0, a-1)][max(0, b-1)][1][0] + topleft*(a>0) + right*(b>0)
                    }); 

                    dp[i%2][a][b][2][0] = max({
                            dp[(i-1)%2][a+1][b][2][0] - left + topright,
                            dp[(i-1)%2][a][b+1][2][0] + left - topright,
                            dp[(i-1)%2][max(0, a-1)][max(0, b-1)][2][0] + left*(a>0) + topright*(b>0)
                    });
                }
            }
        }
    }

    cout << dp[n%2][0][0][0][t] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int TC = 1; 
    // cin >> TC;
    while(TC--) solve();
    return 0;
}
