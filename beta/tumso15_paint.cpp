#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
bool vis[N][N];
int n, m;

void dfs(int i, int j) {
    if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j]) return ;

    vis[i][j] = true;
    dfs(i-1, j); dfs(i, j-1); dfs(i+1, j); dfs(i, j+1);
    return ;
}

void solve() {
    cin >> n >> m;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            char c; cin >> c;

            if(c == '*') vis[i][j] = true;
            else vis[i][j] = false;
        }
    }
    int cnt = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(!vis[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << '\n';
    return ;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q; cin >> q;
    while(q--) solve();
    
    return 0;
}