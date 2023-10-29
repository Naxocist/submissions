#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;

	vector<int> v(m);
	for(auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	
	int t = n - m;
	while(t--){
		int x; cin >> x;
		int r = upper_bound(v.begin(), v.end(), x) - v.begin() + 1;
		cout << r << '\n';
	}
	return 0;
}