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
using pi = pair<int, int>;
const int mod = 1e9 + 7;
const int INF = 2e9;
const int N = 1e5 + 5;
ll val[N];
vector<int> adj[N];

void solve() {
    int n, m, s, q; cin >> n >> m >> s >> q;
    for(int i=1; i<=n; ++i) cin >> val[i];

    for(int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    queue<int> Q;
    Q.push(s);

    vector<int> lvl(n+1, -1);
    vector<vector<int>> in_lvl(n+1);

    lvl[s] = 0;
    int mx_lvl = 0;

    while(Q.size()) {
        int u = Q.front(); Q.pop();
        mx_lvl = max(mx_lvl, lvl[u]);
        in_lvl[lvl[u]].pb(u);

        for(auto v : adj[u]) {
            if(lvl[v] != -1)  continue;
            lvl[v] = lvl[u] + 1;
            Q.push(v);
        }
    }

    priority_queue<ll> pq;
    vector<ll> qs_node(mx_lvl + 2), mn_get(mx_lvl + 2), qs_min(mx_lvl + 2);
    ll sum = 0;

    qs_node[1] ++;
    for(int i=mx_lvl; i>=1; --i) {
        for(auto u : in_lvl[i]) {
            pq.push(val[u]);
            qs_node[i+1] ++;
        }

        ll pick = pq.top(); pq.pop();
        mn_get[i] = pick;
        sum += pick;
    }

    // layer = [0, mx_lvl]
    for(int i=1; i <= mx_lvl + 1; ++i) {
        if(i > 1) mn_get[i] = min(mn_get[i], mn_get[i-1]);
        qs_min[i] = qs_min[i-1] + qs_node[i]*mn_get[i];
        qs_node[i] += qs_node[i-1];
    }

    // for(int i=1; i<=mx_lvl; ++i) cout << mn_get[i] << ' ';
    // cout << '\n';

    while(q--) {
        ll t, x, y; cin >> t;

        if(t == 1) {
            cin >> x >> y;
            int l = lvl[x] + 1;
            cout << sum + max(0LL, y-mn_get[l]) << '\n';
        }else {
            cin >> y;

            int l = 1, r = mx_lvl + 1, dv = -1;
            while(l <= r) {
                int md = l + (r-l)/2;
                if(mn_get[md] < y) r = md - 1, dv = md;
                else l = md + 1;
            }

            ll a = qs_node[dv-1]*sum;
            ll b = (qs_node[mx_lvl+1]-qs_node[dv-1])*(sum+y) - (qs_min[mx_lvl+1] - qs_min[dv-1]);

            cout << a + b << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int TC = 1; 
    // cin >> TC;
    while(TC--) solve();
    return 0;
}

/*
8 7 1 1
300 100 50 90 150 200 600 300
1 2
2 3
3 4
4 5
5 6
6 7
7 8
1 5 60
 */
