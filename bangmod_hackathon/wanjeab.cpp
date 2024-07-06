#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define pb emplace_back
#define clr(x) memset(x, 0, sizeof x)
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int, int>;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        int l, r; cin >> l >> r;

        deque<int> dq;
        vector<int> v(n+1), qs(n+1);
        for(int i=1; i<=n; ++i) cin >> v[i], qs[i] = qs[i-1] + v[i];
        
        int res = 0;
        dq.emplace_back(0);
        for(int i=l; i<=n; ++i) {
            res = max(res, qs[i] - qs[dq.front()]);
            while(dq.size() and i - dq.front() >= r) dq.pop_front();
            int nw = dq.back() + 1;

            while(dq.size() and qs[dq.back()] > qs[nw]) dq.pop_back();
            dq.emplace_back(nw);
        }
        cout << res << '\n';
    }
    return 0;
}