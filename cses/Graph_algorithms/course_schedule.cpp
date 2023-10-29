#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 3;
vector<int> adj[N];
int in[N];
 
int main() {
 
	int n, m; scanf("%d%d", &n, &m);
 
	for(int i=0; i<m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		in[v] ++;
	}
 
	stack<int> st;
	for(int i=1; i<=n; ++i) {
		if(in[i] == 0) st.push(i);
	}
 
	vector<int> res;
 
	while(st.size()) {
		int u = st.top(); st.pop();
		res.push_back(u);
		for(int v : adj[u]) {
			if(--in[v] == 0) {
				st.push(v);
			}
		}
	}
 
	if(res.size() != n) {
		printf("IMPOSSIBLE"); return 0;
	}else {
		for(int r : res) printf("%d ", r);
	}
	return 0;
}
