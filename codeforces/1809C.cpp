#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	int t = 0;
	while((t+1)*(t+2)/2 <= k) t ++;

	int p = k - t*(t+1)/2;

	for(int i=0; i<t; ++i) cout << 2 << ' ';

	if(t != n) {
		cout << 2*(p-t) - 1 << ' ';
	}

	for(int j=t+1; j<n; ++j) {
		cout << -1000 << ' ' ;
	}
	cout << '\n';
}	

int main() {
	int t; cin >> t;
	while(t--) solve();
	return 0;
}