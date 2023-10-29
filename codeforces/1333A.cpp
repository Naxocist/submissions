#include <bits/stdc++.h>
using namespace std;
void f() {
	int n, m; cin >> n >> m;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cout << (i == 0 && j == 0 ? 'W' : 'B');
		}
		cout << '\n';
	}
}
int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) f();
	
	return 0;
}