#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;

    set<pi> s;
    s.insert({0, 0}), s.insert({n+1, n+1});
    while(q--){
        int x, len; cin >> x >> len;

        int prv = -1;
        bool ok = false;
        bool can = false;

        for(auto e : s) {
            // [prv + 1, l - 1]
            int l, r; tie(l, r) = e;

            int st = prv + 1;

            if((prv < x and x < l) or prv >= x) can = true;

            if(prv < x and x < l) st = x;

            if(prv == -1 or st + len - 1 >= l or !can) {
                prv = r;
                continue ;
            }

            cout << st << ' ' << st + len - 1 << '\n';
            // cout << "F\n";

            s.insert({st, st+len-1});

            ok = true;
            break ;
        }
        if(ok) continue ;

        prv = -1;

        for(auto e : s) {
            int l, r; tie(l, r) = e;

            int st = prv + 1;

            if(prv == -1 or st + len - 1 >= l) {
                prv = r;
                continue ;
            }

            cout << st << ' ' << st + len - 1 << '\n';

            s.insert({st, st+len-1});
            ok = true;
            break ;
        }

        if(!ok) cout << "invalid\n";
    }
}
