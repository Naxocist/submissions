#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using M = array<array<ll, 2>, 2>;
ll mod = 1e9 + 7;
 
M mul(M a, M b) {
    M c = {0};
    for(int i=0; i<2; ++i) {
        for(int j=0; j<2; ++j) {
            for(int k=0; k<2; ++k) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    //  for(int i=0; i<2; ++i) {
    //     for(int j=0; j<2; ++j) {
    //       cout << c[i][j] << ' ';
    //     }cout << endl;
    // }
    // cout << endl;
    
    return c;
}
 
ll fib(ll b) {
    M r = {0}, res = {0};
    
    r[0][0] = r[0][1] = r[1][0] = 1;
    res[0][0] = res[1][1] = 1;
    for(;b; b>>=1, r = mul(r, r)) {
        if(b&1) res = mul(res, r);
    }
    
    return res[0][1];
    
}
 
int main() {
    
    ll n; cin >> n;
 
    cout << fib(n);
    return 0;
}
