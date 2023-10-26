#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
using pi = pair<int, int>;
const int N = 303;
vector<int> adj[N];
int dp[N], res, pos;


void dfs(int u) {
	for(int v : adj[u]) {
		dfs(v);
		dp[u] += dp[v];
	}
	if(dp[u] > res) {
		res = dp[u];
		pos = u;
	}
}


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;

	vector<pi> v;
	for(int i=1; i<=n; ++i) {
		int l, r; cin >> l >> r;
		v.pb(l, i);
		v.pb(r, i);
	}
	sort(v.begin(), v.end());

	stack<int> st;
	vector<int> root;
	for(auto e : v) {
		int t, i; tie(t, i) = e;
		if(st.empty()) st.push(i), root.pb(i);
		else if(st.top() != i) {
			adj[st.top()].pb(i);
			st.push(i);
		}else {
			st.pop();
		}
	}

	while(m--) {
		int x; cin >> x; dp[x] = 1;
	}

	set<int> s;
	for(auto x : root) {
		res = 0;
		dfs(x);
		if(res > 0) s.insert(pos);
	}

	cout << s.size() << '\n';
	for(auto x : s) cout << x << ' ';
	return 0;
}