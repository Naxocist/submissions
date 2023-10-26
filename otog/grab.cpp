#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
 
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using piv = pair<int, vi>;

const int N = 3e4 + 100;

int sff[50][N], dist[N], tmp[N];
vector<pi> adj[N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m, k, q; cin >> n >> m >> k >> q;

    int u, v, w;
    for(int i=0; i<m; ++i){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for(int i=0; i<=n; ++i) dist[i] = INF;
    int idx = 0;
    while(k--){
        int shop; cin >> shop;
        tmp[shop] = idx;

        priority_queue<pi, vector<pi>, greater<pi>> pq;
        dist[shop] = 0;
        pq.push({0, shop});
        while(pq.size()){
            pi t = pq.top(); pq.pop();
            w = t.first, u = t.second;

            if(w > dist[u]) continue;

            for(pi e : adj[u]){
                v = e.first;
                int vw = e.second;
                if(w + vw < dist[v]){
                    dist[v] = w + vw;
                    pq.push({dist[v], v});
                }
            }
        }

        for(int i=0; i<=n; ++i) {
            sff[idx][i] = dist[i];
            dist[i] = INF;
        }
        idx++;

    }


    while(q--){
        cin >> u >> w >> v;
        k = tmp[w];
        cout << sff[k][u] + sff[k][v] << '\n';
    }
    return 0;
 
}
