#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

using ll = long long ;
using pid = pair<int, double>;
using pi = pair<pid, int>;

const int N = 1e5 + 3;
vector<pid> G[N];
pid dist[N];
int par[N];


int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, s, t; cin >> n >> m >> s >> t;

    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w/100.0});
        G[v].push_back({u, w/100.0});
    }

    for(int i=0; i<=n; ++i){
        dist[i] = {INF, 0};
    }

    dist[s] = {1, 0};
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.emplace(dist[s], s);
    
    while(pq.size()){
        auto f = pq.top();
        int u = f.second, uw = f.first.first;
        double up = f.first.second;
        pq.pop();

        for(auto x : G[u]){
            int v = x.first;
            double p = x.second;
            int vw = dist[v].first;
            double vp = dist[v].second;

            int nw = uw + 1;
            double np = 1 - (1 - up) * (1 - p);
            if(nw < vw || (nw == vw && np < vp)){
                dist[v].first = nw; dist[v].second = np;
                par[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }
    
    int ansW = dist[t].first;
    double ansP = dist[t].second;
    stack<int> path;
    path.push(t);
    while(t != s) { // backtrack to s
        t = par[t];
        path.push(t);
    }

    cout << fixed << setprecision(6) << ansW << ' ' << ansP << '\n';

    while(path.size()){
        cout << path.top() << ' ';
        path.pop();
    }
    return 0;

}

/*
4 4
1 3
1 2 50
2 3 50
1 4 10
4 3 10
*/