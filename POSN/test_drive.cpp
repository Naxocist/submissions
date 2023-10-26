#include <bits/stdc++.h>
using namespace std;

#define INF 2e9

using tiii = tuple<int, int, int>;
using pi = pair<int, int>;
using ll = long long;

const int N = 1005;
int in[N], dist[N][N];
vector<int> adj[N];


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;

    for(int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);
        adj[u].push_back(v);
        in[v]++;
    }

    queue<tiii> q;
    for(int i=1; i<=n; ++i) if(!in[i]) q.emplace(i, i, 0);

    int mx = 0;
    vector<tiii> v;
    while(q.size()){
        int u, p, t; 
        tie(u, p, t) = q.front(); q.pop();
        
        mx = dist[p][u] = t;
        for(int v : adj[u]){
            q.emplace(v, p, t+1);
        }
    }

    cout << mx << '\n';
    for(int i=1; i<=n; ++i){
        if(in[i]) continue ;

        for(int j=1; j<=n; ++j){
            if(dist[i][j] == mx){
                cout << "(" << i << ","<< j << ") ";
            }
        }
    }
    return 0;
}
