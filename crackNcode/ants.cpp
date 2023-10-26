#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {
    int n; scanf("%d", &n);

    ll res = 0, k = 0;
    for(ll i=0; i<n; ++i) {
        ll x; scanf("%lld", &x);
        if(x == 0) res += i - k++;
    }
    printf("%lld", res);
    return 0;
}