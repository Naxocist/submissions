#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using pi = pair<int, int>;
using tiii = tuple<int, int, int>;


const int N = 505, mod = 1e9 + 7;
int ar[N], dist[N][N], node[N][N];


int main() {
    // freopen("input.txt", "r", stdin);
    int n, m, q; scanf("%d%d%d", &n, &m, &q);

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            dist[i][j] = 2e9;
        }
    }

    for(int i=1; i<=n; ++i) scanf("%d", &ar[i]), dist[i][i] = 0;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            dist[i][j] = ar[i] + ar[j];
            node[i][j] = 2;
        }
    }

    for(int i=0; i<m; ++i){
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        dist[u][v] = dist[v][u] = w;
    }


    for(int k=1 ; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    node[i][j] = node[i][k] + node[k][j];
                }else if(dist[i][k] + dist[k][j] == dist[i][j]){
                    if(node[i][k] + node[k][j] > node[i][j]) {
                        node[i][j] = node[i][k] + node[k][j];
                    }

                }
            }
        }
    }

    
    while(q--){
        int s, e; scanf("%d%d", &s, &e);

        if(dist[s][e] <= ar[s] + ar[e]){
            printf("%d %d\n", dist[s][e], node[s][e]);
        }else{
            printf("%d %d\n", ar[s] + ar[e], 2);
        }

    }
    return 0;
}
