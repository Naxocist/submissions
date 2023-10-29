#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
const int N = 1e4 + 3;
vector<vector<bool>> ar(N, vector<bool>(2001, false));
int n, m;


int bfs(int i, int j) {

    int k = -1;
    if(ar[i+1][j] == 1 && ar[i][j+1] == 1) k = 0;

    int mv[] = {1, 0, -1, 0, 1};
    queue<pi> q;
    q.emplace(i, j);

    int t = 1e9, r = -1, b = -1, l = 1e9;
    int cnt = 0;
    while(q.size()) {
        int x, y; tie(x, y) = q.front(); q.pop();
        if(ar[x][y] == 0) continue ;
        ar[x][y] = 0;
        cnt ++;

        t = min(t, x), r = max(r, y), b = max(b, x), l = min(l, y);
        
        for(int i=0; i<4; ++i) {
            int xx = mv[i] + x, yy = mv[i+1] + y;
            if(xx < 1 || yy < 1 || xx > n || yy > m || ar[xx][yy] == 0) continue ;
            q.emplace(xx, yy);
        }
        
    }
    // printf("cnt : %d\n", cnt);

    if(k != -1) return k;

    return (b - t == r - l ? 1 : 2);
}

int main() {

    scanf("%d%d", &m, &n);

    for(int i=1; i<=n; ++i) {
        char s[m+1]; scanf("%s", s+1);
        for(int j=1; j<=m; ++j) {
            ar[i][j] = s[j] - '0';
        }
    }

    vector<int> res(3, 0);

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(ar[i][j] == 1) {
                res[bfs(i, j)] ++;
            }
        }
    }

    for(int x : res) printf("%d ", x);
    return 0;
}