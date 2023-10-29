#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

using ll = long long int;
ll ar[N];

int main() {

    int n, k; scanf("%d%d", &n, &k);

    ll s = 2e9;
    for(int i=0; i<n; ++i) scanf("%lld", &ar[i]), s = min(s, ar[i]);

    ll res = n;
    for(int i=0; i<n; ++i) {
        if(ar[i] == s) continue ;

        if(ar[i]*(k-1) >= s*k) res--;
    }
    printf("%lld", res);
    return 0;
}