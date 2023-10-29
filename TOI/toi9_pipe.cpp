#include <bits/stdc++.h>
using namespace std;

const int N = 303, a = 11, b = 12, c = 13, d = 14, v = 21, h = 22, r = 31;
int ar[N][N];
int n, m;

int mv(int di, int i, int j) {
    if(i < 1 || i > n || j < 1 || j > m) return 0;
    int &x = ar[i][j];
    if(x == a) {
        di = (di == 1 ? 4 : 2);
    }else if(x == b) {
        di = (di == 1 ? 3 : 2);
    }else if(x == c) {
        di = (di == 2 ? 4 : 1);
    }else if(x == d) {
        di = (di == 2 ? 3 : 1);
    }
    
    if(x == r) {
        x = (di == 1 || di == 2 ? h : v);
    }else {
        x = 0;
    }
    
    if(di == 1) return 1 + mv(di, i+1, j);
    if(di == 2) return 1 + mv(di, i-1, j);
    if(di == 3) return 1 + mv(di, i, j+1);
    if(di == 4) return 1 + mv(di, i, j-1);

    return 0;
}


int main() {

    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) scanf("%d", &ar[i][j]);
    }
    vector<int> res;
    int x;
    for(int j=1; j<=m; ++j) {
        x = ar[1][j];
        if(x == v || x == r || x == a || x == b) res.emplace_back(mv(1, 1, j));
    }
    for(int j=1; j<=m; ++j) {
        x = ar[n][j];
        if(x == v || x == r || x == c || x == d) res.emplace_back(mv(2, n, j));
    }

    for(int i=1; i<=n; ++i) {
        x = ar[i][1];
        if(x == h || x == r || x == a || x == c) res.emplace_back(mv(3, i, 1)); 
    }
    for(int i=1; i<=n; ++i) {
        x = ar[i][m];
        if(x == h || x == r || x == b || x == d) res.emplace_back(mv(4, i, m));
    }
    printf("%d\n", res.size());
    for(int x : res) printf("%d ", x);

    return 0;
}
/*
5 6
0 21 14 11 0 21
0 12 31 13 0 21
14 22 31 11 14 31
21 0 12 22 11 21
31 22 22 22 22 11
*/