#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	n *= 2;
	for(int i=1; i<n; ++i) {
		for(int j=1; j<n; ++j) {
			int k = n/2 - min({i, j, n-i, n-j}) + 1;
			if(k < 10) cout << ' ';
			cout << k << ' ';
		}
		cout << '\n';
	}
	return 0;
}