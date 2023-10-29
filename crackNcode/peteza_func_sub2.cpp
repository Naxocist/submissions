#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
const int N = 5e5 + 3;
int ar[N], n, q, l, r;
vector<int> v;
int res = 0;
void f(int x) {
	if(x == n + 1) {
		int mx = -INF, mn = INF;
		for(auto y : v) mx = max(mx, y), mn = min(mn, y);
		res += (l <= mx*mn && mx*mn <= r);
		return ;
	}

	v.push_back(ar[x]);
	f(x+1);
	v.pop_back();
	f(x+1);
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=n; ++i) cin >> ar[i];

	while(q--) {
		cin >> l >> r;
		f(1);
		cout << res << '\n';
		res = 0;
	}
	return 0;
}