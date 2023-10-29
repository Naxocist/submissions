#include <bits/stdc++.h>
using namespace std;

const int N = 103;
using T = tuple<int, int, int, int, int>;
using pi = pair<int, int>;
vector<pi> ar[N][N];
bool vis[N][N];

int main() {

    int n, m; scanf("%d%d", &n, &m);

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            char c; scanf(" %c", &c);
            if(c == 'R' || c == 'B') {
                ar[i][j].emplace_back(i, j+1);
                ar[i][j+1].emplace_back(i, j);
            }
            if(c == 'D' || c == 'B') {
                ar[i][j].emplace_back(i+1, j);
                ar[i+1][j].emplace_back(i, j);
            }
        }
    }

    queue<T> q;
    q.emplace(1, 1, 0, 0, 1);
    while(q.size()) {
        int x, y, px, py, d; tie(x, y, px, py, d) = q.front(); q.pop();
        if(vis[x][y]) {
            printf("%d\n%d %d", d, x, y); return 0;
        }
        vis[x][y] = 1;
        for(auto e : ar[x][y]) {
            int xx = e.first, yy = e.second;
            if(xx == px && yy == py) continue ;
            q.emplace(xx, yy, x, y, d+1);
        }
    }
    return 0;
}

/*
4 4
B R D N
D R B D
R R R D
N N N N
*/