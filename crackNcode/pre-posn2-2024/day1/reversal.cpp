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
int n, sz, cnt;
vector<int> a, b;
unordered_map<int, int> t;

void f(int la, int ra, int lb, int rb, bool rev) {
    if(la == ra || lb == rb) return ;

    int ma = (la+ra)/2, mb = (lb+rb)/2;
    int s = ma - la + 1;

    if(!rev) for(int i=la; i<=ma; ++i) t[a[i]] ++;
    else for(int i=ma+1; i<=ra; ++i) t[a[i]] ++;

    for(int j=mb+1; j<=rb; ++j) {
        s -= t[b[j]] == 1; 
        if(t[b[j]]) t[b[j]]--;
    }

    if(s != 0 and s != ma-la+1) {
        cout << -1;
        exit(0);
    }

    if(s == ma-la+1) for(int j=lb; j<=mb; ++j) t[b[j]] --;

    int turn = rev;
    if(s == 0) cnt ++, turn ++, rev = !rev;

    if(turn == 1) f(la, ma, mb+1, rb, rev), f(ma+1, ra, lb, mb, rev);
    else f(la, ma, lb, mb, rev), f(ma+1, ra, mb+1, rb, rev);
}

void runcase() {
    cin >> n; sz = 1<<n;
    a.resize(sz), b.resize(sz);
    for(auto &x : a) cin >> x; for(auto &x : b) cin >> x;

    f(0, sz-1, 0, sz-1, 0);

    cout << cnt;
    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}