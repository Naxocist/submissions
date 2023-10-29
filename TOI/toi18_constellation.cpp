#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 303, M = 1603, mod = 1e6 + 3;
int a[M][M], b[M][M]; 
ll fac[N*N], inv[N*N];

ll binpow(ll x, ll y) {
    ll res = 1;
    for(;y;x=(x*x)%mod, y>>=1) if(y&1) res = (res*x)%mod;
    return res;
}

ll C(ll n, ll r) {
    return (((fac[n]*inv[n-r])%mod)*inv[r])%mod;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    fac[0] = inv[0] = 1;
    for(int i=1; i<N*N; ++i) {
        fac[i] = (fac[i-1] * i) % mod;
        inv[i] = binpow(fac[i], mod-2);
    }

    int n, m, k; cin >> n >> m >> k;

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            char c; cin >> c;
            if(c == '#') a[i+601][j+601] ++, b[i+601][j+601] ++;
        }
    }

    for(int i=1; i<1600; ++i) {
        for(int j=1; j<1600; ++j) {
            a[i][j] += a[i-1][j+1], b[i][j] += b[i-1][j-1];
        }
    }
            
    ll res = 0;
    for(int s = 1; s<=n+m; ++s) {
        for(int i=602; i<=601+n; ++i) {
            for(int j=602; j<=601+m; ++j) {
                int cnt = 0;
                cnt += a[i][j-s] - a[i-s-1][j+1];
                cnt += a[i+s][j] - a[i-1][j+s+1];
                cnt += b[i-1][j+s-1] - b[i-s][j];
                cnt += b[i+s-1][j-1] - b[i][j-s];
                if(cnt < k) continue ;
                res += C(cnt, k);
                res %= mod; 
            }
        }
    }

    cout << res;

    return 0;
}
