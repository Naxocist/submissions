#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 2e5 + 3;
vector<int> adj[N];
bool choose[N];
int res = 0;
void dfs(int u, int p) {
    for(auto v : adj[u]) {
        if(v == p) continue ;
        dfs(v, u);
        if(!choose[u] and !choose[v]) {
            choose[u] = choose[v] = 1;
            res ++;
        }
 
    }
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    for(int i=1; i<n; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }    
    dfs(1, 0);
    cout << res;
    return 0;
}