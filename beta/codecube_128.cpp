#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
int l[N], r[N];
int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) cin >> r[i], l[i] = max(l[i-1], r[i]);
	for(int i=n; i>=1; --i) r[i] = max(r[i+1], r[i]);

	for(int i=1; i<n; ++i) {
		cout << min(l[i], r[i+1]) << ' ';
	}
	return 0;
}