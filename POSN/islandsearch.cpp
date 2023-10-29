#include <bits/stdc++.h>
#define endll '\n'
using namespace std;


int arr[500][500], cnt, c[500][500];

void bfs(int i, int j){ 
    queue<pair<int, int>> q;
    int v[3] = {-1, 0, 1};

    q.push(make_pair(i, j));
    while(!q.empty()){
        pair<int, int> p = q.front();
        int a = p.first, b = p.second;
    
        c[a][b] = 1;
    
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                int h = a + v[i], k = b + v[j];
                if(arr[h][k] == 1 && c[h][k] == 0){
                    q.push(make_pair(h, k));
                    c[h][k] = 1;
                }
            }
        }

        q.pop();
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j) cin >> arr[i][j];
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(arr[i][j] == 1 && c[i][j] != 1){
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}

/*
5
0 0 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 0 0

2


5
0 1 0 1 1 
1 0 0 1 1
0 1 0 0 0
0 0 0 0 0
1 1 1 1 1 

3
*/