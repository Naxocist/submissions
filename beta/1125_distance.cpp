#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {

    int n; scanf("%d", &n);
    vector<int> x(n), y(n);
    for(int i=0; i<n; ++i) scanf("%d %d", &x[i], &y[i]);
    sort(x.begin(), x.end()); sort(y.begin(), y.end());

    ll res = 0;
    for(int i=1; i<n; ++i) {
        res += 1LL * (n - i) * i * abs(x[i] - x[i-1]);
        res += 1LL * (n - i) * i * abs(y[i] - y[i-1]);
    }

    

    printf("%lld", res);
    return 0;
}