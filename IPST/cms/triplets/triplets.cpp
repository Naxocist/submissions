#include "triplets.h"
#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const ll N = 1e5 + 3, mod = 9377;
vector<int> adj[N], rev[N];
ll fac[2*N], inv[2*N];

ll binpow(ll x, ll y) {
    ll res = 1;
    for(;y;y>>=1, x*=x,x%=mod){
        if(y&1)res*=x;
        res%=mod;
    }
    return res;
}

ll P(int n, int r) {
    if(n<r)return 0;
    return (fac[n]*inv[n-r])%mod;
}

stack<int> st, t;
bool vis[N];

void dfs(int u) {
    if(vis[u]) return ;
    vis[u]=1;
    for(auto v : adj[u]) {
        dfs(v);
    }
    st.emplace(u);
}

void dfs2(int u) {
    if(vis[u]) return ;
    vis[u]=1;
    t.emplace(u);
    for(auto v : rev[u]) {
        dfs2(v);
    }
}

int count_triplets(int n, std::vector<int> U, std::vector<int> V, std::vector<int> col){
    fac[0]=inv[0]=1;
    for(int i=1; i<2*N; ++i) {
        fac[i]=i*fac[i-1],fac[i]%=mod;
        inv[i]=binpow(fac[i],mod-2),inv[i]%=mod;
    }
    for(int i=0; i<U.size();++i){
        adj[U[i]].pb(V[i]);
        rev[V[i]].pb(U[i]);
    }

    for(int i=0; i<n; ++i) {
        dfs(i);
    }
    ll ret = P(n,3);
    // cout << P(6, 3) << endl;
    vector<int> group(n);
    for(int i=0; i<N;++i)vis[i]=0;
    while(st.size()) {
        int u = st.top(); st.pop();
        if(vis[u])continue;
        dfs2(u);
        int sz = t.size();
        map<ll, ll> cnt;
        while(t.size()) {
            int x=t.top();t.pop();
            group[x]=u;
            // cout << x << ' ' ;
            cnt[col[x]] ++;
        }
        // if(sz)cout << endl, div()
        for(auto e : cnt) {
            ll c, d; tie(c, d) = e;
            ret -= P(d, 3);
            ret=(ret+mod)%mod;
        }
        // ret -= P(sz,3);
    }

  return ret%mod;
}   