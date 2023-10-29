#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
 
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using pii = pair<pi, vi>;
 
const int N = 1e5 + 3;
int dsu[N];
bool chk[N];
 
int par(int u){
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}
 
void un(int u, int v){
    int x = par(u), y = par(v);
    if(x == y) return ;
    dsu[x] = y;
}
 
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    
    for(int i=1; i<=n; ++i) dsu[i] = i;
    
    int G = n;
    for(int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        if(par(u) != par(v)) G--, un(u, v);
    }
 
    cout << G-1 << '\n';
 
    vector<int> v;
    for(int i=1; i<=n; ++i) {
        int g = par(i);
        if(!chk[g]){
            chk[g] = 1;
            v.push_back(g);
        }
    }
    for(int i=0; i<v.size()-1; ++i){
        cout << v[i] << ' ' << v[i+1] <<  '\n';
    }
 
    return 0;
 
}
