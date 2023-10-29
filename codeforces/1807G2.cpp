#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

void solve() {
    int n; cin >> n;

    ll v[n+1], p[n+1];

    for(int i=1; i<=n; ++i) {
        cin >> v[i];
    }

    v[0] = p[0] = 0;
    sort(v+1, v+1+n);
    for(int i=1; i<=n; ++i) {
        p[i] = p[i-1] + v[i];
    }
    if(v[1] != 1) {
        cout << "NO\n";
        return ;
    }

    for(int i=2; i<=n; ++i) {
        if(v[i] > p[i-1]) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
    return ;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;  cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}