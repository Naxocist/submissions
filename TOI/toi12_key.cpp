#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
bool dp[N][N];

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    string s, z;  cin >> s >> z; int n = s.size(), m = z.size();
    s = '.' + s; z = '.' + z;

    int q; cin >> q;
    while(q--) {
        string t; cin >> t; t = '.' + t;
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        int i = 1;
        while(s[i] == t[i]) dp[i][0] = 1, i++;
        i = 1;
        while(z[i] == t[i]) dp[0][i] = 1, i++;

        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                dp[i][j] = (dp[i][j-1] and z[j] == t[i+j]) or (dp[i-1][j] and s[i] == t[i+j]);
            }
        }
        
        if(dp[n][m]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
/*
ABBBA
BAABA
1
BABABABABA
*/