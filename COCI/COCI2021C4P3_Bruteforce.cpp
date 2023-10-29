#include <bits/stdc++.h>
using namespace std;

using ll = long long;
unordered_map<int, int> mp;

int main() {
	int n; cin >> n;

	vector<int> v(n);
	for(auto &x : v) cin >> x;

	ll res = n*(n+1)/2;
	for(int i=0; i<n; ++i) {
		int mxf = 0;
		for(int j=i; j<n; ++j) {
			mxf = max(mxf, ++mp[v[j]]);	
			if(mxf > (j - i + 1)/2) res++;
		}
		mp.clear();
	}
	cout << res;
	return 0;
}