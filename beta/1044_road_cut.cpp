#include <bits/stdc++.h>
using namespace std;

const int N = 105; 
int ar[N][N], p[N][N], a[N], b[N], c[N], d[N];

int main() {

    int n, m; scanf("%d%d", &n, &m);

    int x = 0, s = 0;

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) scanf("%d", &ar[i][j]), a[i] += ar[i][j];
        x += a[i];
    }

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) scanf("%d", &p[i][j]), c[i] += p[i][j];
    }

    for(int j=1; j<=m; ++j) {
        for(int i=1; i<=n; ++i) b[j] += ar[i][j], d[j] += p[i][j];
    }

    for(int i=1; i<=n; ++i) s = max(s, x - a[i] + c[i-1] + c[i+1]);
    for(int i=1; i<=m; ++i) s = max(s, x - b[i] + d[i-1] + d[i+1]);
    cout << s;
    return 0;
}