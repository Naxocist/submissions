#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
const int N = 2e5 + 3;
vector<int> seg(4*N), v, x;
int n, m;
 
void build(int i, int l, int r) {
    if(l == r) {
        seg[i] = v[l];
        return ;
    }
    int md = l + (r - l)/2;
    build(2*i, l, md);
    build(2*i+1, md+1, r);
 
    seg[i] = max(seg[2*i], seg[2*i+1]);
    return ;
}
 
int query(int i, int l, int r, int x) {
 
    if(l == r && seg[i] >= x) {
        seg[i] -= x;
        return l;
    }
    int res = 0, md = l + (r-l)/2;
    if(seg[2*i] >= x) {
        res = query(2*i, l, md, x);
    }else if(seg[2*i+1] >= x) {
        res = query(2*i+1, md+1, r, x);
    }
 
    seg[i] = max(seg[2*i], seg[2*i+1]);
 
    return res;
}  
 
int main() {
    int n, q;scanf("%d%d", &n, &q);
    v.resize(n+1);
    for(int i=1; i<=n; ++i) scanf("%lld", &v[i]);
 
    build(1, 1, n);
 
    while(q--) {
        int x; scanf("%d", &x);
 
        printf("%d ", query(1, 1, n, x));
    }
    return 0;
}
/*
10 10
1 1 1 1 1 1 1 1 1 10000
2 2 2 2 2 2 2 2 2 2
*/
