#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k; cin >> n >> k;
	vector<string> v(n);
	for(auto &x : v) cin >> x;
	int c = 0;
	bool f = false;
	while(!f) {
		c++;
		int i = 0;
		for(; i<n; ++i) {
			int j = c % v[i].size();
			int x = v[i][j] - '0';
			if(x != k) break ;
		}
		f = (i == n);
	}
	cout << c;
	return 0;
}