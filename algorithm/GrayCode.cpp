#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

	for(int i=0; i<(1<<n); ++i) {
		int k = (i>>1)^i;
		for(int j=0; j<n; ++j, k>>=1){
			if(k&1) cout << 1;
			else cout << 0;
		}
		cout << '\n';
	}
	return 0;
}