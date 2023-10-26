#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using tiii = tuple<int, int, int>;

const int N = 1e6 + 3;
ll ar[N], n, m, l, r;

int main() {
    // freopen("input.in", "r", stdin);
    scanf("%lld%lld", &n, &m);
    for(int i=0; i<n; ++i) scanf("%d", &ar[i]), r = max(r, ar[i]);

    r *= m;
    ll ans = 1e18;
    while(l <= r){
        ll md = l + (r - l)/2, box = 0;

        for(int i=0; i<n; ++i){
            box += md / ar[i];
        }
        if(box >= m){
            ans = min(ans, md);
            r = md - 1;
        }else{
            l = md + 1;
        }

    }

    printf("%lld", ans);
    return 0;
}
