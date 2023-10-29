#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
map<ll, pi> mp;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ll n, t; cin >> n >> t;
	vector<ll> v(n); for(auto &x : v) cin >> x;
 
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			mp[v[i] + v[j]] = pi(i, j);
		}
	}
 
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			if(mp.find(t - v[i] - v[j]) != mp.end()) {
				int a, b; tie(a, b) = mp[t - v[i] - v[j]];
				if(i == a || i == b || j == a || j == b) continue ;
				i++,j++,a++,b++;
				cout << i << ' ' << j << ' ' << a << ' ' << b ;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
