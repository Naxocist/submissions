#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
const ll INF = 2e12;

void solve(int n) {
	vector<vector<ll>> floyd(n+1, vector<ll>(n+1, INF));

	unordered_map<int, string> name;
	for(int i=0; i<n; ++i) {
		string s; cin >> s;
		name[i] = s;
		for(int j=0; j<n; ++j) {
			ll w; cin >> w;
			if(w == 0 && i != j) floyd[i][j] = INF; 
			else floyd[i][j] = w;
		}
	}

	for(int k=0; k<n; ++k) {
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				if(floyd[i][k] < INF && floyd[k][j] < INF)
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			for(int t=0; t<n; ++t) {
				if(floyd[i][t] < INF && floyd[t][t] < 0 && floyd[t][j] < INF) {
					floyd[i][j] = -INF;
				}
			}
		}
	}

	int x; cin >> x;
	while(x--) {
		int u, v; cin >> u >> v;
		if(floyd[u][v] == -INF) {
			cout << "NEGATIVE CYCLE\n";
			continue ;
		}

		cout << name[u] << "-" << name[v] << ' ';

		if(floyd[u][v] == INF) {
			cout << "NOT REACHABLE\n";
		}else {
			cout << floyd[u][v] << '\n';
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	for(int i=1; ;++i){
		int n; cin >> n;
		if(n == 0) break;
		cout << "Case #" << i << ":\n";
		solve(n);
	}
	return 0;
}