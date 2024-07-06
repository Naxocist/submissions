#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
const int N = 3e5 + 3;
int seg[4*N], l, r;

int q(int i, int low, int high) {
    if(high < l || r < low) return INT_MIN;

    if(l <= low && high <= r) return seg[i];

    int md = low + (high - low)/2;
    
    return max(q(2*i, low, md), q(2*i+1, md+1, high));
}

void update(int i, int low, int high) {
    if(low == high) {
        seg[i] = r;
        return ;
    }

    int md = low + (high - low)/2;
    if(l <= md) update(2*i, low, md);
    else update(2*i+1, md+1, high);

    seg[i] = max(seg[2*i], seg[2*i+1]);

    return ;
}


int main() {
    int n, m; scanf("%d%d", &n, &m);

    while(m--) {
        char c; scanf(" %c", &c);
        scanf("%d%d", &l, &r);
        if(c == 'U') {
            update(1, 1, n);
        }else {
            printf("%d\n", q(1, 1, n));
        }
    }
    return 0;
}
