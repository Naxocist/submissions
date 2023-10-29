#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int f[N], n;

int query(int x) {
    int s = 0;
    while(x) {
        s += f[x];
        x -= x & -x;
    }

    return s;
}

void update(int x, int v) {
    while(x <= n) {
        f[x] += v;
        x += x & -x;
    }
}

int main() {

    cin >> n;
    for(int i=1; i<=n; ++i) {
        int x; scanf("%d", &x);
        int k = i;
        while(k<=n) {
            f[k] += x;
            k += k&-k;
        }
    }

    int q; cin >> q;
    while(q--) {
        int c, l, r; cin >> c >> l >> r;

        if(c == 1) {
            cout << query(r) - query(l-1) << '\n';
        }else {
            update(l, r);
        }
    }

    return 0;
}