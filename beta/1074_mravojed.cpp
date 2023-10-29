#include <bits/stdc++.h>
using namespace std;

const int N = 105;
char ar[N][N]; 


int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) cin >> ar[i][j];
    }

    int a=1,b=1;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(ar[i][j] == 'x') {
                int x = 1;
                while(ar[i+x][j] == 'x' && ar[i][j+x] == 'x') x++;
                cout << i << ' ' << j << ' ' << x << '\n';
                a=i,b=j;
                for(int h=i; h<i+x; ++h) {
                    for(int k=j; k<j+x; ++k) ar[h][k] = '.';
                }
                goto r;
            }
        }
    }
    r:;
    int l=a,r=b,x=1;
    for(int i=n; i>=1; --i) {
        for(int j=m; j>=1; --j) {
            if(ar[i][j] == 'x'){

                while(ar[i-x][j] == 'x' || ar[i][j-x] == 'x') x++;
                l = max(i-x+1,1); r = max(j-x+1,1);
                goto f;
            }
        }
    }
    f:;
    cout << l << ' ' << r << ' ' << x << '\n';
}

/*
5 5
.....
.xxx.
.xxxx
.xxx.
.....
*/
