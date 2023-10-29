#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int ar[N], qs[N];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr);

    int n, q; scanf("%d%d", &n, &q);

    for(int i=1; i<=n; ++i) {
        scanf("%d", &ar[i]);
        qs[i] = qs[i-1] + ar[i];
    }

    while(q--) {
        int l, m, r; scanf("%d%d%d", &l, &m, &r);

        if(m == 1) {
            cout << qs[r] - qs[l-1] << ' '; continue ;
        }

        int s = 0;
        for(int i=l; i<=r; i+=m) {
            s += ar[i];
        }

        cout << s << ' ';
    }
    return 0;
}