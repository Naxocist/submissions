#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, int>;
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ll n, t; cin >> n >> t;
	vector<pi> v(n); 
	for(int i=0; i<n; ++i) {
		ll x; cin >> x;
		v[i] = pi(x, i+1);
	}
 
	sort(v.begin(), v.end());
	for(int i=0; i<n; ++i) {
		int l = 0, r = n-1;
		ll x = t - v[i].first;
		while(l < r) {
 
			if(v[l].first + v[r].first == x and l != i and r != i) {
				cout << v[l].second << ' ' << v[r].second << ' ' << v[i].second;
				exit(0);
			}
 
			if(v[l].first + v[r].first > x) r--;
			else l++;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
