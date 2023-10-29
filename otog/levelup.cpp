#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, m; cin >> n >> m;

	int mx = 0;
	while(n--) {
		int x; cin >> x;
		mx = max(mx, x);
	}

	while(m--) {
		int x; cin >> x;
		cout << ((x - 1) / mx) + 1 << '\n';
	}
	return 0;
}