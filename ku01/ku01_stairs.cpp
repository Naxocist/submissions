#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	vector<int> v(n), t(N), odd(N), even(N); 
	for(auto &x : v) cin >> x;

	for(int i=0; i<n-1; ++i) {
		if(i&1) t[v[i+1]+1]++, t[v[i]]--;
		else t[v[i]+1]++, t[v[i+1]]--;
	}

	for(int i=1; i<N; ++i) {
		t[i] += t[i-1];
		if(i&1) odd[i] += t[i];
		else even[i] += t[i];

		odd[i] += odd[i-1];
		even[i] += even[i-1];
	}

	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		l+=!l;
		cout << even[r] - even[l-1] << ' ' << odd[r] - odd[l-1] << '\n';
	}
	return 0;
}