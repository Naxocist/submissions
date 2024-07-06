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
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const ll INF = 2e9;
const int N = 1e5 + 3;
ll qsv[N], qsw[N], w[N], v[N];

ll bin(int a, int b, int p) {
    // dbg(a, b);

    ll l = 1, r = 1e8, res = 0;
    while(l <= r) {
        ll md = l + (r-l)/2;

        int t = 0, cnt = 1;
        for(int i=0; i<p; ++i) {
            auto u = upper_bound(qsw+a+t, qsw+b+1, md+qsw[a+t-1]) - qsw - a;
            // dbg(u);
            if(u < b-a+1) t = u, cnt++;
            else break ;

            if(cnt > p) break ;
        }

        // dbg(md, cnt);

        if(cnt <= p) r = md - 1, res = md;
        else l = md + 1;
    }

    return res;
}

void runcase() {
    int n, m, p; cin >> n >> m >> p;
    for(int i=1; i<=n; ++i) cin >> v[i] >> w[i], qsv[i] = qsv[i-1] + v[i], qsw[i] = qsw[i-1] + w[i];

    // int ttt = bin(1, m, p);
    // dbg(ttt);
    
    ll R = LLONG_MIN;
    for(int i=m; i<=n; ++i) {
        ll B = bin(i-m+1, i, p);
        ll r = qsv[i] - qsv[i-m] - 1LL*B*B;
        amax(R, r);
    }
    cout << R;

    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}