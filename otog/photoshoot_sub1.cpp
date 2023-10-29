#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(int i=1; i<=n; ++i) v[i-1] = i;
	using pi = pair<int, int>;
	vector<pi> p(k);
	for(auto &x : p) cin >> x.first >> x.second;

	int mx = 0;
	vector<int> res;
	do {
		int s = 0;
		for(auto x : p) {
			int l = x.first, r = x.second; l--, r--;
			int mx = -1, mn = 1e9;
			for(int i=l; i<=r; ++i) mx = max(mx, v[i]), mn = min(mn, v[i]);
			s += mx - mn;
		}
		if(s > mx) {
			mx = s;
			res = v;
		}
	}while(next_permutation(all(v)));

	for(auto x : res) cout << x << ' ';
	return 0;
}