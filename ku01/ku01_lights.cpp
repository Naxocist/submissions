#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n); for(auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	int t = 0, res = 0;
	for(auto x : v) t += x, res += t;
	cout << res*2;
	return 0;
}