#include <bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>;
const int N = 2e3 + 3;

int main() {

    int n, m; scanf("%d%d", &n, &m);
    vector<vector<char>> ar(n, vector<char>(m, ' '));
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    queue<T> q;
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            char c; scanf(" %c", &c);
            ar[i][j] = c;
            if(c == 'X') q.emplace(i, j, 0), vis[i][j] = 1;
            if(c == 'W') vis[i][j] = 1;
        }
    }

    int k = 0, res = 0;
    while(q.size()) {
        int x, y, d; tie(x, y, d) = q.front(); q.pop();
        // printf("%d %d\n", x, y);
        if(ar[x][y] == 'A') {
            k++;
            res += 2*d;
        }
        int t[] = {1, 0, -1, 0, 1};
        for(int i=0; i<4; ++i) {
            int h = x + t[i], k = y + t[i+1];
            if(h < 0 || k < 0 || h >= n || k >= m || vis[h][k]) continue ;
            vis[h][k] = 1;
            q.emplace(h, k, d+1);
        }
    }
    
    printf("%d %d", k, res);
    return 0;
}

/*
5 9
EEEWEEEEE
EWEWEWEEE
AWXWEWWWE
EWWWEWEXE
EEEEEWAEE
*/