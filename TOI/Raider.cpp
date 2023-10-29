#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using pii = pair<int, pi>;
using tiii = tuple<int, int, int>;

const int N = 105;
int ar[N][N], dis[N][N];
int rr[] = {-1, -1, 0, 0, 1, 1}, cc[2][6] = {{0, 1, -1, 1, 0, 1}, {-1, 0, -1, 1, -1, 0}}; // odd even (base 1)


int main() {
    // freopen("input.in", "r", stdin);

    int n, m; scanf("%d%d", &n, &m);

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j) scanf("%d", &ar[i][j]);
    }

    queue<tiii> q;
    int md = (n-1)/2 + 1;

    q.emplace(0, md, 0);

    while(q.size()){
        int mv, r, c;
        tie(mv, r, c) = q.front(); q.pop();

        if(r == md && c == m){
            printf("%d", mv);
            return 0;
        }
        
        mv ++;
        for(int i=0; i<6; ++i){
            int h = r + rr[i], k = c + cc[r&1^1][i];
            
            if(h < 1 || k < 1 || h > n || k > m || ar[h][k] == 0 || dis[h][k] == mv || mv % ar[h][k]) continue ;

            dis[h][k] = mv;
            q.emplace(mv, h, k);
        }

    }

    return 0;
}

/*
5
4
1 1 3 8
0 1 1 0
1 6 5 7
1 3 2 3
2 5 2 0
*/