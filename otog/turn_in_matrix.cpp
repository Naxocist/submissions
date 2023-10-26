#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

pi operator +(const pi &a, const pi &b){
    return pi(a.first + b.first, a.second + b.second);
}

enum Direction {
    U, D, L, R, None
};

using tup = tuple<int, Direction, pi>;
queue<tup> q;

const int N = 2500, INF = 1e9;

char mp[N][N];
int ar[N][N];
pi diff[] = {{-1, 0}, {1, 0}, {0,-1}, {0, 1}};


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    pi st;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            char &c = mp[i][j];
            cin >> c;
            if(c == 'K'){
                st = {i, j};
            }
            ar[i][j] = INF;
        }
    }

    q.emplace(-1, None, st);

    while(q.size()){
        tup f = q.front(); q.pop();

        int turn = get<0>(f); Direction lastDir = get<1>(f); pi pos = get<2>(f);
        int i = pos.first, j = pos.second;

        if(turn > ar[i][j]) continue;

        for(Direction newDir : {L, R, U, D}){
            pi nPos = pos + diff[newDir];
            int h = nPos.first, k = nPos.second, nTurn = turn + (lastDir != newDir);
            
            if(h < 0 || k < 0 || h >= n || k >= n || mp[h][k] != '.' || nTurn > ar[h][k]) continue;    

            ar[h][k] = nTurn;
            q.emplace(nTurn, newDir, nPos);
        }
    }

    int mx = -1e9, cnt = 1;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(mp[i][j] == 'K') {
                cout << "K ";
                continue;
            }
            if(mp[i][j] != '.' || ar[i][j] == INF) {
                cout << "# ";
                continue;
            }
            cout << ar[i][j] << ' ';
            int k = ar[i][j];
            if(k > mx){
                mx = k;
                cnt = 1;
            }else if(k == mx) cnt++;
        }
        cout << '\n';
    }
    cout << mx << '\n' << cnt;
    return 0;
}

/*
8
.....#..
...#....
.#......
......#.
#..#.K.#
..#.....
......#.
.#...#..
*/