#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
using pi = pair<int, int>;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k, m; cin >> n >> k >> m;

	vector<pi> v;
	vector<int> ok(n+1);
	for(int i=1; i<=n; ++i) {
		int a, b; cin >> a >> b;
		v.emplace_back(a, i); v.emplace_back(b+1, -i);
	}
	sort(all(v));
	int crr = 0;
	for(auto e : v) {
		int x = e.second;
		if(ok[abs(x)] == -1) continue; 
		if(x < 0) crr--, x=-x;
		else crr++;

		if(crr > k) ok[x] = -1, crr--;
		else if(ok[x] != -1) ok[x] = 1;
	}

	while(m--) {
		int x; cin >> x;
		cout << (ok[x] != -1 ? "Y" : "N") << ' ';
	}
	return 0;
}