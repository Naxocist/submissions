#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using tiii = tuple<int, int, int>;

const int N = 1e5 + 3;
int dsu[N];
vector<tiii> mst, edge;

int par(int u){
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}


void un(int u, int v){
    int x = par(u), y = par(v);
    dsu[x] = y;

    return ;
}


int main() {
    // freopen("input.in", "r", stdin);
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<n; ++i) dsu[i] = i;
    
    int u, v, w;
    for(int i=0; i<m; ++i){
        scanf("%d%d%d", &u, &v, &w);
        edge.emplace_back(w, u, v);
    }

    sort(edge.begin(), edge.end());

    priority_queue<int> pq;

    for(auto x : edge){
        tie(w, u, v) = x;
        if(par(u) != par(v)){
            un(u, v);
            pq.push(w);
        }
    }

    int s = 0;

    while(k--){
        int x = pq.top(); pq.pop();
        x /= 2;
        pq.push(x);
    }

    while(pq.size()) s += pq.top(), pq.pop();
    
    printf("%d", s);
    return 0;
}
