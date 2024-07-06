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

void runcase() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string res(n, '.');


    int g = -k-1, h = -k-1, cnt = 0;
    for(int i=0; i<n; ++i) {
        if(s[i] == 'G' and i-g > k) {
            cnt ++;
            g = min(i+k, n-1);
            if(res[g] != '.') g--;
            res[g] = 'G';
        } else if(s[i] == 'H' and i-h > k) {
            cnt ++;
            h = min(i+k, n-1);
            if(res[h] != '.') h--;
            res[h] = 'H';
        }
    }
    
    cout << cnt << ln << res << ln;
    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    cin >> TC; 
    while(TC--) runcase();
    return 0;
}