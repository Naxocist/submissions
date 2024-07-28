#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

template<typename S, typename T> S amax(S &a, const T &b) { if(b > a) a = b; return a; }
template<typename S, typename T> S amin(S &a, const T &b) { if(b < a) a = b; return a; }

#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define pb emplace_back
#define sz(x) (int) (x).size()
#define ln '\n'
using ll = long long;
using pi = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
const ll INF = 2e9;
vector<int> v;
int sz = 0;

struct node {
    int val;
    node *left=nullptr, *right=nullptr, *par;
};


node *create(int val) {
    node *N = new node;
    N->val = val;
    return N;
}

map<int, node*> mp;


void in(node *crr) {
    if(crr == nullptr) {
        cout << -1 << ' '; return ;
    }
    
    if(crr->left == nullptr and crr->right == nullptr) {
        cout << crr->val << ' '; return ;
    }

    in(crr->left);
    cout << crr->val << ' ';
    in(crr->right);
    return ;
}

void pre(node *crr) {
    if(crr == nullptr) {
        cout << -1 << ' '; return ;
    }
    
    if(crr->left == nullptr and crr->right == nullptr) {
        cout << crr->val << ' '; return ;
    }

    cout << crr->val << ' ';
    pre(crr->left);
    pre(crr->right);
    return ;
}

void post(node *crr) {
    if(crr == nullptr) {
        cout << -1 << ' '; return ;
    }
    
    if(crr->left == nullptr and crr->right == nullptr) {
        cout << crr->val << ' '; return ;
    }

    post(crr->left);
    post(crr->right);
    cout << crr->val << ' ';
    return ;
}

node *build(int i) {
    if(i >= sz or v[i] == -1) return nullptr;
    node *N = create(v[i]);

    N->left = build(2*i);
    if(N->left != nullptr) N->left->par = N;

    N->right = build(2*i+1);
    if(N->right != nullptr) N->right->par = N;

    return N;
}

int mx(node *head) {
    if(head == nullptr) return 0;
    return max({mx(head->left), mx(head->right), head->val});
}

int leaf(node *head) {
    if(head == nullptr) return 0;
    if(head->left == nullptr and head->right == nullptr) return 1;
    return leaf(head->left) + leaf(head->right);
}


node *findp(node *head, int x) {
    if(head == nullptr) return head; 

    if(head->left != nullptr and head->left->val == x) {
        return head;
    }

    if(head->right != nullptr and head->right->val == x) {
        return head;
    }

    node *l = findp(head->left, x), *r = findp(head->right, x);
    if(l != nullptr) return l;
    return r;
}

node *sib(node *head, int x) {
    if(head == nullptr) return head;

    if(head->left != nullptr and head->left->val == x) {
        return head->right;
    }

    if(head->right != nullptr and head->right->val == x) {
        return head->left;
    }

    node *l = sib(head->left, x), *r = sib(head->right, x);
    if(l != nullptr) return l;
    return r;
}


void runcase() {

    int n; cin >> n;
    sz = 1<<n;
    v.resize(sz);
    for(int i=1; i<sz; ++i) {
        cin >> v[i];
    }

    node *head = build(1);

    int q; cin >> q;
    while(q--) {
        char c; cin >> c;
        
        if(c == 'i') { in(head); cout << ln; }

        if(c == 'a') { pre(head); cout << ln; }

        if(c == 'b') { post(head); cout << ln; }

        if(c == 'm') { cout << mx(head) << ln; }

        if(c == 'l') { cout << leaf(head) << ln; }
        
        if(c == 'p') { 
            int x; cin >> x;
            node *f = findp(head, x);
            if(f == nullptr) cout << -1 << ln;
            else cout << f->val << ln;
        }

        if(c == 's') {
            int x; cin >> x;
            node *s = sib(head, x);
            if(s == nullptr) cout << -1 << ln;
            else cout << s->val << '\n';
        }
    }

    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}
