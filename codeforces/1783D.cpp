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
const int N = 303, mod = 998244353, z = 1e5;

void runcase() {
    int n; cin >> n;
    vector<int> v(n+1); for(int i=1; i<=n; ++i) cin >> v[i];

    vector<int> dp(3*z + 1);
    dp[z + v[2]] = 1;
    for(int i=1; i<=n-2; ++i) {
        vector<int> nxt(3*z + 1);
        for(int x=-z; x<=z; ++x) {
            nxt[z+v[i+2]+x] += dp[z+x], nxt[z+v[i+2]+x]%=mod;
            if(x!=0){ 
                nxt[z+v[i+2]-x] += dp[z+x], nxt[z+v[i+2]-x]%=mod;
            }
        }
        dp = nxt;
    }

    int res = 0;
    for(int i=0; i<=2*z; ++i) res += dp[i], res%=mod;
    cout << res << ln;
    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}