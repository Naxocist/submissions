#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int ar[N][11], in[11];
int n, p;

bool chk(int u, int v) {

    for(int i=0; i<p; ++i) {
        if(ar[u][i] + ar[v][i] != in[i]) return 0;
    }

    return 1;
}

int main() {

    ios_base::sync_with_stdio(false); cout.tie(nullptr);
    scanf("%d%d", &n, &p);

    for(int i=1; i<=n; ++i) {
        for(int j=0; j<p; ++j) scanf("%d", &ar[i][j]);
    }

    for(int i=0; i<p; ++i) scanf("%d", &in[i]);

    for(int i=1; i<=n; ++i) {

        bool ok = 1;
        for(int k=0; k<p; ++k) {
            if(ar[i][k] != in[k]) {
                ok = 0; break;
            }
        }
        if(ok) {
            cout << i; return 0;
        }
        for(int j=i+1; j<=n; ++j) {
            if(chk(i, j)) {
                cout << i << ' ' << j; return 0;
            }
        }
    }


    cout << "NO";
    return 0;
}