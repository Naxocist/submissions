#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

using ll = long long;
using pi = pair<int, int>;
using pii = pair<pi, int>;

const int N = 25;
int ar[N][N], tr[] = {-1, 1, 0, 0}, tc[] = {0, 0, -1, 1};
bool vis[N][N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;
    int x, y; cin >> y >> x;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j) cin >> ar[i][j];
    }

    queue<pi> q;

    vis[x][y] = 1;
    int mx = ar[x][y];
    q.push({x, y});

    while(q.size()){
        pi f = q.front(); q.pop();
        int r = f.first, c = f.second;

        for(int i=0; i<4; ++i){
            int h = r + tr[i], k = c + tc[i];
            if(h < 1 || k < 1 || h > n || k > n || ar[h][k] <= ar[r][c] || vis[h][k] || ar[h][k] == 100) 
                continue;
                
            vis[h][k] = 1;
            mx = max(mx, ar[h][k]);
            q.push({h, k});
        }
    }
    cout << mx;
    return 0;

}

