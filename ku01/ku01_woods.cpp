#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
bool t[10][N];

int main() {

    int n, w, L; scanf("%d%d%d", &n, &w, &L);

    for(int i=0; i<n; ++i) {
        int k; scanf("%d", &k);
        while(k--) {
            int x; scanf("%d", &x);
            t[i][x] = 1;
        }
    }

    for(int i=1; i<=w; ++i) {
        for(int j=0; j<n; ++j) {
            for(int l=0; l<=L; ++l) {
                if(t[j][max(1,i-l)] || t[j][min(i+l, w)]) {
                    goto f;
                }
            }

            goto e;
            f:;
        }
        printf("1");
        return 0;
        e:;
    }

    printf("0");
    return 0;
}