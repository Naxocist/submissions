#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
 
const int N = 2e5 + 3;
ll ar[N], seg[4*N], lazy[4*N];
 
 
void build(int i, int l, int r) {
    if(l == r) {
        seg[i] = ar[l]; return ;
    }
 
    int md = (l+r)/2;
 
    build(2*i+1, l, md); build(2*i+2, md+1, r);
 
    seg[i] = seg[2*i+1] + seg[2*i+2];
 
}
 
 
void update(int i, int l, int r, int u, int v, ll val) {
 
    int a = 2*i+1, b = 2*i+2;
 
    if(lazy[i] != 0) {
        seg[i] += (r-l+1) * lazy[i];
 
        if(l != r) {
            lazy[a] += lazy[i];
            lazy[b] += lazy[i];
        }
        lazy[i] = 0;
    }
 
    if(r < u || l > v) return ;
 
    if(l >= u && r <= v) {
        seg[i] += (r-l+1) * val;
        if(l != r) {
            lazy[a] += val;
            lazy[b] += val;
        }
        return ;
    }
 
    int md = (l+r)/2;
 
    update(a, l, md, u, v, val);
    update(b, md+1, r, u, v, val);
 
    seg[i] = seg[a] + seg[b];
    return ;
}
 
 
ll query(int i, int l, int r, int idx) {
 
    int a = 2*i+1, b = 2*i+2;
 
    if(lazy[i]) {
        seg[i] += (r-l+1) * lazy[i];
 
        if(l != r) {
            lazy[a] += lazy[i];
            lazy[b] += lazy[i];
        }
        lazy[i] = 0;
    }
 
    if(l == r) {
        return seg[i];
    }
 
    int md = (l+r)/2;
 
    if(idx <= md) return query(a, l, md, idx);
    return query(b, md+1, r, idx);
 
}
 
 
int main() {
 
    int n, q; scanf("%d%d", &n, &q);
    for(int i=0; i<n; ++i) scanf("%lld", &ar[i]);
 
    build(0, 0, n-1);
 
    while(q--) {
        int c, l, r; ll val;
        scanf("%d", &c);
        
        if(c == 1) {
            
            scanf("%d%d%lld", &l, &r, &val);  l--; r--;
            
            update(0, 0, n-1, l, r, val);
        }else {
            scanf("%d", &l); l--;
            printf("%lld\n", query(0, 0, n-1, l));
        }
 
        
    }
    return 0;
}
 
/*
8 100
1 2 3 4 5 6 7 8
 
 
8 900
7 6 4 6 2 9 4 8
1 8 8 10
2 1
2 2
2 3
2 4
2 5
*/
