#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
using pi = pair<char, int>;
vector<pi> adj[N];
vector<tuple<int, int, double>> r;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(1);
    int m; cin >> m;

    while(m--) {
        char u, v; int w;
        cin >> u >> v >> w;
        adj[(int)u].emplace_back(v, w);
        adj[(int)v].emplace_back(u, w);
    }

    queue<pi> q; 
    q.emplace('X', 'Z');
    bool ok = 0;
    double res = 0; 

    while(q.size()) {
        int u = q.front().first, p = q.front().second; q.pop();
        if(u == 'Y') {
            ok = 1;
            break ;
        }

        vector<double> t;
        
        char d;
        for(auto x : adj[u]) {
            char v; double w; tie(v, w) = x;
            if(v == p) continue ;
            d = v;
            t.push_back(w); 
        }
        q.emplace(d, u);
        if(t.empty()) break ;
        
        sort(t.begin(), t.end());
        int x = t.size();
        double s = (x % 2 ? t[x/2] : (t[x/2] + t[x/2-1]) / 2.0);
        res += s;
        r.emplace_back(u, d, s);
    }

    if(ok) {
        for(auto x : r) {
            char a, b; double c; tie(a, b, c) = x;
            cout << a << ' ' << b  << ' ' << c << '\n'; 
        }
        cout << res;
    }else  cout << "broken";
    
    return 0;
}
