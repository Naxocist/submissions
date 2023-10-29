#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using pi = pair<int, int>;
vector<pi> v;

int main() {

    int m, n; scanf("%d%d", &m, &n);

    vector<ll> f(10, 1);
    for(int i=0; i<m; ++i) {
        int x, a, b; scanf("%d%d%d", &x, &a, &b);
        v.emplace_back(a, x); v.emplace_back(b+1, -x);
    }
    sort(v.begin(), v.end());

    ll mx = 0; 
    int r = 0;
    for(int i=0; i<v.size()-1; ++i) {
        int k = v[i].second, c = 1;
        if(k < 0) c = -1, k *= -1;

        if(k == 2) f[2] += c;
        if(k == 3) f[3] += c;
        if(k == 4) f[2] += 2*c;
        if(k == 5) f[5] += c;
        if(k == 6) f[2] += c, f[3] += c;
        if(k == 7) f[7] += c;
        if(k == 8) f[2] += 3*c;
        if(k == 9) f[3] += 2*c;
        if(k == 10) f[2] += c, f[5] += c;

        ll t = f[2] * f[3] * f[5] * f[7];
        int q = v[i+1].first - v[i].first;
        if(t > mx) {
            mx = t; r = q;
        }else if(t == mx){
            r += q;
        }
    }

    printf("%lld %d", mx, r);
    return 0;
}

/*
1 5
3 0 2

1 1 1 1 1
3 3 3 1 1
*/