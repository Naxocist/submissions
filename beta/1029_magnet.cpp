#include <bits/stdc++.h>
using namespace std;

const int N = 1e8 + 3;

int main() {
    cout.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, m, q; scanf("%d%d%d", &n, &m, &q);

    set<int> s; 
    while(m--) {
        int x, y; scanf("%d%d", &x, &y);
        if(s.count(x)) s.erase(x);
        else s.insert(x);
        y = x + y;
        if(s.count(y)) s.erase(y);
        else s.insert(y);
    }
    s.insert(n+1);
    while(q--) {
        int x; scanf("%d", &x);
        auto k = s.upper_bound(x);
        if(k == s.begin()) cout << *k - 1;
        else cout << *k - *--k;

        cout << '\n';
    }

    return 0;
}