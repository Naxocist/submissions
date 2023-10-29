#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> v(n+1);
    ll s = 0;
    for(int i=1; i<=n; ++i) {
        cin >> v[i];
        s += v[i];
        v[i] += v[i-1];
    }

    while(q--) {
        ll l, r, k; cin >> l >> r >> k;
        ll x = (k*(r-l+1)) + (s - (v[r] - v[l-1]));
        if(x % 2) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;  cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}