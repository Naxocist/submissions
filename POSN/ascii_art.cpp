#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
void solve() {
	
	ll x; cin >> x;
	x--;
	int i = 1;
	while(x >= 26*i) {
		x -= 26*i;
		i++;
	}

	cout << char('A' + x/i) << '\n';
}

int main() {
	int q; cin >> q;
	for(int i=1; i<=q; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}