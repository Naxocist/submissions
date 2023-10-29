#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
const int N = 2e5 + 3;
using pi = pair<int, int>;
int val[N]; bool r[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int h, n, k; cin >> h >> n >> k;
	for(int i=1; i<=n; ++i) cin >> val[i];
	vector<pi> v(k);
	for(auto &x : v) cin >> x.second >> x.first; sort(all(v));
	int c; cin >> c;
	for(auto x : v) {
		int i, h; tie(h, i) = x;
		swap(r[i], r[i+1]);
		if(i == c) c++;
		else if(i + 1 == c) c--;
		r[c] = r[c-1] = r[c+1] = 1;
	}
	int mx = 0;
	for(int i=1; i<=n; ++i) if(r[i]) mx = max(mx, val[i]);
	cout << mx << '\n' << (mx == val[c] ? "NO" : "USE");

	return 0;
}