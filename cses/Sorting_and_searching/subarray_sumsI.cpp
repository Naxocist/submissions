#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n, t ; cin >> n >> t;
	vector<ll> v(n); for(auto &x : v) cin >> x;
 
	unordered_map<ll, ll> cnt;
	cnt[0] ++;
	ll qs = 0, res = 0;
	for(int i=0; i<n; ++i) {
		qs += v[i];
		res += cnt[qs - t];
		cnt[qs] ++;
	}
 
	cout << res;
	return 0;
}
