#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;
int fw[N], n, k;

void update(int i, int v) {

    for(; i<=n; i += i&-i) {
        fw[i] += v;
    }
}

int sum(int i) {
    int s = 0;
    for(; i>=1; i -= i&-i) {
        s += fw[i];
    }

    return s;
}

int bs(int x) {

    int l = 1, r = n;
    while(l < r) {
        int md = (l+r)/2;

        if(sum(md) < x) l = md + 1;
        else r = md;
    }

    return l;
}

int main() {

    scanf("%d%d", &n, &k);

    for(int i=1; i<=n; ++i) update(i, 1);

    int p = n;
    while(p > 1) {
        int x = bs(k);
        update(x, -1);
        k--, p--;
        k = (k + x - 1) % p + 1;
    }

    printf("%d", bs(k));
    return 0;
}