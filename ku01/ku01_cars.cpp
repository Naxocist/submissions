#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v) cin >> x >> x;
	int res = 0;

	for(int i=n-2; i>=0; --i) {
		if(v[i] <= v[i+1]) {
			res ++;
			v[i] = v[i+1];
		}
	}
	cout << res;
	return 0;
}