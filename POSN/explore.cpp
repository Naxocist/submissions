#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 3;
vector<int> adj[N];
bool no[N];
int n, m, k, mx = 1;

bool dfs(int u, int p) {
    if(u == n) 
        return 1;
    
    mx = max(mx, u);
    for(int v : adj[u]) {
        if(p == v) continue ;
        if(dfs(v, u)) return 1;
    }

    return 0;
}

int main() {

    scanf("%d%d%d", &n, &m, &k);

    int u, v;
    for(int i=0; i<m; ++i) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }

    for(int i=0; i<k; ++i) {
        int x; scanf("%d", &x);
        no[x] = 1;
    }

    for(int i=1; i<=n; ++i) {
        if(no[i]) continue ;
        adj[i].push_back(i+1);
    }


    if(dfs(1, -1)) printf("1");
    else printf("0 %d", mx);
    return 0;
}