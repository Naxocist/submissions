#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll k = 1e12;
void solve() {
	string s; cin >> s;
	int n = s.size();
	ll one = 0, zero = 0;
	for(char c : s) one += c=='1';
	
	ll res = LLONG_MAX;
	for(int i=0; i<n-1; ++i) {
		char c = s[i], cc = s[i+1];
		if(c == '1') one--;
		if(c == '0') zero++;
		ll t = zero + one + (c=='1') + (cc=='0');
		ll r = (n-t)*(k+1);
		if(c > cc) r += k;

		res = min(res, r);
	}

	cout << (res==LLONG_MAX ? 0:res) << '\n';
}

int main() {

	int t; cin >> t;
	while(t--) solve();
	return 0;
}