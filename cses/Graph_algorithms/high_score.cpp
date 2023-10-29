#include <bits/stdc++.h>
using namespace std;
#define INF 2e15
const int N = 2503;
using ll = long long;
using T = tuple<int, int, int>;
ll dist[N], s[N], t[N];
vector<T> edge;
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	while(m--) {
		int u, v, w; cin >> u >> v >> w;
		edge.emplace_back(u, v, w);
	}
	for(int i=1; i<=n; ++i) dist[i] = -INF, s[i] = t[i] = i;
	dist[1] = 0;
	for(int i=0; i<n; ++i) {
		for(auto e : edge) {
			int u, v, w; tie(u, v, w) = e;
			if(dist[u] + w > dist[v]) {
				dist[v] = dist[u] + w;
				if(i == n-1 and s[u] == 1 and t[v] == n) {
					cout << -1; return 0;
				}
			}
			if(s[u] == 1) s[v] = 1;
			if(t[v] == n) t[u] = n;	
		}
	}
 
	cout << dist[n];
	return 0;
}
