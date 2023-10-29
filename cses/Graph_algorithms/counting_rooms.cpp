#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
 
using ll = long long;
using pi = pair<int, int>;
using pii = pair<pi, int>;
 
const int N = 1005;
int tr[] = {-1, 1, 0, 0}, tc[] = {0, 0, -1, 1}, n, m;
char mp[N][N];
bool vis[N][N];
 
void bfs(int r, int c){
    
    queue<pi> q; q.push({r, c});
    vis[r][c] = 1;
    while(q.size()) {
        int i = q.front().first, j = q.front().second; q.pop();
        for(int u=0; u<4; ++u){
            int h = i + tr[u], k = j + tc[u];
            if(h < 0 || k < 0 || h >= n || k >= m || mp[h][k] == '#' || vis[h][k]) continue;
            vis[h][k] = 1;
            q.push({h, k});
        }
    }
 
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n >> m;
 
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> mp[i][j];
        }
    }
 
    int cnt = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(mp[i][j] == '.' && !vis[i][j]){
                bfs(i, j);
                cnt ++;
            }
        }
    }
 
    cout << cnt;
    return 0;
 
}
