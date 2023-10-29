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
const int N = 2e5+ 3;
int ar[N], head[N], sz[N], id[N], seg[2*N], dep[N], pa[N];
vector<int> adj[N];
int idx,n,q;
 
void upd(int x, int v) {
    x += n;
    seg[x] = v;
    for(int i=x/2;i>0;i/=2) seg[i]=max(seg[2*i],seg[2*i+1]);
}
 
int qry(int x, int y){
    int ret=0;
 
    for(x+=n,y+=n; x<=y; x/=2, y/=2) {
        if(x&1)ret=max(ret,seg[x++]);
        if(y&1^1)ret=max(ret,seg[y--]);
    }
    return ret;
}
 
void dfs(int u, int p){
    sz[u]=1;
    for(auto v : adj[u]){
        if(v==p) continue;
        dep[v]=dep[u]+1;
        pa[v]=u;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
 
void hld(int u, int p, int h){
    head[u]=h;
    id[u]=++idx;
    upd(id[u],ar[u]);
    int big=-1,mx=0;
    for(auto v : adj[u]){
        if(sz[v]>mx and v!=p) mx=sz[v],big=v;
    }
    if(big!=-1)hld(big,u,h);
    
    for(auto v : adj[u]){
        if(v!=big and v!=p)hld(v,u,v);
    }
}
 
int path(int x, int y){
    int ret=0;
    while(head[x]!=head[y]){
        if(dep[head[x]]<dep[head[y]])swap(x,y);
        ret=max(ret, qry(id[head[x]],id[x]));
        x=pa[head[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    ret=max(ret, qry(id[x],id[y]));
    return ret;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>ar[i];
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs(1,1); hld(1,1,1);
    while(q--){
        int c, x, y; cin>>c>>x>>y;
        if(c==1) upd(id[x],y);
        else cout<<path(x,y)<<' ';
    }
    return 0;
}
