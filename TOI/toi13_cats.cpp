#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	int prev = 0, res = 0;
	while(n--) {
		int crr; cin >> crr;
		if(prev == 0) prev = crr;
		else if(crr == prev) prev = 0;
		else if(crr > prev) res = max(res, prev), prev = crr;
		else res = max(res, crr);
	}
	cout << res;
	return 0;
}