#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 3;
vector<int> seg(4*N), v;
 
void build(int i, int l, int r) {
    if(l == r) {
        seg[i] = 1;
        return ;
    }
 
    int md = l + (r-l)/2;
    build(2*i, l, md); build(2*i+1, md+1, r);
 
    seg[i] = seg[2*i] + seg[2*i+1];
 
    return ;
}
 
int query(int i, int l, int r, int x) {
    if(l == r) {
        seg[i] = 0;
        return v[l];
    }
 
    int res = 0, md = l + (r-l)/2;
    if(seg[2*i] >= x) {
        res = query(2*i, l, md, x);
    }else {
        res = query(2*i+1, md+1, r, x-seg[2*i]);
    }
 
    seg[i] = seg[2*i] + seg[2*i+1];
 
    return res;
}   
 
int main() {
 
    int n; scanf("%d", &n);
    v.resize(n+1);
    for(int i=1; i<=n; ++i) scanf("%d", &v[i]);
 
    build(1, 1, n);
    int q = n;
    while(q--) {
        int x; scanf("%d", &x);
        printf("%d ", query(1, 1, n, x));
    }
    return 0;
}
