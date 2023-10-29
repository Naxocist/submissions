#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using T = tuple<ll, int, int>;
const int N = 1e5 + 3;
ll dist[3][N], mat[3][N];

int main() {

    int n; scanf("%d", &n);

    for(int i=0; i<3; ++i) {
        for(int j=0; j<n; ++j) scanf("%lld", &mat[i][j]), dist[i][j] = 2e18;
    }

    priority_queue<T> pq;
    pq.emplace(0, 0, 0);
    dist[0][0] = mat[0][0];

    while(pq.size()) {
        int r, c; ll w; tie(w, r, c) = pq.top(); pq.pop();

        if(c == n-1) {
            printf("%lld", dist[r][c]);
            return 0;
        }
        int t[] = {-1, 0, 1};
        for(int i=0; i<3; ++i) {
            int nr = r + t[i];
            if(nr < 0 || nr > 2 || nr < r) continue ;

            int nw = mat[nr][c+1];
            if(dist[r][c] + nw < dist[nr][c+1]) {
                dist[nr][c+1] = dist[r][c] + nw;
                pq.emplace(-dist[nr][c+1], nr, c+1);
            }
        }
    }

    return 0;
}