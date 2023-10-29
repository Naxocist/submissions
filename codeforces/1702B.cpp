#include <bits/stdc++.h>
using namespace std;

bitset<200> chk;
void solve() {
    string s; cin >> s;
    int res = 0 ;

    for(auto x : s) {
        if(chk[x]) continue ;

        if(chk.count() == 3) {
            res++;
            chk.reset();
            // cout << x << ' ';
            chk[x] = 1;
            continue ;
        }
        chk[x] = 1;
    }

    res++;
    chk.reset();
    cout << res << '\n';

    return ;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}