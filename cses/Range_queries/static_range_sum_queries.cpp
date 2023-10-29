#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, q; cin >> n >> q;
    vector<ll> v(n+1);
    for(int i=1; i<=n; ++i) cin >> v[i], v[i] += v[i-1];
    while(q--) {
        int l, r; cin >> l >> r;
        cout << v[r]-v[l-1] << '\n';
    }
    return 0;
}
