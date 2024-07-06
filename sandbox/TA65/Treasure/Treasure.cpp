#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
int ar[N], qs[N];

int f(int x) {
    int k = 1;
    while(x > 9*k) {
        x -= 9*k;
        k++;
    }
    
    return (x + k - 1)/k;
}
int main() {
    
    int n; cin >> n;
    for(int i=1; i<=n; ++i) {
        int x; cin >> x;
        ar[i] = f(x);
    }
    
    for(int i=2; i<=n; ++i) {
        qs[i] = qs[i-1] + max(0, ar[i] - ar[i-1]);
    }
    
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << qs[r] - qs[l] << '\n';
    }
    
    return 0;
}