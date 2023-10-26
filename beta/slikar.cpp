#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

using ll = long long;
using pi = pair<int, int>;
using pii = pair<pi, int>;

const int N = 53;
int tr[] = {-1, 1, 0, 0}, tc[] = {0, 0, -1, 1};
char mp[N][N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;

    pi st, tar;
    queue<pii> q;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            char &c = mp[i][j];
            cin >> c;
            if(c == 'S'){
                st = {i, j};
            }
            if(c == 'D'){
                tar = {i, j};
            }
            if(c == '*'){
                q.push({{i, j}, 0});
            }

        }
    }
    
    q.push({{st.first, st.second}, 0});
    
    while(q.size()){
        pii t = q.front(); q.pop();
        int r = t.first.first, c = t.first.second, u = t.second;
        int type = (mp[r][c] == '*' ? 0 : 1);
        
        if(tar.first == r && tar.second == c){
            cout << u;
            return 0;
        }

        for(int i=0; i<4; ++i){
            int h = r+tr[i], k = c+tc[i];
            if(h < 0 || k < 0 || h >= n || k >= m) continue ;

            if(type && (mp[h][k] == '.' || mp[h][k] == 'D')){
                mp[h][k] = 'S';
                q.push({{h, k}, u+1});
            }
            else if(!type && (mp[h][k] == '.' && mp[h][k] != 'D')){
                mp[h][k] = '*';
                q.push({{h, k}, u+1});
            }
        }
    }

    cout << "KAKTUS";
    return 0;

}

