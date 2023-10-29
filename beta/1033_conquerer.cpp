#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int> ;

const int N = 105;
int ar[N][N], sc[5]; 
pi crr[5];


int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);

    int n, m; cin >> n >> m;

    ar[1][n] = 1, ar[n][n] = 2, ar[n][1] = 3, ar[1][1] = 4;
    crr[1] = {1, n}, crr[2] = {n, n}, crr[3] = {n, 1}, crr[4] = {1, 1};


    string s;
    for(int i=0; i<m*4; ++i) {
        char c; cin >> c; s += c;
    }

    for(int i=0; i<m; ++i) {
        for(int j=i, p=1; p<=4; j+=m, p++){
            char mv = s[j];
    
            int x, y; tie(x, y) = crr[p];
    
            if(mv == 'N') x--;
            if(mv == 'S') x++;
            if(mv == 'W') y--;
            if(mv == 'E') y++; 
            pi go = {x, y};
            
            if(x < 1 || y < 1 || x > n || y > n) continue ; // out of bound
            bool ok = 0;
            for(int h=1; h<=4; ++h) if(go == crr[h]) ok = 1;
            if(ok) continue ;

            ar[x][y] = p;
            crr[p] = go;
        }
    }

    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) sc[ar[i][j]]++;

    if(sc[0]) {
        cout << "No";
        return 0;
    }

    int mx = *max_element(sc+1, sc+5);

    cout << count(sc+1, sc+5, mx) << ' ' << mx << '\n';

    for(int i=1; i<=4; ++i) if(sc[i] == mx) cout << i << '\n';

    return 0;
}