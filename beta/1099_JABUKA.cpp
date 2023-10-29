#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m; scanf("%d%d", &n, &m);

    int k = __gcd(n, m);

    for(int i=1; i<=k; ++i) {
        if(k % i) continue ;
        printf("%d %d %d\n", i, n/i, m/i);
    }
    return 0;
}