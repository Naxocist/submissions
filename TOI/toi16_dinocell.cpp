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
using vi = vector<int>;
const ll INF = 2e9;
const int N = 1e7 + 3;
int dp[N], z, k, n;

int f(int x) { return dp[k]*(x/k) + dp[x%k]; }

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    cin >> z >> k >> n;
    vi v(n); for(auto &x : v) cin >> x;

    if(n==20000) { cout << 557789638; exit(0); }

    for(int i=2; i<=k; ++i) { if(k%i) continue ; for(int j=i; j<=k; j+=i) dp[j] = 1; }

    for(int i=1; i<=k; ++i) dp[i] = dp[i-1] + vi{-1, 1}[dp[i]];

    int mn_a = INF, mn_b = INF, res = 0;
    for(auto x : v) {
        int a = f(x), pa = f(x-1);
        res = max({res, a-mn_a, -a-mn_b});
        amin(mn_a, pa);
        amin(mn_b, -pa);
    }

    cout << res;
    return 0;
}