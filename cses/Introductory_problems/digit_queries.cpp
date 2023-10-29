#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 19;
ll qs[N], ten[N];
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q; cin >> q;
	ten[0] = 1;
	for(int i=1; i<N; ++i) ten[i] = ten[i-1] * 10;
	
	while(q--) {
		ll x; cin >> x;
		if(x <= 9) {
			cout << x <<'\n'; continue ;
		}
		ll k = 1;
		for(;x-9*ten[k-1]*k > 0; x-=9*ten[k-1]*k, k++);
		x--;
		string t = to_string(ten[k-1] + x/k);
		cout << t[x%k] << '\n';
	}
	
	return 0;
}
