#include <bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	vector<T> v(n);
	for(int i=0; i<n; ++i) {
		int l, r; cin >> l >> r;
		v[i] = T(r, -l, i);
	}
	sort(v.begin(), v.end());

	vector<int> lis, res(n);
	for(auto &x : v) {
		int l, r, i; tie(r, l, i) = x;

		auto t = upper_bound(lis.begin(), lis.end(), l);
		if(t == lis.end()) {
			lis.push_back(l);
			res[i] = lis.size();
		}else {
			*t = l;
			res[i] = t - lis.begin() + 1;
		}
	}
	cout << lis.size() << '\n';
	for(auto &x : res) {
		cout << x << ' ';
	}
}