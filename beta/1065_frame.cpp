#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
struct point {
    int x, y;
};
point a[N], b[N];

int main() {

    int n, m; scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i) {
        scanf("%d%d%d%d", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
    }
    for(int i=0; i<m; ++i) {
        point h, k;
        scanf("%d%d%d%d", &h.x, &h.y, &k.x, &k.y);

        int res = 0;
        for(int j=0; j<n; ++j) {
            point c = a[j], d = b[j];
            if(k.x <= c.x || h.x >= d.x || k.y >= c.y || h.y <= d.y) continue ;
            res ++;
        }
        printf("%d\n", res);
    }

    return 0;
}