#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
using T = tuple<int, int, int>;
using pi = pair<int, int>;
const int N = 203;
int dist[17][1<<17], idx[N], floyd[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;
	idx[0] = 1, idx[k+1] = n; 
	for(int i=1; i<=k; ++i) cin >> idx[i];
	
	for(int i=1; i<=n; ++i) 
		for(int j=1; j<=n; ++j) floyd[i][j] = INF, floyd[i][i] = 0;

	for(int i=0; i<=k+1; ++i) 
		for(int j=0; j<(1<<17); ++j) dist[i][j] = INF;
	
	while(m--){
		int u, v, w; cin >> u >> v >> w;
		floyd[u][v] = min(floyd[u][v], w);
		floyd[v][u] = min(floyd[v][u], w);
	}

	for(int k=1; k<=n; ++k) 
		for(int i=1; i<=n; ++i) 
			for(int j=1; j<=n; ++j) 
				if(floyd[i][k] != INF and floyd[k][j] != INF)
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
		
	priority_queue<T> pq;
	pq.emplace(0, 0, 1);
	dist[0][1] = 0;
	while(pq.size()) {
		int d, u, t; tie(d, u, t) = pq.top(); pq.pop();
		if(u == k+1 and t == (1<<(k+2)) - 1) {
			cout << -d; return 0;
		}
		for(int v=0; v<=k+1; ++v) {
			int nu = idx[u], nv = idx[v];
			if(v == u) continue ;
			int vw = floyd[nu][nv], nt = t | (1 << v);
			if(dist[u][t] + vw < dist[v][nt]) {
				dist[v][nt] = dist[u][t] + vw;
				pq.emplace(-dist[v][nt], v, nt);
			}
		}
	}
}