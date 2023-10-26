#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int N = 2e5 + 3;


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k; cin >> n >> k;
	vector<pi> v(n); for(auto &x : v) cin >> x.second >> x.first;

	sort(v.begin(), v.end());
	
	int res = 0;
	multiset<int> t;
	for(int i=0; i<k; ++i) t.insert(0);
	for(auto e : v) {
		int l, r; tie(r, l) = e;
		auto x = t.upper_bound(l);
		if(x == t.begin()) continue ;
		
		t.erase(--x);
		t.insert(r);
		res ++;
	}
	cout << res;
	return 0;
}