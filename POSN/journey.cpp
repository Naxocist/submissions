#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

using pi = pair<int, int>;

const int N = 1e5 + 10;

vector<pi> adjList[N];
int dist[N];

int main(){
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<=n; ++i) dist[i] = INF;

    for(int i=0; i<m; ++i){
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        int w = pq.top().first, u = pq.top().second;
        pq.pop();

        if(w > dist[u]) continue;

        for(auto x : adjList[u]){
            int v = x.first, vw = x.second;
            if(w + vw < dist[v]){
                dist[v] = w + vw;
                pq.push({dist[v], v});
            }
        }
    }

    int mx=1;
    for(int i=1; i<=n; ++i) {
        if(dist[i] == INF) continue;
        if(dist[i] <= k){
            mx = max(mx, i);
        }
    }

    printf("%d", mx);
    return 0;
}
