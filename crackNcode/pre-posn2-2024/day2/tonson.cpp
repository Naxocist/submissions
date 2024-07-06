#include <bits/stdc++.h>
using namespace std;

template<typename S, typename T> S amax(S &a, const T &b) { if(b > a) a = b; return a; }
template<typename S, typename T> S amin(S &a, const T &b) { if(b < a) a = b; return a; }

#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define pb emplace_back
#define sz(x) (int) (x).size()
using ll = long long;
const ll INF = 2e9;

void runcase() {
    int n; cin >> n;
    // cout << n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];

    vector<int> t;
    for(int i=0; i<n; ++i) if(a[i] <= b[i]) t.pb(b[i]-a[i]);

    vector<int> lis;
    for(int i=sz(t)-1; i>=0; --i) {
        int tt = t[i];
        auto x = upper_bound(all(lis), tt);
        if(x == lis.end()) lis.pb(tt);
        else *x = tt;
    }

    cout << lis.size();
    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}