#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
const int N = 2e5 + 3, M = 30;
int cnt[N], idx[M];
char alp[N];
vector<int> adj[N], alptm[M];
bool vis[N];

int main() {
	int n, m, k; cin >> n >> m >> k;

	for(int i=1; i<=n; ++i) {
		char c; cin >> c;
		cnt[c - 'A'] ++;
		alp[i] = c;
	}

	while(m--) {
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v); adj[v].emplace_back(u);
	}
	string s;
	for(int i=1; i<=k; ++i) {
		char c; cin >> c;
		s += c;
		if(--cnt[c - 'A'] < 0) {
			cout << -1;
			return 0;
		}
	}

	queue<pi> q;
	q.emplace(1, 0);
	while(q.size()) {
		int u, d; tie(u, d) = q.front(); q.pop();
		if(vis[u]) continue ;
		vis[u] = 1;
		alptm[alp[u] - 'A'].push_back(d);
		for(int v : adj[u]) {
			q.emplace(v, d+1);
		}
	}
	// for(int i=0; i<26; ++i) {
	// 	cout << char('A' + i) << ": ";
	// 	for(auto x : alptm[i]) cout << x << ' ';
	// 	cout << endl;
	// }

	ll res = 0;
	for(char c : s){
		// cout << idx[c - 'A'] << " ";
		res += (ll)alptm[c - 'A'][idx[c - 'A']++];
	}
	cout << 2*res;
	return 0;
}