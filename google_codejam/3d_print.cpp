#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d;
    a = b = c = d = 1e9;

    int q = 3;
    while(q--) {
        int x, y, z, e; cin >> x >> y >> z >> e;
        a = min(a, x);
        b = min(b, y);
        c = min(c, z);
        d = min(d, e);
    }

    if(a + b + c + d < 1e6) {
        cout << "IMPOSSIBLE\n"; return ;
    }

    int s = 1e6;

    cout << a << ' ';
    s -= a;
    cout << min(s, b) << ' ';
    s -= b; s = max(s, 0);
    cout << min(s, c) << ' ';
    s -= c; s = max(s, 0);
    cout << min(s, d) << '\n';

}

int main() {
    
    int q; cin >> q;
    for(int i=1; i<=q; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}