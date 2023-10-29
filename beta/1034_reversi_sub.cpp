#include <bits/stdc++.h>
using namespace std;

#define INF 2e9

using tiii = tuple<int, int, int>;
using ll = long long;

const int N = 10;
char ar[N][N];

void capture(int r, int c, char &p){
    char t = (p == 'O' ? 'X' : 'O');
    bool a = 0, b = 0;
    int x = r, y = r;

    // vertical
    while(x >= 1) {
        if(ar[x][c] == t) {
            a = 1;
            break;
        }
        x--;
    }
    while(y <= 8) {
        if(ar[y][c] == t){
            b = 1;
            break;
        }
        y++;
    }

    if(a && b){
        for(int i=x; i<=y; ++i) ar[i][c] = t;
    }

    // horizontal
    x = c; y = c; a = 0, b = 0;
    while(x >= 1) {
        if(ar[r][x] == t) {
            a = 1;
            break;
        }
        x--;
    }
    while(y <= 8) {
        if(ar[r][y] == t){
            b = 1;
            break;
        }
        y++;
    }

    if(a && b){
        for(int i=x; i<=y; ++i) ar[r][i] = t;
    }

    // diagonal 1
    x = r; y = c; a = 0; b = 0;

    while(x >= 1 && y <= 8){
        if(ar[x][y] == t) {
            a = 1;
            break;
        }
        x--; y++;
    }

    int h = x, k = y;
    x = r; y = c;

    while(x <= 8 && y >= 1){
        if(ar[x][y] == t){
            b = 1;
            break;
        }
        x++; y--;
    }

    if(a && b){
        for(int i=h, j=k; i<=x && j>=y; i++, j--) ar[i][j] = t;
    }

    // diagonal 2
    x = r; y = c; a = 0; b = 0;

    while(x >= 1 && y >= 1){
        if(ar[x][y] == t) {
            a = 1;
            break;
        }
        x--; y--;
    }

    h = x, k = y;
    x = r; y = c;

    while(x <= 8 && y <= 8){
        if(ar[x][y] == t){
            b = 1;
            break;
        }
        x++; y++;
    }

    if(a && b){
        for(int i=h, j=k; i<=x && j<=y; i++, j++) ar[i][j] = t;
    }
    return ;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin >> n;
    for(int i=1; i<=8; ++i){
        for(int j=1; j<=8; ++j) {
            ar[i][j] = '.';
        }
    } 

    ar[5][4] = 'X'; ar[5][5] = 'O'; ar[4][4] = 'O'; ar[4][5] = 'X';

    int k = 0;
    while(n--){
        char cc; int r;
        cin >> cc >> r;
        int c = cc - 'a' + 1;

        ar[r][c] = (k&1^1 ? 'X' : 'O');
        k++;

        for(int i=1; i<=8; ++i){
            for(int j=1; j<=8; ++j){
                if(ar[i][j] == '.') continue ;

                capture(i, j, ar[i][j]);
            }
        }
        // for(int i=1; i<=8; ++i){
        //     for(int j=1; j<=8; ++j) {
        //         cout << ar[i][j];
        //     }
        //     cout << '\n';
        // } 
        // // cout << "-----\n";
    }
    

    for(int i=1; i<=8; ++i){
        for(int j=1; j<=8; ++j) {
            cout << ar[i][j];
        }
        cout << '\n';
    } 
    return 0;
}
