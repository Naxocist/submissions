#include <bits/stdc++.h>
using namespace std;


using ll = long long int;
const int N = 1e5 + 3;
ll ar[N], tmp[N], s = 0;

void f(int l, int r) {
    if(l >= r) return ;

    int md = l + (r - l)/2;
    f(l,md); f(md+1, r);

    int x = l, y = md+1, i = l;
    ll t = 0;
    for(int j=y; j<=r; ++j) t += ar[j];

    while(x <= md && y <= r) {
        if(ar[x] > ar[y]) s += t + ar[x]*(r-y+1), tmp[i++] = ar[x++];
        else t -= ar[y], tmp[i++] = ar[y++];
    }

    while(x <= md) tmp[i++] = ar[x++];
    while(y <= r) tmp[i++] = ar[y++];

    for(int j=l; j<=r; ++j) ar[j] = tmp[j];
}

int main() {

    int n; scanf("%d", &n);

    for(int i=1; i<=n; ++i) {
        int x,y; scanf("%d%d", &x, &y); ar[y] = x;
    }

    f(1, n);
    printf("%lld", s);
    return 0;
}