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
using T = tuple<int, int, int>;

const int N = 1e5 + 3;
int seg[4*N];
vector<int> v;

struct node {
    int mx, pref, suf;
    node *l, *r;
    node(int x) : mx(x), pref(x), suf(x), l(nullptr), r(nullptr) {}
    node(node *a, node *b, int al, int ar, int bl, int br) {
        l = a, r = b;
        pref = a->pref;
        suf = b->suf;
        
        if(a->pref == ar-al+1) pref = a->pref + b->pref;
        if(b->suf == br-bl+1) suf = b->suf + a->suf;

        mx = max({pref, suf, a->suf + b->pref});
    }
    node(node *a) : mx(a->mx), pref(a->pref), suf(a->suf) {}
} *roots[N];


node* build(int l, int r) {
    if(l == r) return new node(v[l]);
    int md = l + (r-l)/2;
    node *t = new node(build(l, md), build(md+1, r), l, md, md+1, r);
    // cout << l << ' ' << r << ' ' << t->mx << endl;
    return t; 
}

node *qry(node *root, int l, int r, int x, int y) {
    if(r < x or l > y) return new node(0);
    if(x <= l and r <= y) return root;
    int md = l + (r-l)/2;
    return new node(qry(root->l, l, md, x, y), qry(root->r, md+1, r, x, y), l, md, md+1, r);
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    v.resize(n+1);
    for(int i=1; i<=n; ++i) cin >> v[i];
    
    int cnt = 0;
    roots[cnt++] = build(1, n);   

    node *res = qry(roots[cnt-1], 1, n, 1, n);
    cout << max({res->mx, res->pref, res->suf});
    return 0;
}
