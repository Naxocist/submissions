#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 3;
int n;
vector<int> adj[N];
using pi = pair<int, int>;

bool bfs(int i) {
	
	queue<pi> q;
	q.emplace(i, 0);
	bitset<N> vis;
	vis[i] = 1;

	while(q.size()) {
		int u, d; tie(u, d) = q.front(); q.pop();
		for(int v : adj[u]) {
			
			if(!vis[v]) {
				q.emplace(v, d+1);
				vis[v] = 1;
			}else if(i == v) {
				printf("%d\n", d+1);
				return true;
			}

		}
	}
	return false;
}

int main() {

	scanf("%d", &n);
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			int x; scanf("%d", &x);
			if(x) adj[i].push_back(j);
		}
	}

	for(int i=0; i<n; ++i) {
		if(!bfs(i)) printf("NO WAY\n");	
	}

	return 0;
}