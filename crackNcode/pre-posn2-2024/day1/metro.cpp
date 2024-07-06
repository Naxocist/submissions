#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

template<typename S, typename T> S amax(S &a, const T &b) { if(b > a) a = b; return a; }
template<typename S, typename T> S amin(S &a, const T &b) { if(b < a) a = b; return a; }

#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define pb emplace_back
#define sz(x) (int) (x).size()
#define ln '\n'
using ll = long long;
using pi = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
const ll INF = 2e9;

void runcase() {
    int n, m; cin >> n >> m;

    vector<int> cost(m);
    unordered_map<int, vector<int>> g, revg;
    for(int q=0; q<m; ++q){
        int k, x; cin >> k >> x;
        cost[q] = x;
        vector<int> t;
        while(k--) {
            int u; cin >> u;
            g[q].pb(u);
            revg[u].pb(q);
        }
    }

    vector<int> dist(n, INF);
    vector<bool> vis(m);
    priority_queue<pi> pq;
    pq.emplace(0, 0);
    dist[0] = 0;
    while(pq.size()) {
        int d, u; tie(d, u) = pq.top(); pq.pop();
        if(d > dist[u]) continue ;

        for(int G : revg[u]) {
            if(vis[G]) continue ;
            vis[G] = 1;
            for(int v : g[G]) {
                if(dist[u] + cost[G] < dist[v]) {
                    dist[v] = dist[u] + cost[G];
                    pq.emplace(-dist[v], v);
                }
            }
        }

    }

    if(dist[n-1] == INF) cout << -1;
    else cout << dist[n-1];
    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}