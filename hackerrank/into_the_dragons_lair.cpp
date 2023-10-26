#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
int qs[N];

int f(int x) {
    int k = 1;
    while(x > 9*k) {
        x -= 9*k;
        k ++;
    }
    
    return ceil(double(x) / double(k));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> v(n+1); 
    for(int i=1; i<=n; ++i) {
        int x; cin >> x;
        v[i] = f(x);
        // cout << v[i] << endl;
    }
    // cout <<"---\n";
    
    for(int i=1; i<=n; ++i) {
        qs[i] = qs[i-1] + max(0, v[i] - v[i-1]);
    }
    
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << qs[r] - qs[l] << '\n';
    }
    return 0;
}