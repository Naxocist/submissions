#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
const int N = 505;
ll dist[N][N];
 
int main() {
 
 
	int n, m, q; scanf("%d%d%d", &n, &m, &q);
 
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) dist[i][j] = LLONG_MAX;
		dist[i][i] = 0;
	}
 
	for(int i=0; i<m; ++i) {
		int u, v; ll w; scanf("%d%d%lld", &u, &v, &w);
		dist[u][v] = min(w, dist[u][v]);
		dist[v][u] = min(w, dist[v][u]);
	}
 
	for(int k=1; k<=n; ++k) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				if(dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX) continue ;
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}
	while(q--) {
		int s, t; scanf("%d%d", &s, &t);
		if(dist[s][t] == LLONG_MAX) printf("-1\n");
		else printf("%lld\n", dist[s][t]);
	}
	return 0;
}