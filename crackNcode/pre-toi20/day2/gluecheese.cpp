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
using T = tuple<ll, int, int>;
const int mod = 1e9 + 7;
const ll INF = 2e18;
const int N = 1e3 + 3;
ll ar[N][N], d[N][N];

void solve() {
    int n, m, r, c; cin >> n >> m >> r >> c;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        cin >> ar[i][j];
        d[i][j] = INF;
    }

    priority_queue<T, vector<T>, greater<T>> pq;
    pq.emplace(d[r][c] = ar[r][c], r, c);
    while(pq.size()) {
        auto [q, x, y] = pq.top(); pq.pop();
        int t[] = {1, 0, -1, 0, 1};
        for(int i=0; i<4; ++i) {
            int xx = x + t[i], yy = y + t[i+1];
            if(xx < 1 or yy < 1 or xx > n or yy > m) continue ;

            if(d[x][y] + ar[xx][yy] < d[xx][yy]) 
                pq.emplace(d[xx][yy]=d[x][y]+ar[xx][yy], xx, yy);
        }
    }

    ll last = min({d[1][1], d[1][m], d[n][1], d[n][m]});

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            cout << d[i][j] + last - ar[r][c] << ' ';
            // cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int TC = 1; 
    // cin >> TC;
    while(TC--) solve();
    return 0;
}
