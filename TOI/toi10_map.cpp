#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3, M = 4e4 + 3;
using pi = pair<int, int>;
vector<pi> adj[M];
int in[M], res[N][N];
int x = 1e9, y = 1e9;

void dfs(int u, int p, int i, int j) {
    x = min(x, i), y = min(y, j);

    res[i][j] = u;
    for(pi e : adj[u]) {
        int v = e.first, mv = e.second;
        if(v == p) continue ;

        if(mv == 1) dfs(v, u, i+1, j);
        else if(mv == 2) dfs(v, u, i-1, j);
        else if(mv == 3) dfs(v, u, i, j+1);
        else dfs(v, u, i, j-1);
    }

    return ;
}


int main() {

    int n, m; scanf("%d%d", &n, &m);
    int k = n*m; 
    for(int i=1; i<k; ++i){
        int a, b; char c;
        scanf("%d %c%d", &a, &c, &b);
        in[a] ++; in[b] ++;
        if(c == 'U') {
            adj[a].emplace_back(b, 1);
            adj[b].emplace_back(a, 2);
        }else {
            adj[a].emplace_back(b, 3);
            adj[b].emplace_back(a, 4);
        }
    }

    int s = -1;
    for(int i=0; i<k; ++i) {
        if(in[i] == 1) s = i;
    }
    
    dfs(s, -1, 500, 500);

    for(int i=x; i<x+n; ++i) {
        for(int j=y; j<y+m; ++j) printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}