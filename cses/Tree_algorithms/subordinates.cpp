#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int res[N];
vector<int> v[N];
 
void dfs(int u) {
	res[u] = 1;
	for(auto v : v[u]) {
		dfs(v);
		res[u] += res[v];
	}
}
int main() {
	int n; cin >> n;
	for(int i=2; i<=n; ++i) {
		int up; cin >> up;
		v[up].emplace_back(i);
	}
 
	dfs(1);
 
	for(int i=1; i<=n; ++i) cout << res[i]-1 << ' ';
	return 0;
}
