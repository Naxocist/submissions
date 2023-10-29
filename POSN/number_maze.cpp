#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

const int N = 1010;
int table[N][N], dist[N][N];

using pii = pair<int, int>;

int main(){
    int n, m; scanf("%d %d", &n, &m);

    for(int i=1; i<=n; ++i){
        for(int j=1 ; j<=m; ++j){
            scanf("%d", &table[i][j]);
            dist[i][j] = INF;
        }
    }

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push({1, 1});
    dist[1][1] = table[1][1];
    while(!pq.empty()){ // dijkstra's algorithm on 2d array
        int x, y; tie(x, y) = pq.top(); pq.pop();

        int t[] = {-1, 0, 1, 0, 1};
        for(int i=0; i<4; ++i){
            int h = x + t[i], k = y + t[i+1];
            if(h < 1 || k < 1 || h > n || k > m) continue;
            int w = table[h][k];

            if(dist[x][y] + w < dist[h][k]){
                dist[h][k] = dist[x][y] + w;
                pq.push({h, k});
            }
        }
    }


    printf("%d", dist[n][m]); // shortest path
    return 0;
}
