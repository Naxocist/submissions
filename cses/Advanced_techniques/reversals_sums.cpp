#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
 
struct node {
    ll pr, sz, rev, key, sum;
    node *l, *r;
    node(int v) : sum(v), rev(0), key(v), pr(rand()), sz(1), l(NULL), r(NULL) {}
} *root = NULL;
 
int sz(node *t) {
   return (t ? t->sz : 0);
}
 
ll sm(node *t) {
    return (t ? t->sum : 0);
}
 
void upd(node *&t) {
    if(t) {
        t->sz = 1 + sz(t->l) + sz(t->r);
        t->sum = t->key + sm(t->l) + sm(t->r);
    }
}
 
void push(node *&t) {
    if(!t) return ;
    if(t->rev) {
        t->rev = 0;
        swap(t->l, t->r);
        if(t->l) t->l->rev ^= 1;
        if(t->r) t->r->rev ^= 1;
    }
}
 
void split(node *t, node *&l, node *&r, int v) {
    push(t);
    if(!t) return void(l = r = NULL);
    
    if(sz(t->l) < v) split(t->r, t->r, r, v-sz(t->l)-1), l = t;
    else split(t->l, l, t->l, v), r = t;
    upd(t);
}
 
void merge(node *&t, node *l, node *r) {
    push(l); push(r);
    if(!l || !r) {
        return void(t = l ? l : r);
    }
    
 
    if(l->pr > r->pr) {
        merge(l->r, l->r, r);
        t = l;
    }else {
        merge(r->l, l, r->l);
        t = r;
    }
    upd(t);
}
 
 
void print(node *t) {
    if(!t) return ;
    print(t->l);
    cout << t->key << ' ' << t->sum << '\n';
    print(t->r);
}
 
 
void frev(int l, int r) {
    // cout << l << r;
    node *a, *b, *c, *d;
    split(root, a, b, r);
    split(a, c, d, l-1);
    d->rev ^= 1;
    merge(root, c, d);
    merge(root, root, b);
    // inOrder(root);cout << endl;
    // push(root);
}
 
void fsum(int l, int r) {
    node *a, *b, *c, *d;
    split(root, a, b, r);
    split(a, c, d, l-1);
    cout << d->sum << '\n';
    merge(root, c, d);
    merge(root, root, b);
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    srand(time(NULL));
    
    int n, q; cin >> n >> q;
    for(int i=1; i<=n; ++i) {
        int x; cin >> x;
        merge(root, root, new node(x));
    }
 
    // inOrder(root);
    while(q--) {
        int k, l, r; cin >> k >> l >> r;
        if(k == 1) frev(l, r);
        else fsum(l, r);
        // print(root);
        // cout << endl;
    }
    return 0;
}