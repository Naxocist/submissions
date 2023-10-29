#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int ar[N][N];
char d[] = {'N', 'E', 'S', 'W'} ;

int main() {

    int n, m, k; scanf("%d%d%d", &m, &n, &k);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) scanf("%d", &ar[i][j]);
    }

    while(k--) {
        int i, j; scanf("%d%d", &j, &i);
        int lim = n*m, mv = 0;
        bool ok = 1; char c;

        while(i >= 1 && j >= 1 && i <= n && j <= m) {
            if(mv > lim) {
                ok = 0; break ;
            }
            // cout << i << ' ' << j <<  ' ' << ar[i][j] <<'\n';
            int m = ar[i][j];
            if(m == 1) i--;
            else if(m == 2) j++;
            else if(m == 3) i++;
            else j--;

            c = d[m - 1];
            mv++;
        }

        if(ok) cout << c;
        else cout << "NO";

        cout << '\n';
    }
    return 0;
}

/*
N 1
E 2
S 3
W 4
*/