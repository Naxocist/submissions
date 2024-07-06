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
const int N = 5e3 + 3;
int dp[N][8][8][8][8];
void runcase() {
    int n; cin >> n;
    vector<int> v(9);
    for(int i=1; i<=8; ++i) {
        cin >> v[i];
    }

    int res = 0;
    for(int q=1; q<=n; ++q) {
        int x; cin >> x;
        for(int i=1; i<=8; ++i) { 
            for(int j=1; j<=8; ++j) {
                if(i == j) continue ;
                for(int k=1; k<=8; ++k) {
                    if(i == k || j == k) continue ;
                    for(int l=1; l<=8; ++l) {
                        if(i == l || j == l || k == l) continue ;
                        for(int p=1; p<=8; ++p) {
                            if(p == i || p == j || p == k || p == l) continue ;
                            amax(dp[q][p][l][k][j], dp[q-1][l][k][j][i] + abs(v[p] - x));
                            if(q == n) amax(res, dp[q][p][l][k][j]);
                        }
                    }
                }
            }
        }
    }
    cout << res;
    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}