#include <bits/stdc++.h>
using namespace std;

#define INF 2e9

using tiii = tuple<int, int, int>;
using pi = pair<int, int>;
using ll = long long;

const int N = 30;

int in[N];
unordered_set<char> us;
vector<int> adj[N];
bitset<N> vis, has;


bool cycle(int u){
    if(vis[u]) return 1;

    vis[u] = 1;
    for(int v : adj[u]){
        if(cycle(v)) return 1;
    }

    return vis[u] = 0;
}


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);
    int n; cin >> n;

    string t, s; 
    int k = 0;
    
    cin >> s;
    while(--n){
        cin >> t;

        for(auto x : s) us.insert(x);
        for(auto x : t) us.insert(x);

        for(int i=0; i<s.size() && i<t.size(); ++i) {
            int u = s[i] - 'a', v = t[i] - 'a';

            if(u == v) continue ;

            adj[u].push_back(v);
            has[u] = has[v] = 1;
            in[v]++; k++;

            break ;
        }

        s = t;
    }

    for(int i=0; i<N; ++i){
        if(cycle(i)){
            cout << '!';
            return 0;
        }
    }

    queue<int> q;
    for(auto x : us) {
        if(!in[x - 'a']) q.push(x - 'a');
    }

    string res;
    while(q.size()){
        if(q.size() > 1) {
            cout << '?';
            return 0;
        }
        int u = q.front(); q.pop();
        
        res.push_back(u + 'a');

        for(int v : adj[u]){
            if(--in[v] == 0) {
                q.push(v);
            }
        }
    }
    
    cout << res;
    
    return 0;
}
