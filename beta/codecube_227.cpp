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
const ll N = 1e5 + 3, K = 103, mod = 1e9 + 7;
ll dp[N][K], res[K];

void add(ll &x, ll y) { x += y, x %= mod; }
void sub(ll &x, ll y) { x -= y, x %= mod, x += mod, x %= mod; }

void runcase() {
    int n, q; cin >> n >> q;

    dp[0][0] = 1;
    for(int i=1; i<=n; ++i) {
        int x; cin >> x;
        for(int j=0; j<K; ++j) {
            add(dp[i][j], dp[i-1][j]);
            if(j >= x) add(dp[i][j], dp[i-1][j-x]);
        }
    }

    while(q--) {
        int l, r, k; cin >> l >> r >> k;
        for(int i=0; i<=k; ++i) {
            res[i] = dp[r][i];
            for(int j=0; j<i; ++j) sub(res[i], res[j]*dp[l-1][i-j]);
        }
        cout << res[k] << ln;
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