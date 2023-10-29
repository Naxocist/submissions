#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
using ll = long long;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	sort(all(a)), sort(all(b)); ll res = 0;
	for(int i=0; i<n; ++i) res += abs(a[i] - b[i]);
	cout << res;
	return 0;
}