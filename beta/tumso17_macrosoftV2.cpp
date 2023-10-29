#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int N = 1e5 + 3;
ll A[N], B[N], C[N], dA[N], dB[N], dC[N];

int main() {

    int n; scanf("%d", &n);

    dB[1] = dC[2] = 2e18;
    for(int i=1; i<=n; ++i) scanf("%lld", &A[i]);
    for(int i=1; i<=n; ++i) scanf("%lld", &B[i]);
    for(int i=1; i<=n; ++i) scanf("%lld", &C[i]);
    for(int i=1; i<=n; ++i) dA[i] = dA[i-1] + A[i];
    for(int i=2; i<=n; ++i) dB[i] = min(dB[i-1] + B[i], dA[i-1] + B[i]);
    for(int i=3; i<=n; ++i) dC[i] = min(dC[i-1] + C[i], dB[i-1] + C[i]);

    printf("%lld", dC[n]);
    return 0;
}