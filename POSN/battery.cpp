#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
using pii = pair<int, pi>;

const int N = 1e6;
vector<pii> edgeList;
int p[N];


int root(int x){
    if(p[x] == x) return x;
    return p[x] = root(p[x]);
}


void un(int u, int v){
    if(root(u) == root(v)) return ;

    int x = root(u), y = root(v);
    p[x] = y;
}

int main(){

    int n, m; scanf("%d %d", &n, &m);
    int u, v, w;

    for(int i=0; i<=n; ++i) p[i] = i;

    for(int i=0; i<m; ++i){
        scanf("%d %d %d", &u, &v, &w);
        edgeList.push_back({w, {u, v}});
    }

    sort(edgeList.begin(), edgeList.end());

    int cost = -1e9;
    for(auto x : edgeList){
        u = x.second.first, v = x.second.second, w = x.first;
        if(root(u) != root(v)){
            cost = max(cost, w);
            un(u, v);
        }
    }

    printf("%d", cost);

    return 0;
}

/*
5 6
0 1 30
1 2 10
1 3 50
3 2 30
2 5 20
5 2 10
*/
