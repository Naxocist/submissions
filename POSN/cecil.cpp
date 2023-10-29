#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

vector<int> adj[30];
int path[30], par[30];
bitset<30> vis, in;

bool cycle(int u) {
    if(vis[u]) return 1;
    vis[u] = 1;


    if(path[u] >= 0 && cycle(path[u])) return 1;

    return vis[u] = 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);
    memset(path, -1, sizeof path);
    memset(par, -1, sizeof par);
    for(int i=0; i<25; ++i) path[i] = i+1, par[i] = i-1;
    in[0] = 1;
    int t; cin >> t;
    int n = 30;
    string a, b; cin >> a;
    while(--t) {
        cin >> b;

        for(int i=0; i<a.size() && i < b.size(); ++i){
            int u = a[i] - 'a', v = b[i] - 'a';

            if(u == v || path[u] == v) continue ;
            if(in[v]) {
                in[path[v]] = 1;
                in[v] = 0;
            }
            path[par[v]] = path[v];
            par[path[v]] = par[v];

            path[v] = path[u];
            par[path[u]] = v;

            path[u] = v;
            par[v] = u;
            break ;
        }
        a = b;
    }

    // for(int i=0; i<n; ++i) {
    //     // cout << char(i + 'a') << " : " << char(path[i] + 'a') << ln;
    //     cout << char(i + 'a') << " : " << in[i] << ln;
    // }
    
    int st = -1;
    for(int i=0; i<n; ++i) {
        if(st == -1 && in[i]) st = i;
        if(path[i] >= 0 && cycle(i)) {
            // cout << char(i + 'a') << endl;
            cout << -1;
            return 0;
        }
    }

    string res;
    
    while(st != -1) {
        res.push_back(st + 'a');
        st = path[st];
    }
    cout << res;
    return 0;
}

/*
10
tourist
petr
wjmzbmr
yeputons
vepifanov
scottwu
oooooooooooooooo
subscriber
rowdark
tankengineer
*/