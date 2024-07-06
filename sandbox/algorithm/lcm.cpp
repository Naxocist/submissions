#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
int main() {

    lli n, x, y; scanf("%lld%lld", &n, &x);
    while(--n) {
        scanf("%lld", &y);

        x = x * y / __gcd(x, y);
    }

    cout << x;

    return 0;
}
