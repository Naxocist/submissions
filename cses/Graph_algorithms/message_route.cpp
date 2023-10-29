#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
 
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using piv = pair<int, vi>;
 
const int N = 1e5 + 3;
vector<int> adj[N];
bool vis[N];
int parent[N];
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
 
    for(int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    queue<int> q;
    q.push(1);
    vis[1] = 1;
 
    while(q.size()){
        int u = q.front(); q.pop();
 
        if(u == n){
            int p = n;
            stack<int> st;
            
            while(p != 0) st.push(p), p = parent[p];
 
            cout << st.size() << '\n';
            while(st.size()){
                cout <<  st.top() << ' ';
                st.pop();
            }
            return 0;
        }
 
        for(int v : adj[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            parent[v] = u;
            q.push(v);
        }
    }
 
    cout << "IMPOSSIBLE";
    return 0;
 
}
