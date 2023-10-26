#include <bits/stdc++.h>
using namespace std;

#define INF 2e18

using tiii = tuple<int, int, int>;
using ll = long long;

const int N = 405;
ll dist[N][N];


int main(){
    int n, m; scanf("%d%d", &n, &m);

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j) dist[i][j] = INF;
        dist[i][i] = 0;
    }

    int u, v, w;
    for(int i=0; i<m; ++i){
        scanf("%d%d%d", &u, &v, &w);
        if(w < dist[u][v]){
            dist[u][v] = dist[v][u] = w;
        }
    }


    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    ll s = 0;
    for(int i=1; i<n; ++i){
        s += dist[i][i+1];
    }
    printf("%lld", s);
    return 0;
}
