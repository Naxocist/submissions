#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {

    int n; scanf("%d", &n);
    vector<ll> v(n);
    for(int i=0; i<n; ++i) scanf("%lld", &v[i]);

    sort(v.begin(), v.end());

    ll res = 0;
    for(int i=0; i<n/2; ++i) {
        res += v[n-i-1] - v[i];
    }

    printf("%lld", res);

    return 0;
}