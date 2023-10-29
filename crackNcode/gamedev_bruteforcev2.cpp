#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;
using ll = long long int;
using pi = pair<int, int>;
ll ar[N], p[N];
vector<int> possible[N];

ll f(int l, int r) {
    // cout << l << ' ' << r << '\n';
    return ar[r]*(r-l) - p[r-1] + p[l-1];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;

    for(int i=1; i<=n; ++i) {
        cin >> ar[i];
        p[i] = p[i-1] + ar[i];
    }
    

    vector<pi> lis;
    ll res = 0;
    for(int i=1; i<=n; ++i) {
        ll x = ar[i];
        auto t = lower_bound(lis.begin(), lis.end(), pi(x, i));
        int k = t - lis.begin();

        if(t == lis.end()) {
            lis.emplace_back(x, i);
        }
        else {
            *t = pi(x, i);
        }
        for(int j=0; j<k; ++j) {
            for(int e : possible[j]) {
                res = max(res, f(e, i));
            }
        }
        possible[k].push_back(i);
    }   

    cout << res;
    return 0;
}
/*
7
10 10 5 9 4 9 3
7
10 1 5 9 2 3 3
5
5 4 7 2 10
5
10 7 2 1 8

10
5 2 8 2 9 1 8 2 0 3
*/