#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
int main() {
	int n, m; cin >> n >> m;
	vector<int> a, b;
	int md = n/2;
	for(int i=0; i<n; ++i) {
		int x; cin >> x;
		if(i < md) a.pb(x);
		else b.pb(x);
	}

	
int mx = 0;
	vector<int> c, d;
	for(int i=0; i<1<<md; ++i) {
		int s = 0;
		for(int j=0; j<md; ++j) {
			if(i&(1<<j)) {
				s += a[j];
				s %= m;
			}
		}
		mx = max(mx, s);
		c.pb(s);
	}

	for(int i=0; i<1<<(n-md); ++i) {
		int s = 0;
		for(int j=0; j<(n-md); ++j) {
			if(i&(1<<j)) {
				s += b[j];
				s %= m;
			}
		}
		mx = max(mx, s);
		d.pb(s);
	}

	sort(d.begin(), d.end());
	for(auto x : c) {
		int t = upper_bound(d.begin(), d.end(), m-x-1) - d.begin() - 1;
		if(t>=0) mx = max(mx, (x + d[t])%m);
	}

	cout << mx;
	return 0;
}