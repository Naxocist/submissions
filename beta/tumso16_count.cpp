#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {

    int q; scanf("%d", &q);
    while(q--) {
        ll x; scanf("%lld", &x);
        ll t = 1 << (63 - __builtin_clzll(x));
        x = 2*(x - t) + 1;
        printf("%lld\n", x);
    }
    return 0;
}