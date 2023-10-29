#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 3;
int ar[N];
 
int main() {
    int n, q; scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) scanf("%d", &ar[i]), ar[i] ^= ar[i-1];
 
    while(q--) {
        int l, r; scanf("%d%d", &l, &r);
 
        printf("%d\n", ar[r]^ar[l-1]);
    }
 
    return 0;
}
