#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {

    ll n = 100L;

    ll x = (n * (n+1))/2;
    x*=x;

    ll y = n*(2*n + 1)*(n + 1)/6;

    printf("%lld", x - y);
    return 0;
}