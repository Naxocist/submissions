#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int a[N], b[N], qa[N], qb[N];

int main() {

	int n, k; cin >> n >> k;

	for(int i=1; i<=n; ++i) cin >> a[i];
	for(int i=1; i<=n; ++i) cin >> b[i];
	for(int i=1; i<=n; ++i) qa[i] = qa[i-1] + a[i];
	for(int i=1; i<=n; ++i) qb[i] = qb[i-1] + b[i];

	multiset<double, greater<double>> res;
	for(int i=1; i<=n; ++i) {
		for(int j=i; j<=n; ++j) {
			double p = double(qa[j] - qa[i-1]) / double(qb[j] - qb[i-1]);
			res.emplace(p);
			if(res.size() > k) res.erase(--res.end());
		}
	}

	for(auto r : res) {
		if(!(--k)) {
			r = floor(r * 1000.0) / 1000.0;
			cout << fixed << setprecision(3) << r;
			return 0;
		}
	}
}