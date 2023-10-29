#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll qs, res;
int len, n, w;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> w;
    
    deque<pair<ll, int>> dq;
    dq.emplace_back(0, 0);
    
    for(int i=1; i<=n; ++i) {
        ll x; cin >> x;
        qs += x;

        while(dq.size() && dq.back().first >= qs) dq.pop_back();
        while(dq.size() && i - dq.front().second > w) dq.pop_front();

        dq.emplace_back(qs, i);

        ll r = dq.back().first - dq.front().first;
        int l = dq.back().second - dq.front().second;
        if(dq.front().second == i) continue ;

        if(r > res) {
            res = r;
            len = l;
        }else if(r == res) {
            len = min(len ,l);
        }
    }

    cout << res << '\n' << len;
    return 0;
}