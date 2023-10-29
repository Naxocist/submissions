#include <bits/stdc++.h>
using namespace std;

int ar[20][20];
int x, y;

int f(int i, int j) {
    int c = 0;

    if(ar[i][j] == ar[i+1][j]) c++, x = 1;
    if(ar[i][j] == ar[i-1][j]) c++, x = -1;
    if(ar[i][j] == ar[i][j+1]) c++, y = 1;
    if(ar[i][j] == ar[i][j-1]) c++, y = -1;

    return c;
}

int main() {

    int n; scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) scanf("%d", &ar[i][j]);
    }

    int res = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            
            if(f(i, j) == 2 && f(i+x, j) == 1 && f(i, j+y) == 1) {
                res ++;
            }
            x = 0; y = 0;
        }

    }
    printf("%d", res);
    return 0;
}

/*
5
3 3 6 6 0
3 5 5 6 8
2 2 5 8 8
2 1 4 4 7
1 1 4 7 7
*/