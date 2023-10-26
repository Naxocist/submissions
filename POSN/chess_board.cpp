#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
 
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using pii = pair<int, pi>;

const int N = 1005;
char mp[N][N];
bool vis[N][N];
int tr[] = {-2, -1, 1, 2, 2, 1, -1, -2}, tc[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m; cin >> n >> m;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m ;++j){
            cin >> mp[i][j];

        }
    }

    int sr, sc, dr, dc;
    cin >> sr >> sc >> dr >> dc;

    queue<pii> q;
    vis[sr][sc] = 1;
    q.push({0, {sr, sc}});
    while(q.size()){
        pii f = q.front(); q.pop();
        int mv = f.first, r = f.second.first, c = f.second.second;

        if(r == dr && c == dc){
            cout << mv;
            return 0;
        }
        for(int i=0; i<8; ++i){
            int h = r + tr[i], k = c + tc[i];
            if(h < 1 || k < 1 || h > n || k > m || vis[h][k] || mp[h][k] == '#') continue;
            vis[h][k] = 1;
            q.push({mv+1, {h, k}});
        }
    }

    cout << -1;

    return 0;
 
}

/*
4 10
.###......
##.######.
##..###.##
....#..##.
1 1 4 10
ans = 6

4 10
.###......
##.######.
##..######
....#..##.
1 1 4 10
ans = -1
*/