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
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int, int>;

const int N = 1e5 + 3;

struct node {
    int mx, pref, suf, len;
    node *l, *r;
    node(int x) : len(1), mx(x), pref(x), suf(x), l(nullptr), r(nullptr) {}
    node(node *a, node *b) {
        l = a, r = b;
        pref = a->pref;
        suf = b->suf;
        
        if(a->pref == a->len) pref = a->pref + b->pref;
        if(b->suf == b->len) suf = b->suf + a->suf;

        mx = max({a->suf + b->pref, a->mx, b->mx});
        len = a->len + b->len;
    }
    node(node *a) : len(a->len), mx(a->mx), pref(a->pref), suf(a->suf) {}
} *roots[N];

T un(T a, T b) {
    int mx3, p3, s3, l3, mx1, p1, s1, l1, mx2, p2, s2, l2;
    tie(mx1, p1, s1, l1) = a, tie(mx2, p2, s2, l2) = b;
    p3 = p1;
    s3 = s2;
    if(p1 == l1) p3 = p1 + p2;
    if(s2 == l2) s3 = s2 + s1;

    mx3 = max({s1 + p2, mx1, mx2});
    l3 = l1 + l2;
    return T(mx3, p3, s3, l3);
}

node* build(int l, int r) {
    if(l == r) return new node(0);
    int md = l + (r-l)/2;
    node *t = new node(build(l, md), build(md+1, r));
    return t; 
}


node *upd(node *root, int l, int r, int &x) {
    if(l == r) return new node(1);
    int md = l + (r-l)/2;
    if(x <= md) return new node(upd(root->l, l, md, x), root->r);
    return new node(root->l, upd(root->r, md+1, r, x));
}


T qry(node *root, int l, int r, int x, int y) {
    if(r < x or l > y) return T(0, 0, 0, 1);
    if(x <= l and r <= y) return T(root->mx, root->pref, root->suf, root->len);
    
    int md = l + (r-l)/2;
    return un(qry(root->l, l, md, x, y), qry(root->r, md+1, r, x, y));
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pi> h(n);
    for(int i=0; i<n; ++i) {
        cin >> h[i].first;
        h[i].second = i+1;
    }
    sort(allrev(h));
    map<int, int> get_h;

    int cnt = 0;
    roots[cnt] = build(1, n);

    for(auto e : h) {
        int H, x; tie(H, x) = e;
        roots[cnt+1] = upd(roots[cnt], 1, n, x);
        cnt ++;
        get_h[cnt] = H;
    }
    // cout << "HI\n";
    // for(int i=1; i<=n; ++i) cout << qry(roots[5], 1, n, i, i)->mx << ' ';
    //     cout << endl;

    // T t = qry(roots[3], 1, n, 1, n);
    // int mx = max({get<0>(t), get<1>(t), get<2>(t)});
    // cout << mx;
    int q; cin >> q;
    while(q--) {
        int l, r, w; cin >> l >> r >> w;
        int lw = 1, hi = cnt, res = 1;
        while(lw <= hi) {
            int md = lw + (hi-lw)/2;
            T t = qry(roots[md], 1, n, l, r);
            int mx = max({get<0>(t), get<1>(t), get<2>(t)});
            if(mx >= w) hi = md - 1, res = md;
            else lw = md + 1;
        }

        cout << get_h[res] << '\n';
    }
    return 0;
}