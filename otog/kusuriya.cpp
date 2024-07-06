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
const ll INF = 2e18;
int n, m;

void runcase() {
    cin >> n >> m;
    int T=1<<m;
    vector<ll> dp(T, INF);

    for(int i=0; i<n; ++i) {
        int x; cin >> x;
        int mask = 0;
        for(int j=0; j<m; ++j) {
            int t; cin >> t; mask |= t<<j;
        }
        amin(dp[mask], x);
    }
    
    for(int i=T-1; i>=0; --i) {
        for(int j=0; j<m; ++j) if(i&(1<<j)) amin(dp[i^(1<<j)], dp[i]);
    }

    for(int i=0; i<T; ++i) {
        int t = i;
        while(t) {
            amin(dp[i], dp[i^t]+dp[t]);
            t=(t-1)&i;
        }
    }

    cout << dp[T-1];
    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}