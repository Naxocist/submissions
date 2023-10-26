#include <bits/stdc++.h>
using namespace std;

#define INF 2e9

using tiii = tuple<int, int, int>;
using pi = pair<int, int>;
using ll = long long;

const int N = 2505;

vector<tiii> edge;
int dsu[N];

int par(int u){
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v){
    int x = par(u), y = par(v);
    dsu[x] = y;
}


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;

    for(int i=1; i<=n; ++i) dsu[i] = i;

    
    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
    }
    int s, d, p; cin >> s >> d >> p;

    sort(edge.begin(), edge.end(), greater<tiii>());

    int bt = 1e9;
    for(auto e : edge){
        int u, v, w;
        tie(w, u, v) = e;

        if(par(u) != par(v)){
            un(u, v);
            if(par(s) == par(d)){
                bt = w-1;
                break;
            }
        }   
    }

    cout << ceil((double) p / bt);
    return 0;
}
