#include <bits/stdc++.h>
#include <random>
#include <ctime>
using namespace std;
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

mt19937 mt(time(nullptr));

struct node {
    int pr, val, sz;
    node *l, *r;
    node(int v) : val(v), pr(mt()), sz(1), l(NULL), r(NULL) {}
};

int sz(node *t) {
    if(t) return t->sz;
    return 0;
}

void upd_sz(node *t) {
    if(t) t->sz = 1 + sz(t->l) + sz(t->r);
}

void split(node *t, node *&l, node *&r, int v) {
    if(!t) return void(l = r = NULL);

    if(t->val <= v) split(t->r, t->r, r, v), l = t;
    else split(t->l, l, t->l, v), r = t;

    upd_sz(t);
}

void merge(node *&t, node *l, node *r) {
    if(!l || !r) return void(t = l ? l : r);
    if(l->pr > r->pr) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    upd_sz(t);
}


void inOrder(node *t) {
    if(!t) return ;
    inOrder(t->l);
    cout << t->val << ' ';
    inOrder(t->r);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    srand(time(NULL));
    node *root = NULL;
    for(int i=1; i<=5; ++i) merge(root, root, new node(i));
    inOrder(root);
    node *a, *b;
    split(root, a, b, 3);
    
    cout << '\n';

    merge(root, a, b);
    inOrder(root);

    return 0;
}
