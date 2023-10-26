#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

const int N = 5005;
int table[N][N], visited[N][N], dsu[N][N], n, parent[N*N], sz[N*N], index=1;
int tx[] = {1, -1, 0, 0};
int ty[] = {0, 0, -1, 1};


int root(int u){
    if(u == parent[u]) return u;
    return parent[u] = root(parent[u]);
}


void un(int u, int v){
    int x = root(u), y = root(v);
    if(x == y) return ;
    parent[y] = x;
}


int func(int r, int c){
    if(table[r][c] == 1) return -1;
    int p = root(dsu[r][c]);
    return sz[p];
}


void setting(int r, int c){ 
    vector<pi> v;
    queue<pi> q;

    int cnt = 1;
    q.push({r, c});
    v.push_back({r, c});
    visited[r][c] = true;

    while(!q.empty()){ 
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0; i<4; ++i){
            int h = x + tx[i], k = y + ty[i];
            if(h < 1 || k < 1 || h > n || k > n) continue;

            if(!visited[h][k] && table[h][k] == 0){
                visited[h][k] = true;
                q.push({h, k});
                v.push_back({h, k});
                cnt++;
            }
        }
    }

    for(auto x : v) dsu[x.first][x.second] = index;
    
    parent[index] = index;
    sz[index] = cnt;
    index += 1;
}

void update(int r, int c){
    if(table[r][c] == 0) return ;
    table[r][c] = 0;

    dsu[r][c] = index;
    parent[index] = index;
    
    unordered_set<int> us;
    for(int i=0; i<4; ++i){ // check changes
        int h = r + tx[i], k = c + ty[i];
        if(h < 1 || k < 1 || h > n || k > n) continue;
        if(dsu[h][k] != 0){
            int ch = root(dsu[h][k]);
            un(parent[dsu[r][c]], ch);
            us.insert(ch);
        }
    }

    int V = 1;
    for(auto x : us) V += sz[x];
    sz[index] = V;

    index += 1;
}


int main(){

    scanf("%d", &n);
    
    for(int i=1; i<=n; ++i){
        string s; cin >> s;
        for(int j=1; j<=n; ++j){
            table[i][j] = s[j-1] - '0';
        }
    }

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(visited[i][j] || table[i][j] == 1) continue;
            setting(i, j);
        }
    }

    int q; scanf("%d", &q);
    while(q--){
        char k; scanf(" %c", &k);
        int r, c; scanf("%d %d", &r, &c);

        if(k == 'F') printf("%d\n", func(r, c));
        
        if(k == 'D') update(r, c);
        
    }
    return 0;
}
