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
const int N = 23;
double ar[N][N];

void runcase() {
    int n; cin >> n;
    for(int j=1; j<=n; ++j) {
        for(int i=0; i<n; ++i) {
            cin >> ar[i][j]; ar[i][j] /= 100;
        }
    }
    int K = 1<<n;
    vector<double> dp(K);
    dp[0] = 1;
    for(int i=1; i<K; ++i) {
        for(int j=0; j<n; ++j) {
            if(i&(1<<j)) amax(dp[i], dp[i^(1<<j)] * ar[j][__builtin_popcount(i)]);
        }
    }
    cout << fixed << setprecision(12) << dp[K-1]*100;
    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}