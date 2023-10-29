#include <bits/stdc++.h>
using namespace std;

using pi = pair<double, double>;
#define INF LLONG_MAX
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	vector<pi> v(n);
	for(int i=0; i<n; ++i) {
		double a, b, c, d; cin >> a >> b >> c >> d;
		double st = b == 0 ? 0 : (a == 0 ? INF : b/a), ed = d == 0 ? 0 : (c == 0 ? INF : d/c);
		if(st < ed) swap(st, ed);
		v[i] = pi(ed, st);
	}
	sort(v.rbegin(), v.rend());
	double last = INF;
	int res = 0;
	for(auto &x : v) {
		double st, ed; tie(ed, st) = x;
		if(st < last) res ++, last = ed;
	}
	cout << n - res;
	return 0;
}