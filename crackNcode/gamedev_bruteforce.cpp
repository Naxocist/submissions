#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {
    
    int n; scanf("%d", &n);
    
    vector<ll> v(n+1), qs(n+1, 0);
    
    for(int i=1; i<=n; ++i) {
        scanf("%lld", &v[i]);
        qs[i] = qs[i-1] + v[i];
        
    }
    
    ll res = 0;
    int a, b;
    for(int l=1; l<=n; ++l) {
        for(int r=l+1; r<=n; ++r) {
            int k = r - l;
            if(v[r]*k - qs[r-1] + qs[l-1] > res) {
                res = v[r]*k - qs[r-1] + qs[l-1];
                a = l, b = r;
            }
        }
    }
    
    printf("%lld\n", res);
    printf("%d %d", a, b);
    return 0;
}