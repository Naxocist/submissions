#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = unsigned long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 2e5 + 3;
ll ar[N];
int n;
struct node {
    ll s = 0, lz1 = 0, lz2 = 0;
} seg[4*N];
 
 
void build(int i, int l, int r) {
    if(l == r) {
        seg[i].s = ar[l];
        return ;
    }
    int m = l + (r-l)/2;
    build(2*i, l, m); build(2*i+1, m+1, r);
    seg[i].s = seg[2*i].s + seg[2*i+1].s;
}
 
void pushlz(int i, ll l, ll r) {
    if(seg[i].lz1 || seg[i].lz2) {
        // cout << i << ' ' << l << ' ' << r << endl;
        ll md = l + (r-l)/2;
        seg[i].s += seg[i].lz1*(r-l+1) + seg[i].lz2*((r-l+2)*(r-l+1)/2);
 
        if(l != r) seg[2*i].lz1 += seg[i].lz1, seg[2*i+1].lz1 += seg[i].lz1 + (md-l+1)*seg[i].lz2;
        if(l != r) seg[2*i].lz2 += seg[i].lz2, seg[2*i+1].lz2 += seg[i].lz2;
        seg[i].lz1 = 0;
        seg[i].lz2 = 0;
    }
}
 
void upd(int i, int l, int r, int x, int y) {
    pushlz(i, l, r);
    if(r < x or l > y) return ;
    if(x <= l and r <= y) {
        seg[i].lz1 += (ll)l-x;
        seg[i].lz2 ++;
        pushlz(i, l, r);
        return ;
    }
    int m = l + (r-l)/2;
    upd(2*i, l, m, x, y); upd(2*i+1, m+1, r, x, y);
    seg[i].s = seg[2*i].s + seg[2*i+1].s;
}
 
ll qry(int i, int l, int r, int x, int y) {
    pushlz(i, l, r);
    if(r < x or l > y) return 0;
    if(x <= l and r <= y) return seg[i].s;
    int m = l + (r-l)/2;
    return qry(2*i, l, m, x, y) + qry(2*i+1, m+1, r, x, y);
} 
 
 
void upd(int l, int r) { 
    upd(1, 1, n, l, r); return ;
}
 
ll qry(int l, int r) {
    return qry(1, 1, n, l, r);
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q; cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> ar[i];
    build(1, 1, n);
    while(q--) {
        int c, a, b; cin >> c >> a >> b;
        if(c == 1) upd(a, b);
        else cout << qry(a, b) << '\n';
        // div()
        // for(int i=1; i<=n; ++i) cout << qry(i, i) << ' ';
        // cout << '\n';
    }
    return 0;
}