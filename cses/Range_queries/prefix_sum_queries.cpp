#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
 
struct node {
    ll pref = 0, sum = 0;
};
 
const int N = 2e5 + 3;
vector<node> seg(4*N);
vector<ll> v;
node no;
 
node un(node l, node r) {
   node t;
   t.sum = l.sum + r.sum;
   t.pref = max(l.pref, l.sum + r.pref);
 
   return t;  
}
 
 
void build(int i, int l, int r) {
    if(l == r) {
        seg[i].pref = seg[i].sum = v[l];
        return ;
    }
 
    int md = (l+r)/2;
    build(2*i, l, md); build(2*i+1, md+1, r);
 
    seg[i] = un(seg[2*i], seg[2*i+1]);
    return ;
}
 
void update(int i, int l, int r, int x, int val) {
    if(l == r) {
        seg[i].pref = seg[i].sum = (ll)val; 
        return ;
    }
 
    int md = (l+r)/2;
    if(x <= md) update(2*i, l, md, x, val);
    else update(2*i+1, md+1, r, x, val);
 
    seg[i] = un(seg[2*i], seg[2*i+1]);
    return ;
 
}
 
node query(int i, int l, int r, int tl, int tr) {
    if(r < tl || l > tr) return no;
 
    if(tl <= l && r <= tr) return seg[i];
 
    int md = (l+r)/2;
    return un(query(2*i, l, md, tl, tr), query(2*i+1, md+1, r, tl ,tr));
}
 
int main() {
 
    int n, q; scanf("%d%d", &n, &q);
 
    v.resize(n+1);
    for(int i=1; i<=n; ++i) scanf("%lld", &v[i]);
    build(1, 1, n);
 
    while(q--) {
        int c, x, y; scanf("%d%d%d", &c, &x, &y);
 
        if(c == 1) {
            update(1, 1, n, x, y);
        }
        else {
            node res = query(1, 1, n, x, y);
            printf("%lld\n", max({0ll, res.pref, res.sum}));
        }
    }
    return 0;
}
