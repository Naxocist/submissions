#include <bits/stdc++.h>
using namespace std;

const int N = 200005, LOG = 17;
int ar[N], sp[N][LOG];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr);
   
    int n, q; scanf("%d%d", &n, &q);
    for(int i=0; i<n; ++i) {
        scanf("%d", &ar[i]); 
        sp[i][0] = ar[i];
    }

    for(int j=1; j<=log2(n); ++j) {
        for(int i=0; i + (1 << j) - 1 < n; ++i) {
            sp[i][j] = min(sp[i][j-1], sp[i + (1 << (j-1))][j-1]);
        }
    }



    while(q--) {
        int l, r; scanf("%d%d", &l, &r);
        l--; r--;
        int lg = 31 - __builtin_clz(r - l + 1); // log2(r-l+1)
        cout << min(sp[l][lg], sp[r - (1 << lg) + 1][lg]) << '\n';
    }
    return 0;
}