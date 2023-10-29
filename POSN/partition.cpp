#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;

vector<int> v(N);
bool dp[N][N];

bool sss (int i, int sum) {

    if(sum == 0) {
        return true;
    }
    if(sum < 0 || i == 0) return false;

    return sss(i-1, sum) || sss(i-1, sum - v[i]);
}

int main() {

    int n; cin >> n;
    
    int s = 0;

    for(int i=1; i<=n; ++i) cin >> v[i], s += v[i];

    if(s % 2) {
        return 0;
    }

    s /= 2;

    for(int i=0; i<=n; ++i) dp[i][0] = true;
    for(int j=1; j<=s; ++j) dp[0][j] = false;

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=s; ++j) {
            if(j - v[i] < 0) continue ;
            dp[i][j] = dp[i-1][j] || dp[i-1][j - v[i]];
        }
    }

    bool t = dp[n][s];

    cout << t;
    return 0;
}