#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k, mx=0; cin >> n >> k;
	vector<int> v(n);
	for(auto &x : v) cin >> x;
	for(int i=0; i<n; ++i) mx = max(mx, (int)(upper_bound(all(v), k+v[i]) - v.begin() - i - 1));
	cout << mx;
	return 0;
}