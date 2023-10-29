#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {

    ll x; scanf("%lld", &x);

    ll l = 0, r = 1e18;

    while(l < r) {
        ll md = l + (r - l)/2;
        ll y = md/7;
        if(y*23 + (y/12)*98 >= x) r = md;
        else l = md + 1;
    }

    printf("%lld", r);
    return 0;
}