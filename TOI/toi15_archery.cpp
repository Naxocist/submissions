#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using pi = pair<ll, ll>;
const int N = 5e5 + 3;
pi spot[N];

ll cal(ll x, ll h, ll l) { return x - h + l; }

int main() {

    int n; scanf("%d", &n);

    ll low = LONG_LONG_MAX;

    for(int i=1; i<=n; ++i) scanf("%lld", &spot[i].second), low = min(low, spot[i].second);
    for(int i=1; i<=n; ++i) scanf("%lld", &spot[i].first);
    

    sort(spot+1, spot+n+1);

    ll c = 0;
    for(int i=1; i<=n; ++i) {
        c += spot[i].first - spot[1].first;
    }

    ll res = spot[1].first, mn = c;
    for(int i=2; i<=n; ++i) {
        if(spot[i].first > low) break ; // impossible
  
        c -= (spot[i].first - spot[i-1].first) * (n-1);
        c += cal(spot[i-1].first, spot[i].first, spot[i-1].second);

        if(c < mn) {
            mn = c;
            res = spot[i].first;
        }
    }

    printf("%lld %lld", res, mn);
    
    return 0;
}

/*
5
7 9 6 8 5
4 5 1 3 5
*/