#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 3, mod = 1e9 + 7;
using ll = long long;
ll res[N];
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, p; cin >> n >> m >> p;


	vector<int> v(n); for(auto &x : v) cin >> x, res[x] ++;

	while(m--) {
		int y; cin >> y;

		for(auto x : v) {
			int prev = 0;
			while(1) {
				int now = (prev ? (prev + y)/2 : (x + y)/2);
				if(now == prev) break ;
				res[now] ++;
				prev = now;
			}
		}
	}

	for(int i=1; i<=p; ++i) cout << res[i] << '\n';
	return 0;
}