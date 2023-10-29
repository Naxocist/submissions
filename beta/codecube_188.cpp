#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q; cin >> n >> q;
	unordered_map<int, vector<int>> mp;
	for(int i=0; i<n; ++i) {
		int x; cin >> x;
		mp[x].push_back(i);
	}
	while(q--) {
		int l, r, x; cin >> l >> r >> x, l--, r--;
		vector<int> v = mp[x];
		cout << upper_bound(all(v), r) - lower_bound(all(v), l) << '\n';
	}
	return 0;
}