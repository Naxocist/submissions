#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define all(x) x.begin(), x.end()
const int N = 1e6 + 3;
using ll = long long;
unordered_map<int, int> cnt;
int v[N], a[N], b[N];
vector<int> s[4*N];

void build(int i, int l, int r) {
    if(l == r) {
        s[i].pb(b[l]); return ;
    }
    int m = l+(r-l)/2;
    build(2*i, l, m); build(2*i+1, m+1, r);
    merge(all(s[2*i]), all(s[2*i+1]), back_inserter(s[i]));
}

ll qry(int i, int l, int r, int L, int R, int v) {
    if(R < l || r < L) return 0LL;
    if(L <= l and r <= R) {
        return lower_bound(all(s[i]), v) - s[i].begin();;
    }
    int m = l+(r-l)/2;
    return qry(2*i, l, m, L, R, v) + qry(2*i+1, m+1, r, L, R, v);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;

    for(int i=1; i<=n; ++i) {
        cin >> v[i];
        a[i] = ++cnt[v[i]];
    }

    cnt.clear();
    for(int i=n; i>=1; --i) b[i] = ++cnt[v[i]];

    build(1, 1, n);
    ll res = 0;
    for(int i=1; i<n; ++i) {
        res += qry(1, 1, n, i+1, n, a[i]);
    }
    cout << res;
}