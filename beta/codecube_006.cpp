#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 3;
// ll ar[N], odd[N], even[N];
ll a[N], b[N], c[N];

int main() {
    int n; scanf("%d", &n);

    for(int i=1; i<=n; ++i) {
        int k; scanf("%d", &k);

        if(i & 1) k = -k;

        a[i] = a[i-1] + k; // no zero
        b[i] = min(b[i-1] - k, a[i-1] - k); // one zero
        c[i] = min(c[i-1] + k, b[i-1] + k); // two zero

    }
    printf("%lld", min({a[n], b[n], c[n]})) ;
    // int n; scanf("%d", &n);
    // for(int i=1; i<=n; ++i) {
    //     scanf("%lld", &ar[i]);
    //     if(i & 1) odd[i] += ar[i];
    //     else even[i] += ar[i];

    //     odd[i] += odd[i-1];
    //     even[i] += even[i-1];
    // }

    // ll res = even[n] - odd[n];
    
    // for(int i=1; i<=n; ++i) {
    //     ll o = odd[i-1] + even[n] - even[i-1];
    //     ll e = even[i-1] + odd[n] - odd[i-1];
    //     res = min(res, e - o);
    // }

    
    // for(int i=1; i<=n; ++i) {
    //     for(int j=i+1; j<=n; ++j) {
    //         ll o = odd[i-1] + even[j-1] - even[i-1] + odd[n] - odd[j-1];
    //         ll e = even[i-1] + odd[j-1] - odd[i-1] + even[n] - even[j-1];
    //         res = min(res, e - o);
    //     }
    // }
    // printf("%lld", res);
    return 0 ;
}