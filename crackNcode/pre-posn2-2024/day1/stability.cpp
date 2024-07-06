#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " is: " << x << '\n'
#define div() cout << "############\n"
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back

using ll = long long int;
using T = tuple<ll, int, int, int>; 
const int mod = 1e9 + 7;
const int INF = 2e9;
const int N = 2e6 + 3;
ll p[N], sz[N];
ll n, m, k;

ll f(ll x, ll y){
    return x*m + y;
}

int par(int u) {
    return (p[u] == u ? u : p[u] = par(p[u]));
}

void un(int i, int j, int x, int y) {
    ll u = par(f(i, j)), v = par(f(x, y));
    if(u == v) return ;
    p[u] = v;
    sz[v] += sz[u];
}


void solve() {
    cin >> n >> m >> k;

    vector<T> box;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            ll x; cin >> x;
            if(k) box.pb(x+k,0,i,j);
            box.pb(x,1,i,j);
        }
    }
    for(int i=0; i<N; ++i) p[i] = i, sz[i] = 1;

    sort(allrev(box));
    ll res = 0;
    vector<vector<bool>> placed(n+3, vector<bool>(m+3, false));
    for(auto [h,b,x,y] : box) {
        set<int> combine = {par(f(x, y))};
        int t[] = {1, 0, -1, 0, 1};

        for(int i=0; i<4; ++i) {
            int xx = x + t[i], yy = y + t[i+1];
            if(placed[xx][yy]) combine.insert(par(f(xx, yy)));
        }


        ll s = 0;
        for(int c : combine) s += sz[c];
        res = max(res, h*s);

        if(b) {
            for(int i=0; i<4; ++i) {
                int xx = x + t[i], yy = y + t[i+1];
                if(placed[xx][yy]) un(x, y, xx, yy);
            }
            placed[x][y] = true;
        }
    }

    cout << res << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int TC = 1; 
    // cin >> TC;
    while(TC--) solve();
    return 0;
}
