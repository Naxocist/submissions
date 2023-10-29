#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
const int N = 1e3 + 3;
bool graph[N][N];

int main() {

    int n, m; scanf("%d%d", &n, &m);
    vector<pi> edge;

    for(int i=0; i<m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        edge.emplace_back(u, v);
        graph[u][v] = graph[v][u] = 1;
    }

    int five = 0, six = 0;
    for(int i=0; i<m; ++i) {
        for(int j=i+1; j<m; ++j) {
            int a = edge[i].first, b = edge[i].second, c = edge[j].first, d = edge[j].second;
            if(a == c || a == d || b == c || b == d) continue ;

            int p = 2 + graph[a][c] + graph[a][d] + graph[b][c] + graph[b][d];

            if(p == 5) five++;
            else if(p == 6) six++;
        }
    }

    printf("%d", five/2 + six/3);
    return 0;
}