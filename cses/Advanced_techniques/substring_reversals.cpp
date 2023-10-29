#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
 
struct node {
    int pr, sz, rev;
    char val;
    node *l, *r;
    node(char v) : rev(0), val(v), pr(rand()), sz(1), l(NULL), r(NULL) {}
};
 
int sz(node *t) {
   return (t ? t->sz : 0);
}
 
void upd_sz(node *t) {
    if(t) t->sz = 1 + sz(t->l) + sz(t->r);
}
 
void push(node *t) {
    if(!t) return ;
    if(t->rev) {
        t->rev = 0;
        swap(t->l, t->r);
        if(t->l) t->l->rev ^= 1;
        if(t->r) t->r->rev ^= 1;
    }
}
 
void split(node *t, node *&l, node *&r, int v) {
    if(!t) return void(l = r = NULL);
    push(t);
    if(sz(t->l) < v) split(t->r, t->r, r, v-sz(t->l)-1), l = t;
    else split(t->l, l, t->l, v), r = t;
    upd_sz(t);
}
 
void merge(node *&t, node *l, node *r) {
    if(!l || !r) {
        return void(t = l ? l : r);
    }
    push(l); push(r);
 
    if(l->pr > r->pr) {
        merge(l->r, l->r, r);
        t = l;
    }else {
        merge(r->l, l, r->l);
        t = r;
    }
    upd_sz(t);
}
 
 
void inOrder(node *t) {
    if(!t) return ;
    push(t);
    inOrder(t->l);
    cout << t->val;
    inOrder(t->r);
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    srand(time(NULL));
    node *root = NULL;
    int n, q; cin >> n >> q;
    string s; cin >> s;
    for(char c : s) 
        merge(root, root, new node(c));
 
    while(q--) {
        int l, r; cin >> l >> r;
        node *a, *b, *c, *d;
        split(root, a, b, l-1);
        split(b, c, d, r-l+1);
        c->rev ^= 1;
        merge(b, c, d);
        merge(root, a, b);
    }
    inOrder(root);
    return 0;
}