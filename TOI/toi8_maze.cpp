#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>; 
using tiii = tuple<int, int, int>;
const int mod = 1e9 + 7;
const int N = 155;

int tr[] = {1, -1, 0, 0}, tc[] = {0, 0, 1, -1}, A[N][N], B[N][N], mp[N][N];

int main() {

    // freopen("input.txt", "r", stdin);
    int n, m, x, y, s, e; scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &s, &e);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            scanf("%d", &mp[i][j]);
        }
    }

    int cnt = 0, mn = 2e9;

    queue<pi> q;
    q.emplace(x, y);

    A[x][y] = 1;
    while(q.size()){
         int u, v;

        tie(u, v) = q.front(); q.pop();

        for(int i=0; i<n; ++i){
            int h = tr[i] + u, k = tc[i] + v;
            if(h < 1 || k < 1 || h > n || k > m || A[h][k]) continue ;
            if(mp[h][k]) q.emplace(h, k);
            A[h][k] = A[u][v] + 1;
        }
    }

    q.emplace(s, e);
    B[s][e] = 1;

    while(q.size()){
        int u, v;
        tie(u, v) = q.front(); q.pop();

        for(int i=0; i<n; ++i){
            int h = tr[i] + u, k = tc[i] + v;
            if(h < 1 || k < 1 || h > n || k > m || B[h][k]) continue ;       

            if(mp[h][k]) q.emplace(h, k);
            B[h][k] = B[u][v] + 1;

            if(A[h][k] && B[h][k]){
                cnt++;
                mn = min(mn, A[h][k] + B[h][k] - 1);
            }
        }
    }

    printf("%d\n%d", cnt, mn);
    return 0;

}